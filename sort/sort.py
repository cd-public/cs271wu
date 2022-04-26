# sort.py

list = [int(line) for line in open("onem.txt","r")]
	
list.sort()

f = open("inpy.txt","w")

[f.write(str(i) + "\n") for i in list]
