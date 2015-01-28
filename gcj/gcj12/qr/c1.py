n = int(raw_input())
for cas in range(n):
	A, B = map(int, raw_input().split())
	S = set()
	for i in range(A, B + 1):
		a = str(i)
		for j in range(len(a)):
			b = a[j:] + a[:j]
			b.lstrip('0')
			c,b = map(int,(a,b))
			p = (min(c, b), max(c, b)) 
			if b in range(A, B + 1) and c != b and len(str(c)) == len(str(b)) and p not in S:
#print p[0], p[1]
				S.add(p)
	print "Case #{0}: {1}".format(cas+1, len(S))
