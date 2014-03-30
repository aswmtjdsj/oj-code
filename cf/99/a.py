from math import *
a = raw_input()
s = float(a)
a = a.split('.')
if a[0][-1] == '9':
	print 'GOTO Vasilisa.'
else:
	a[0] = [i for i in a[0]]
	if int(a[1][0]) > 4:
		a[0][-1] = chr(ord(a[0][-1]) + 1)
	print ''.join(a[0])
