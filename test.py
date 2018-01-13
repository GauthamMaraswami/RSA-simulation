import random
from struct import pack, unpack
message="android"
length = len(message)
acc=0
if length % 4:
    extra = (4 - length % 4)
    message = bytes('\000') * extra + bytes(message)

for i in range(0, length, 4):
    acc = (acc << 32) + unpack('>I', message[i:i+4])[0]

print acc
