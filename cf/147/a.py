import sys
li = [',','.','?','!',':']
l = set(li)
for line in sys.stdin:
	s = line.split()
	t = ''
	for i in s:
		t += i
		if i[len(i)-1:] not in l:
			t += '$'
	for i in li:
		t = t.replace(i,i+'$')
	for i in li:
		t = t.replace('$'+i,i)
	t = t.replace('$',' ')
	t = t.strip(' ')
	print t
