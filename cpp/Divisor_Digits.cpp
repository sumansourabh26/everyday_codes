#include<iostream>
#include<string>
#include<algorithm>

using namespace std;



int main(){
    while(true){
        string input;
        cin>>input;

        int out = 0, siz = input.size(), sum_digit = 0;


        int last = input.back()-48;
        int sec_last = input[siz-2]-48;

        int c1 = count(input.begin(),input.end(),'1');
        out = out + c1;

        int c2 = count(input.begin(),input.end(),'2');
        if(last==0 || last==2 || last==4 || last==6 ||last==8)
            out = out + c2;

        int c3 = count(input.begin(),input.end(),'3');
        if(c3!=0){
            for(int i = 0; i < siz; i++){
                int temp = input[i];
                sum_digit = sum_digit+temp-48;
            }
            cout<<"sum:"<<sum_digit<<endl;
            if(sum_digit%3==0){
                out = out + c3;
            }
        }

        int c4 = count(input.begin(),input.end(),'4');
        if((sec_last*10 + last)%4 ==0){
            out = out + c4;
        }

        int c5 = count(input.begin(),input.end(),'5');
        if(last %5 ==0){
            out = out + c5;
        }


        cout<<out<<endl;
    }

}
