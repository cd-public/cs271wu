# make.py

# makes two files, onem.txt and slvd.txt, containing a million integers both unsorted and sorted

import random # good enough

MAX = 2 ** 32 - 1

MIL = 10 ** 6

nums = [random.randint(1,MAX) for _ in range(MIL)]
srtd = sorted(nums)

with open("onem.txt","w") as f:
	[f.write(str(num) + "\n") for num in nums]
	
with open("slvd.txt","w") as f:
	[f.write(str(num) + "\n") for num in srtd]
	
