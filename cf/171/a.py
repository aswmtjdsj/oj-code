a, b = raw_input().split()
a = int(a)
b = [i for i in b]
b.reverse()
b = int(''.join(b))
print a + b
