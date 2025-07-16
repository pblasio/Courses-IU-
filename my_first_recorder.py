# This imports the LSL library
from pylsl import StreamInlet, resolve_streams
import time

print("Hello! I'm going to look for event markers.")

# Step 1: Find streams
print("Looking for marker streams...")
streams = resolve_streams('Markers')
#only taking in one input value 

if len(streams) == 0:
    print("No streams found. Make sure your other program is running!")
else:
    print(f"Found {len(streams)} stream(s)!")
    for i, stream in enumerate(streams):
        print(f"  Stream {i+1}: {stream.name()}")
