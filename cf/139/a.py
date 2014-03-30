n = int(raw_input())
a = [int(i) for i in raw_input().split()]

mark = -1 
while mark == -1:
	for i in range(len(a)):
		n -= a[i]
		if n <= 0:
			mark = i
			break
print mark + 1
