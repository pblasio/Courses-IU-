import time
from playsound3 import playsound
import random
import numpy as np
from numpy.random import randint, shuffle
from pylsl import StreamInfo, StreamOutlet

#FAST FORWARD OPTION FOR LAB TESTS 
#notes 
#fallback trigger number 
#Template marker changed 


class runExperiment:
    """
    fNIRS experiment class for finger tapping with audio stimuli.
    Implements proper LSL marker streaming and experiment structure.
    """
    
    def __init__(self):
        print("Beginning event marker data collection.")
        self.setup_lsl_stream()
        
        # Dictionary of LSL markers for different events
        
         
        self.MARKERS = {
            # Experiment control
            'exp_start': 1, 
            'exp_end': 21,  

            
            # Block markers (5-10)
            'right_block': 2,
            #the begining of orange 
            'left_block': 4, 
            # the beginning of yellow 
            'block_start_r': 6,

            'block_start_l': 8, 
            # a block end is 20 because it is a ending of a 
            # signal but not the entire code 
            'block_end': 20,
            
            # Rest markers
            # 15 and 16 are rest markers because they are dark blue 
            '20rest_start': 15,
            '60rest_start': 16,
            # 17 can be rest end and thats purple 
            'rest_end': 17, 
            
            # Tapping markers (10-19)
            'tap_right_start': 3, 
            #the orange value 
            'tap_left_start': 5,
            # yellow with a dark yellow deoxy 
            'tap_end': 7,
            # the beginning of green the first one 


            # Audio markers (30-59)

            'whitenoise_start':8,
#the green for white noise start 
            'talkaudio_start': 9,

            'audio_end':
            
            # Combined tapping + audio markers (60+)
            'tapright_wn': 
            'tapright_ta':  
            'tapleft_wn':
            'tapleft_ta':
            'tapandtalk_end': 
        }
        

    def setup_lsl_stream(self):
        """Initialize LSL stream for sending markers."""
        try:
        # error handling functions 
            info = StreamInfo('MyMarkerStream', 'Markers', 1, 0, 'int32', 'myuidw43536')
            self.outlet = StreamOutlet(info)
            print("LSL marker stream established successfully.")
        except Exception as e:
            print(f"Error setting up LSL stream: {e}")
            self.outlet = None

    def send_marker(self, marker_code, description=""):
        """Send marker through LSL stream."""
        if self.outlet:
            try:
                self.outlet.push_sample([marker_code])
                print(f"Marker sent: {marker_code} - {description}")
            except Exception as e:
                print(f"Error sending marker {marker_code}: {e}")
        else:
            print(f"No LSL outlet - would send marker: {marker_code} - {description}")

    def intro(self):
        """Introduction to the experiment."""
        print("Welcome to the fNIRS finger-tapping experiment!")
        print("You will be asked to perform various tasks involving finger tapping and listening to audio.")
        print("Please follow the instructions carefully and remain still except for the finger movements.")
        print("Let's begin...")
        self.send_marker(self.MARKERS['exp_start'], "Experiment Start")
        time.sleep(3)
    
    def rest60(self):
        """60-second rest period."""
        print("Taking a long rest (60 seconds)...")
        self.send_marker(self.MARKERS['60rest_start'], "60 Second Rest Start")
        time.sleep(60)
        self.send_marker(self.MARKERS['rest_end'], "Rest End")
    
    def rest20(self):
        """20-second rest period."""
        print("Taking a short rest (20 seconds)...")
        self.send_marker(self.MARKERS['20rest_start'], "20 Second Rest Start")
        time.sleep(20)
        self.send_marker(self.MARKERS['rest_end'], "Rest End")
    
    def tapRight(self):
        """Right finger tapping task."""
        print("Please continuously tap your right index finger for 20 seconds")
        self.send_marker(self.MARKERS['tap_right_start'], "Right Finger Tapping Start")
        time.sleep(20)
        self.send_marker(self.MARKERS['tap_end'], "Right Finger Tapping End")
        print("Stop tapping")
    
    def tapLeft(self):
        """Left finger tapping task."""
        print("Please continuously tap your left index finger for 20 seconds")
        self.send_marker(self.MARKERS['tap_left_start'], "Left Finger Tapping Start")
        time.sleep(20)
        self.send_marker(self.MARKERS['tap_end'], "Left Finger Tapping End")
        print("Stop tapping")
    
    def whiteNoise(self):
        """White noise audio stimulus."""
        print("Listen to white noise for 20 seconds")
        self.send_marker(self.MARKERS['whitenoise_start'], "White Noise Start")
        try:
            playsound(r'C:\Users\phenz\Desktop\IES Research Cardio Edit\WhiteNoise_20s.wav')
        except Exception as e:
            print(f"Error playing white noise: {e}")
            time.sleep(20)  # Still wait 20 seconds even if audio fails
        self.send_marker(self.MARKERS['audio_end'], "White Noise End")
    
    def talkNoise(self):
        """Talk/chatter audio stimulus."""
        print("Listen to people talking for 20 seconds")
        self.send_marker(self.MARKERS['talkaudio_start'], "Talk Audio Start")
        try:
            playsound(r'C:\Users\phenz\Desktop\IES Research Cardio Edit\people-talking-in-small-room-6064_20s.wav')
        except Exception as e:
            print(f"Error playing talk audio: {e}")
            time.sleep(20)  # Still wait 20 seconds even if audio fails
        self.send_marker(self.MARKERS['audio_end'], "Talk Audio End")
    
    def rightTalkCombo(self):
        """Right finger tapping while listening to talk audio."""
        print("Please tap your right index finger while listening to people talking")
        self.send_marker(self.MARKERS['tapright_ta'], "Right Tap + Talk Start")
        try:
            playsound(r'C:\Users\phenz\Desktop\IES Research Cardio Edit\people-talking-in-small-room-6064_20s.wav')
        except Exception as e:
            print(f"Error playing talk audio: {e}")
            time.sleep(20)
        self.send_marker(self.MARKERS['tapandtalk_end'], "Right Tap + Talk End")
        print("Stop tapping")
    
    def leftTalkCombo(self):
        """Left finger tapping while listening to talk audio."""
        print("Please tap your left index finger while listening to people talking")
        self.send_marker(self.MARKERS['tapleft_ta'], "Left Tap + Talk Start")
        try:
            playsound(r'C:\Users\phenz\Desktop\IES Research Cardio Edit\people-talking-in-small-room-6064_20s.wav')
        except Exception as e:
            print(f"Error playing talk audio: {e}")
            time.sleep(20)
        self.send_marker(self.MARKERS['tapandtalk_end'], "Left Tap + Talk End")
        print("Stop tapping")

    def rightWhiteCombo(self):
        """Right finger tapping while listening to white noise."""
        print("Please tap your right index finger while listening to white noise")
        self.send_marker(self.MARKERS['tapright_wn'], "Right Tap + White Noise Start")
        try:
            playsound(r'C:\Users\phenz\Desktop\IES Research Cardio Edit\WhiteNoise_20s.wav')
        except Exception as e:
            print(f"Error playing white noise: {e}")
            time.sleep(20)
        self.send_marker(self.MARKERS['tapandtalk_end'], "Right Tap + White Noise End")
        print("Stop tapping")

    def leftWhiteCombo(self):
        """Left finger tapping while listening to white noise."""
        print("Please tap your left index finger while listening to white noise")
        self.send_marker(self.MARKERS['tapleft_wn'], "Left Tap + White Noise Start")
        try:
            playsound(r'C:\Users\phenz\Desktop\IES Research Cardio Edit\WhiteNoise_20s.wav')
        except Exception as e:
            print(f"Error playing white noise: {e}")
            time.sleep(20)
        self.send_marker(self.MARKERS['tapandtalk_end'], "Left Tap + White Noise End")
        print("Stop tapping")

    def leftBlock(self):
        """Complete left hand block following the protocol."""
        print("\n=== Starting Left Hand Block ===")
        self.send_marker(self.MARKERS['left_block'], "Left Block Start")
        self.send_marker(self.MARKERS['block_start_l'], "Left Block Begin")
        
        # 20 sec rest
        self.rest20()
        
        # 20 left tapping
        self.tapLeft()
        
        # 20 white noise
        self.whiteNoise()
        
        # 20 talk audio
        self.talkNoise()
        
        # 20 left tapping with talk
        self.leftTalkCombo()
        
        # 1 minute rest
        self.rest60()
        
        self.send_marker(self.MARKERS['block_end'], "Left Block End")
        print("=== Left Hand Block Complete ===")
    
    def rightBlock(self):
        """Complete right hand block following the protocol."""
        print("\n=== Starting Right Hand Block ===")
        self.send_marker(self.MARKERS['right_block'], "Right Block Start")
        self.send_marker(self.MARKERS['block_start_r'], "Right Block Begin")
        
        # 20 sec rest
        self.rest20()
        
        # 20 right tapping
        self.tapRight()
        
        # 20 white noise
        self.whiteNoise()
        
        # 20 talk audio
        self.talkNoise()
        
        # 20 right tapping with talk
        self.rightTalkCombo()
        
        # 1 minute rest
        self.rest60()
        
        self.send_marker(self.MARKERS['block_end'], "Right Block End")
        print("=== Right Hand Block Complete ===")
    
    def main(self):
        """Main experiment execution following the protocol."""
        self.intro()
        
        # Create randomized block order (3 right, 3 left, alternating)
        blocks = []
        start_with_right = random.choice([True, False])
        
        for i in range(3):
            if start_with_right:
                blocks.extend(['right', 'left'])
            else:
                blocks.extend(['left', 'right'])
        
        print(f"Block order: {blocks}")
        
        # Execute blocks
        for i, block_type in enumerate(blocks, 1):
            print(f"\n### Block {i} of 6 ###")
            if block_type == 'right':
                self.rightBlock()
            else:
                self.leftBlock()
        
        # End experiment
        self.send_marker(self.MARKERS['exp_end'], "Experiment End")
        print("\n Experiment completed! Thank you for participating.")

if __name__ == "__main__":
    experiment = runExperiment()
    try:
        experiment.main()
    except KeyboardInterrupt:
        print("\nExperiment interrupted by user.")
        experiment.send_marker(experiment.MARKERS['exp_end'], "Experiment Interrupted")
    except Exception as e:
        print(f"Experiment error: {e}")
        experiment.send_marker(experiment.MARKERS['exp_end'], "Experiment Error")