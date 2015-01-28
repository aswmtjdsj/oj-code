strr = """
a y
c e
b h
e o
d s
g v
f c
i d
h x
k i
j u
m l
l g
o k
n b
p r
s n
r t
u j
t w
w f
v p
y a
x m
z q
"""
what = strr.split('\n')
come = {}
for i in what:
	if len(i) > 1:
		temp = i.split(' ')
#print temp[0], temp[1]
		come[temp[0]] = temp[1]
come['q'] = 'z'
come[' '] = ' '
#print len(come)
#for i in range(26):
#	print chr(i + ord('a')), come[chr(i+ord('a'))]

n = int(raw_input())
for j in range(n):
	what= raw_input()
	line = [come[i] for i in what]
	line = ''.join(line)
	print "Case #{0}: {1}".format(j+1, line)
