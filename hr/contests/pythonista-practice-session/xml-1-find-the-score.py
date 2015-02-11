# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import xml.etree.ElementTree as etree
raw_input()
xml = sys.stdin.read()
# print xml
tree = etree.ElementTree(etree.fromstring(xml))

print sum(map(lambda x: len(x.attrib), tree.iter()))
