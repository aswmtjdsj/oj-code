from random import randint
t = 10
print t
for p in range(t):
    n = randint(1, 2000)
    k = randint(0, 1000000000)
    print n, k
    for i in range(n):
        print randint(0, 1000000000),
    print ' '
