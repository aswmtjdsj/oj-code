import sys
from math import *
for line in sys.stdin:
	l = line.split()
	a = int(l[0])
	x = int(l[1])
	y = int(l[2])
#	print a,x,y
	flag = 1
	if y % a == 0:
		flag = 0
	det = (y - a) 
	d = det / ( 2 * a)
	e = det % (2 * a)
	ans = 1 + (d+1) * 3
#print '\t',d,e
#	print ans
	if y < a:
		if abs(x) >= a / 2.0:
			flag = 0
		ans = 1
	elif e < a:
		if abs(x) >= a / 2.0:
			flag = 0
		else:
			ans -= 2
	else:
		if abs(x) >= a or x == 0:
			flag = 0
		else:
			if x < 0:
				ans -= 1
	print ans if flag == 1 else -1
