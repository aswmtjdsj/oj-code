# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys

a = {}
raw_input()
for line in sys.stdin:
    line = line.strip('\n').split(' ')
    if len(line) > 1:
        a[line[0]] = sum(map(lambda x: float(x), line[1:])) / (1. * len(line[1:]))
    else:
        print '{0:.2f}'.format(a[line[0]])
