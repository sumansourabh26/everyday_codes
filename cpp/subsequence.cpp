#include<iostream>
#include<string>

using namespace std;
bool check(string main, string sub);
int main(){
    string main, sub;

    cout<< "enter the main string\n";
    cin>>main;
    cout<< "enter the subsequence to be checked\n";
    cin>> sub;
    cout << check(main, sub);

}

bool check(string main, string sub){
    if(main.size()<sub.size())
        return false;

    else if(main.size() == 0) {
        if (sub.size() == 0)
            return true;
        else if (sub.size() != 0)
            return false;
    }

    if(main.size() != 0){
        if(sub.size() == 0){
            return true;
        }
        else if((*main.begin()) !=  (*sub.begin()) ){
            main.erase(main.begin());
            return check(main, sub);
        }
        else{
            sub.erase(sub.begin());
            main.erase(main.begin());
            return check(main, sub);
        }

    }



}
