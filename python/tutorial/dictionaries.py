
telephone = {"mummy":8109351416, "suman": 9967440124 };

#print(telephone["randomGuy"]) KeyError: 'randomGuy'

print(telephone.has_key("mummy"))
print(telephone.has_key("randomGuy"))

print(list(telephone.keys()))

print("mummy" in telephone);
print("randomGuy" not in telephone);

suman = "salkfn"
temp = dict([(suman, 67576), ("b", 76786869)])
print(temp)

#### maping x with x**3 + 1

a = { x : x**3 + 1 for x in range(10)}
print(a)


#simpler way;
b = dict(suman = 46375, chutiya = 483748, ritu = 82472) #note that here the suman is not replaced by the salkfn 
print(b)
