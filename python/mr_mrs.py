

print("Enter the name of the file for which you want the details of script (eg - despicable.txt)");

while True:
	try:
		inputfile = input("Enter the name of the file for which you want the details of script (eg - despicable.txt)\n");
		moviefile = open(inputfile,'r');
		break
	except FileNotFoundError :
		print ("This file is not present in the directory. Please try again")

a = ["Mr.","Mrs."]

next_line_toPrint = False;




for title in range(len(a)):
	for line in moviefile:
		splited = line.split()
		if(next_line_toPrint):
			if(title):
				print(splited[0], "female");
			else:
				print(splited[0], "male");
			next_line_toPrint = False;
		indices = [i for i,val in enumerate(splited) if val==a[title]]
		for index in indices:
			try:
				if(title):
					print(splited[index+1], "female");
				else:
					print(splited[index+1], "male");
			except IndexError:
				next_line_toPrint = True;
