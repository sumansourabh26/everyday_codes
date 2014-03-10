#include<iostream>
#include<string>
using namespace std;

int main(){

    while(true){
        string str;
        cin>>str;
        if(str=="0")break;
        int length = str.size();
        str.push_back('0');

        int counter[length+1];
        counter[length] = 1;
        counter[length+1] = 1;
        bool last_zero = false;
        int i;
        for(i = length-1; i>=0 ; ){
            if(str[i]=='0'){
                counter[i]=counter[i+1];
                i--;
                if(str[i]=='1' || str[i]=='2'){
                    counter[i]=counter[i+1];
                    i--;
                    last_zero = true;
                }
                else{
                    cout<<"0\n";
                    break;
                }
            }
            else if(i == length-1){
                counter[i]=1;i--;
            }

            else{
                if((str[i]-48)*10+str[i+1]-48 < 27 && !last_zero){
                    counter[i]= counter[i+1]+ counter[i+2];
                    i--;
                }
                else{
                    counter[i]= counter[i+1];
                    i--;
                    if(last_zero) last_zero = false;
                }

            }
        }if(i==-1)cout<<counter[0]<<endl;
    }
}
