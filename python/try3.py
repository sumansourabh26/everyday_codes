

print("Enter the name of the file for which you want the details of script (eg - despicable.txt)");

while True:
	try:
		inputfile = input("Enter the name of the file for which you want the details of script (eg - despicable.txt)\n");
		moviefile = open(inputfile,'r');
		break
	except FileNotFoundError :
		print ("This file is not present in the directory. Please try again")

a = ["Mr.","Mrs."]

count = [0,0,0,0,0] #action, comedy, crime, mystery, horror

genre = []
genre.append([" war","fight","struggle","attack","kill","conflict","rival","clash","quarrel","riot","dispute","operation","battle","hunt","revenge","violence","conflict","breach","hunt","run","dispute" ,"fear" ,"gun", "weapon"])

genre.append(["laugh","fun","comic","chuckle","giggle","gag","pun","mock","spoof","cheer","nonsense","smile","smirk","prank","amusing","entertain","pleasant","merry","cheer","enjoy","gossip","joke","fool","tease","amuse","hoopla","pleasure","charm","celebrate","party","happy","kidding","ass","fuck","mimic","witty"])

genre.append(["murder","drugs","prison","shot","dead",'gang','scandal','corruption','felony','breach','outrage','legal','conduct','prison','police','court','justice','weapon','gun','law'])

genre.append(["spy","detective","undercover","dispute","confusion","bluff","riddle","loot","risk","oracle","hunt","search","operation","secret","agent","informer","investigator","rival","invade","trait shot","murder","tension","shock","fear"])

genre.append(["terror","panic","hatred","fear","dead","evil","curse","strain","stress","tension","scare","distress","wick","brutality","shock","wonder","creepy","insane","phobia","ugly","crime","psycho","shock","grief","dark","revenge","pain","illwill","venom","enmity","hate","prejudice","monster","freak","beast","brute","savage","demon","torment","run","torture"])


for line in moviefile:
	splited = line.split();
	for i in range(len(splited)):
		splited[i] = splited[i].lower()
	for i in range(5):
		for to_find in genre[i]:
			for word in splited:
				if(to_find in word):
					print(to_find,',');	
					count[i] = count[i]+1;
print(count[:])
