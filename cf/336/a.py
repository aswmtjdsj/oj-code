import sys
from math import fabs

for line in sys.stdin:
	a, b = map( int, line.split(' '))

	obj = fabs(a) + fabs(b)
	obj = int( obj)

	if a > 0 and b > 0:
		print 0, obj, obj, 0
	if a < 0 and b > 0:
		print -obj, 0, 0, obj
	if a < 0 and b < 0:
		print -obj, 0, 0, -obj
	if a > 0 and b < 0:
		print 0, -obj, obj, 0 
