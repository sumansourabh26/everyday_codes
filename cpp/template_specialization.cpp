#include<iostream>
using namespace std;

template <class T>

class Spunky{
public:
    Spunky(T x){
        cout<<x<<" is not a character\n";
    }
};

template<>
class Spunky<char>{
public:
    Spunky(char x){
        cout<<x<<" is char\n";
    }
};

int main(){
    Spunky <int> x(5);
    Spunky <char> r('q');
}
