# Enter your code here. Read input from STDIN. Print output to STDOUT

m = int(raw_input())
a = set(map(int, raw_input().split(' ')))
n = int(raw_input())
b = set(map(int, raw_input().split(' ')))

for i in sorted(list(a ^ b)):
    print i
