from _collections import deque
b = range(0,6,2);
print(b);

a = ["its me", "not me", "ghanta"];
a = a + ["kuch bhi"];

print(a);

def f(a, L=[]):
	L.append(a);
	return L;

print(f(1));
print(f(2));
print(f(3));
print(f(4));

def g(a, L = None):
	if(L is None):
		L = [];
	L.append(a);
	return(L);

print(g(1));
print(g(2));
print(g(3));
print(g(4));


def parrot(voltage, state='a stiff', action='voom', type='Norwegian Blue'): 
	print("-- This parrot wouldn't", action);
	print("if you put", voltage, "volts through it.");
	print("-- Lovely plumage, the", type);
	print("-- It's", state, "!");
parrot(1000) # 1 positional argument
parrot(voltage=1000) # 1 keyword argument
parrot(voltage=1000000, action='VOOOOOM') # 2 keyword arguments
parrot(action='VOOOOOM', voltage=1000000) # 2 keyword arguments
parrot('a million', 'bereft of life', 'jump') # 3 positional arguments
parrot('a thousand', state='pushing up the daisies') # 1 positional, 1 keyword
print("#"*10);

l = [0,"sakljf",2764,"asiojg"];
l.insert(6, "chutiya")
print(l);
print("#" * 40);

print("*******************using deque*****************");
queue = deque(["chutiya", "hai", "to", "kya"]);
queue.append(["1","2"]);
print(queue);
queue.popleft();
print(queue);

print("#" * 40);

print("********************list comprehension*********************** ");

square = [x**2 for x in range(10)];
print(square)

#------------------------------------------------------------ def cubeReturn(x):
	#----------------------------------------------------------------- p = x**3;
	#----------------------------------------------------------------- return p;

cube = list(map(lambda x: x**3, range(2,10,3)));
	   #list(map(lambda x: x**2, range(10)))
print(cube)

array1 = [(x,y) for x in range(-12,10,2) for y in range(-4,12,3) if(x*y > 18)]
print("result of: [(x,y) for x in range(-12,10,2) for y in range(-4,12,3) if(x*y > 18)]:")
print(array1);

c = []
c = [c.append(x)for x in range(5)];
print(c)

c = [];
for x in range(5):
	c.append(c.append(x));
print(c);

print("to take transpose of [[1,2,3],[4,5,6],[7,8,9],[10,11,12]] :");
e = [[1,2,3],
	[4,5,6],
	[7,8,9],
	[10,11,12]
	];
	
result = []
for x in(range(len(e[0]))):
	temp = [];
	for y in (range(len(e))):
		temp.append(e[y][x]);
	result.append(temp);
print(result)

result2 = [ [row[i] for row in e ] for i in range(len(e[0])) ]
print(result2)


