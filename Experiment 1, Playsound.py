# Instructions: The fNIRs experiment goes as follows:
#     Psychopy start screen:
#         Block 1:
#             20 sec rest
#             20 right
#             20 white
#             20 talk
#             20 right w talk
#             Rest 1 minute
#         Block 2:
#             20 sec rest
#             20 left
#             20 white
#             20 talk
#             20 left w talk
#             Rest 1 minute
#         Repeat Both Block 1 and 2 twice:
#             In total, 3 right blocks, 3 left blocks
#             Block orders will be randomized, but will still alternate right left

#

import time
from playsound3 import playsound
import random
import numpy as np
from numpy.random import randint, shuffle
from pylsl import StreamInfo,StreamOutlet

class runExperiment:
# class is a template for creating objects/minifunctions within the code 
    
    def __init__(self):
        pass
        print("Beginning event marker data collection.")
        self.setup_lsl_stream()

        # each def is like a method the methods describe individual steps within the class  
        # like this is an experiment class so each def describes a stage in the experiment 
    # have to set up a dictonary of the triggers which are the queues in the that we are looking for in aurora 
        self.MARKERS = {
            # positions in the dictionary refer to the groups of the events
            'exp_start': 1, 
            'exp_end': 2,  
            #block 5-10 
            'right_block': 5,
            'left_block': 7, 
            'block_start_r': 6,
            'block_start_l': 8, 
            'block_end': 9,
            #rest start 020, rest end 20 , 060 60 
            '20rest_start': 20,
            '60rest_start': 60,
            # 20+60 = 80  append 0 in front for rest positions 
            'rest_end': 80, 
            # tap coded in at 10-19 
            'tap_right_start':10, 
            'tap_left_start':11,
            'tap_end': 21,
            # audio  is any value between 21- 59 
            'whitenoise_start': 30,
            'talkaudio_start': 40, 
            'audio_end': 070, 
            #tap with talk is  tap+audio greater than 60 
            'tapright_wn': 60, 
            'tapright_ta': 70, 
            'tapleft_wn': 65, 
            'tapright_ta': 75, 
            'tapandtalk_end': 00
        }


#lsl function 

#marker send function 
def send_markers(self,marker_code,)
    
    def intro(self):
        print("Welcome to the experiment!")
        print("You will be asked to perform various tasks involving finger tapping and listening to audio.")
        print("Please follow the instructions carefully.")
        print("Let's begin...")
        time.sleep(3)
    
    def rest60(self):
        print("Taking a long rest")
        time.sleep(60)
    
    def rest20(self):
        print("Taking a short rest")
        time.sleep(20)
    
    def tapRight(self):
        print("Practice the controls of the experiment, please continuously tap your right index finger")
        self.send_marker(self.MARKERS['tap_right_start'], Right Finger Tapping )

        time.sleep(20)
        self.send_marker(self.MARKERS['tap_end'], "Tapping Right Finger End")
        self.rest20()
    
    def tapLeft(self):
        print("Practice the controls of the experiment, please continuously tap your left index finger")
        
        
        
        time.sleep(20)
        self.rest20()
    
    def whiteNoise(self):
        print("Here is one of the audio prompts you will receive: white noise")
        playsound(r'C:\Users\phenz\Desktop\IES Research Cardio Edit\WhiteNoise_20s.wav')
        time.sleep(20)
        self.rest20()
    
    def talkNoise(self):
        print("Here is one of the audio prompts you will receive: chatter")
        playsound(r'C:\Users\phenz\Desktop\IES Research Cardio Edit\people-talking-in-small-room-6064_20s.wav')
        time.sleep(20)
        self.rest20()
    
    def rightTalk(self):
        print("Please listen while continuously tapping your right index finger")
        playsound(r'C:\Users\phenz\Desktop\IES Research Cardio Edit\people-talking-in-small-room-6064_20s.wav')
        time.sleep(20)
        self.rest20()
    
    def leftTalk(self):
        print("Please listen while continuously tapping your left index finger")
        playsound(r'C:\Users\phenz\Desktop\IES Research Cardio Edit\people-talking-in-small-room-6064_20s.wav')
        time.sleep(20)
        self.rest20()


## randomize 
## 3 blocks with the right finger and three blocks with the left 
##
    def leftBlock(self):
        print("--- Starting Left Hand Block ---")
        # Short rest
        self.rest20()
        # Long rest
        self.rest60()
        # Try tapping left finger
        self.tapLeft()
        # Short rest
        self.rest20()
        # Try tapping left finger with white noise
        print("Please listen to white noise while continuously tapping your left index finger")
        playsound(r'C:\Users\phenz\Desktop\IES Research Cardio Edit\WhiteNoise_20s.wav')
        time.sleep(20)
        self.rest20()
        # Try tapping with sound (chatter)
        self.leftTalk()
        # Long rest
        self.rest60()
    
    def rightBlock(self):
        print("--- Starting Right Hand Block ---")
        # Short rest
        self.rest20()
        # Long rest
        self.rest60()
        # Try tapping right finger
        self.tapRight()
        # Short rest
        self.rest20()
        # Try tapping right finger with white noise
        print("Please listen to white noise while continuously tapping your right index finger")
        playsound(r'C:\Users\phenz\Desktop\IES Research Cardio Edit\WhiteNoise_20s.wav')
        time.sleep(20)
        self.rest20()
        # Try tapping with sound (chatter)
        self.rightTalk()
        # Long rest
        self.rest60()
    
    def main(self):
        self.intro()
        n = random.randint(0, 1)
        for i in range(1, 7):
            print(f"\n=== Starting Section {i} ===")
            if n == 0:
                self.rightBlock()
                n = 1
            else:
                self.leftBlock()
                n = 0
        print("\nExperiment completed! Thank you for participating.")

if __name__ == "__main__":
    experiment = runExperiment()
    experiment.main()








