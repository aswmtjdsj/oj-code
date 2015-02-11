# Enter your code here. Read input from STDIN. Print output to STDOUT

s = raw_input()
t = raw_input()

import re

print len(re.findall('(?={0})'.format(t), s))
