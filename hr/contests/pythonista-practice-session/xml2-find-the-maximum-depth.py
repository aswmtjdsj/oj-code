# Enter your code here. Read input from STDIN. Print output to STDOUT

# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import xml.etree.ElementTree as etree
raw_input()
xml = sys.stdin.read()
# print xml
tree = etree.ElementTree(etree.fromstring(xml))

def dfs(depth, node):
    ans = depth
    for i in node.getchildren():
        ans = max(ans, dfs(depth+1, i))
    return ans

print dfs(0, tree.getroot())
