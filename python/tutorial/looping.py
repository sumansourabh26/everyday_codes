from IPython.testing.tools import pair_fail_msg
character = {"ritu":"seedhi saadi", "shreya":"forward", "pragya":"giveUp and arrogant"};
for name, char in character.items():
	print(name + " is "+ char);

for char in character.itervalues():
	print(char)
	
	
for name in character.iterkeys():
	print(name)
	
num = ["0","1","2","3"]
alpha = ["zero", "one","two", "three"]

pair = (zip(num,alpha))
for q,a in pair: #pair is list of tuples thats why q,a assigns q  first and a second value 
	print(q + " is represented as "+ a)

