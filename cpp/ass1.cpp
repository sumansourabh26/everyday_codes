#include<iostream>
#include<vector>
#include<math.h>

struct int_num{
    unsigned long long value;
    int factor[20];
    unsigned long long nperms;
    int sum;
};

int prime[20] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int index[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

bool check(int_num instance, int power);
bool already_in(unsigned long long check_val);

using namespace std;





vector<int_num> s;
int main(){

    int_num t;
    t.value = 1;
    for(int i = 0 ;i<20;i++){
        t.factor[i]=0;
    }
    t.factor[0]=1;
    t.nperms=1;
    t.sum = 1;


    s.push_back(t);

    cout<<s[0].value<<endl;

    for(unsigned long long i=0; i<= s.size() && i < 100 ; i++){

        for(int j = 0; j<20; j++){
            if( check(s[i], j )){
                if( !(already_in( (s[i].value)*prime[j]))){


                   int_num temp;
                   temp.value = (s[i].value)*(prime[j]);
                   temp.nperms = (s[i].nperms)*(s[i].sum)/prime[j];
                   temp.sum= s[i].sum + 1;
                    for(int counter = 0 ; counter < 20; counter++){
                        temp.factor[counter] = s[i].factor[counter];
                    }
                    temp.factor[j] = temp.factor[j] +1;
                   s.push_back(temp);

                   cout<<s[1].value<<endl;

                }
            }

            else{
                break;
            }


        }
    }
    for(int i = 0 ; i < s.size();i++){
        cout<<s[i].value;
    }



}
bool already_in(unsigned long long check_val){
    for(unsigned long long i = 0 ; i < s.size(); i++){
        if(s[i].value == check_val)
            return true;
    }
    return false;
}
bool check(int_num instance, int power){
    if(instance.factor[power-1]<=instance.factor[power])
        return false;
    else return true;
}
