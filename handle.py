from os import system
from os import listdir, mkdir
from os.path import isfile, join
import re
import sys

mypath = './'

onlyfiles = [ f for f in listdir(mypath) if isfile(join(mypath,f)) ]

if len(sys.argv) < 2:
    raise Exception('arg not enough')

category = sys.argv[1]
print category

for i in onlyfiles:
    print i, 
    m = re.search('([0-9])+', i)
    if m != None:
        n = m.group(0)
        print n,
        r = i.partition(n)[2]
        print r
        obj = './{0}/{1}'.format(category, n)
        cmd_obj = 'mkdir ' + obj
        print '>>> ' + cmd_obj
        try:
            mkdir(obj)
        except:
            pass
        cmd_mv = 'mv {0} {1}/{2}'.format(i, obj, r)
        print '>>> ' + cmd_mv
        system(cmd_mv)
    else:
        print 
