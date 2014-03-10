
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int add(string s1, string s2);
int subtract(string s1, string s2);
int converter(string s);

int main(){
    int no_of_input;
    cin>>no_of_input;

    while(no_of_input--){
        string f, s, t;
        char a, b;
        int int1, int2;
        cin>>f>>a>>s>>b>>t;
        if(f.find('m')<=f.size()){
            int1 = converter(t);
            int2 = converter(s);
            cout<<int1-int2<<" + "<<int2<<" = "<<int1<<endl;
        }
        else if(s.find('m')<=s.size()){
            int1 = converter(t);
            int2 = converter(f);
            cout<<int2<<" + "<<int1-int2<<" = "<<int1<<endl;
        }
        else if(t.find('m')<=t.size()){
            int1 = converter(s);
            int2 = converter(f);
            cout<<int2<<" + "<<int1<<" = "<<converter(s)+converter(f)<<endl;
        }
    }
}

int converter(string s){
    bool neg = false;
    string::iterator itr = s.begin();
    if(*itr == '-') {neg = true;itr++;}
    int x = 0;
    for(;itr!= s.end(); itr++){
        x = x*10+(*itr)-48;
    }
    if(neg) return -1*x;
    else return x;
}




