from pylsl import StreamInfo, StreamOutlet
#stream info describes the data we want to bring in, it is a function from psychopy
#stream outlet describes the data we are sending 
import time 
# we need to import the entire time library 


info = StreamInfo(
	name = 'TriggerStream',
    type = 'Markers', 
    channel_count = 1,
    nominal_srate= 0, 
    channel_format = 'int32', 
    source_id = "MyFirstSender"
)
# here we are creating a variable called info to store a function with specific parameters 


# now to create the streaming information 