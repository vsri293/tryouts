t = raw_input("")

while t--:
	line = raw_input("")
	act = line.split(" ")[0]
	nat = line.split(" ")[1]
	d = dict()
	laddus = 0
	for ind in range(int(act)):
		line = raw_input("")
		arr = line.split(" ")
		if len(arr) > 0:
			str1 = arr[0]
			str2 = arr[1]
			if str1 == "CONTEST_WON":
				if int(str2) <= 20:
					laddus += 300 + 20 - int(str2)
				else:
					laddus +=300
			else if str1 == "BUG_FOUND":
				if int(str2) >= 50:
					laddus += int(str2)
		else:
			str1 = arr[0]
			if str1 == "TOP_CONTRIBUTOR":
				laddus += 300
			else if str1 == "CONTEST_HOSTED":
				laddus += 50

	if nat == "INDIAN":
		mnth = laddus/200
		print int(mnth)
	else:
		mnth = laddus/400
		print int(mnth)
