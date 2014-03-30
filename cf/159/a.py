from random import *
# gen string
num = randint(1,100)
list = []
for i in range(num):
	l = randint(1,20)
	temp = []
	for j in range(l):
		one = randint(0,25)
		temp.append(chr(one+ord('a')))
	list.append(''.join(temp))
n = randint(1, 1000)
d = randint(1, 1000)
print n, d
t = 0
det = 0
for i in range(n):
	a = randint(0,len(list)-1)
	b = randint(0,len(list)-1)
	while a == b:
		b = randint(0,len(list)-1)
	det = randint(0,10)
	t += det
	print list[a], list[b], t
