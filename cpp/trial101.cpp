#include <iostream>
int main()
{ char ch;
string str;
getline(cin, str);
cout << " The contents of string str after getline : \n" << str << endl;
cout << " The characters in input stream after getline(), one per line " << endl;
while (cin.get(ch))
{cout << ch << " " << (short) ch << endl;}
cout << endl;
}
