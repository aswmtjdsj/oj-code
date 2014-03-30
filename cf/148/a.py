import sys
k = int(raw_input())
l = int(raw_input())
m = int(raw_input())
n = int(raw_input())
d = int(raw_input())
ans = 0
lt = [k,l,m,n]
for i in range(1,d+1):
	for j in lt:
		if i % j == 0:
			ans += 1
			break
print ans
