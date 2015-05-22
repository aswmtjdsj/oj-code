# -*- coding: utf-8 -*-  
import urllib2  
import time
from BeautifulSoup import BeautifulSoup as bs4

h = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.65 Safari/537.36', 'cookie': 'YOUR_COOKIE_HERE', 'referer': 'http://whitehouse.gov'}

req = urllib2.Request('http://www.hacker.org/challenge/chal.php?answer=http%3A%2F%2Fwhitehouse.gov&id=38&go=Submit', headers=h)
r = urllib2.urlopen(req)
p = r.read()
print p
