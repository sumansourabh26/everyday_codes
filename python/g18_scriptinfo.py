

while True:
	try:
		inputfile = input("Enter the name of the file for which you want the details of script (eg - despicable.txt)\n");
		moviefile = open(inputfile,'r');
		break
	except FileNotFoundError :
		print ("This file is not present in the directory. Please try again")


while(1):
	a = moviefile.readline()
	if a != '\n' :
		while(a[0]==" "):
			a = a[1:]	# removing initial spaces present in the line
		print ("The title of the movie is: " + a)
		break

while(1):
        a = moviefile.readline()
        if a != '\n' :
               	break

authorlist = []

while(1):
	a = moviefile.readline()
	if a != '\n' :
		while(a[0]==" "):
			a = a[1:]
		i = 0
		while (1):
			temp = ""
			while a[i] != '&':
				temp = temp + a[i]
				i = i + 1
				if i >= len(a):
					break
            #print(i)
			authorlist.append(temp)
			# print (i)
			if i >= len(a):
				break
			if a[i] == '&':
				i = i + 1
		break
print("The author(s) of this movie script is(are) : ")

for i in range(len(authorlist)) :
	print ("Author " + str(i+1) + " : " + authorlist[i])

