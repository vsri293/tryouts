t = raw_input("")

cnt = 2
l = []
l.append(1)
l.append(2)
num = 2
while num < 1000000005:
	num = l[cnt-1]+l[cnt-2]
	l.append(l[cnt-1]+l[cnt-2])
	cnt+=1

print l