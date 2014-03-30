import sys
n = int(raw_input())
num = raw_input().split(' ')
num = [int(i) for i in num]
bp = 0
sp = len(num)-1
for i in range(len(num)):
	if num[i] > num[bp]:
		bp = i
temp = range(len(num))
temp.reverse()
for i in temp:
	if num[i] < num[sp]:
		sp = i
ans = bp + len(num) - 1 - sp
if bp > sp:
	ans -= 1
print ans
