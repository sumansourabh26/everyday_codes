basket = {"apple", "orange", "apple", "pear", "orange", "banana"};
print(basket)

# print(basket[2]); TypeError: 'set' object does not support indexing

a = "apple" in basket
b = "suman" in basket
print(a,b);

c = set("sumanIsGoodBoy");
print(c)


d = set("rituIsBadGirl");
print(d)
e = {x for x in c if x not in d}
print(e)

