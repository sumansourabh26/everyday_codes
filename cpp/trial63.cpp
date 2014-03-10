#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    string input;
    cin>>input;
    int length = input.size();

    string half;
    half.assign(input,0,(length+1)/2);
    cout<<half<<endl;

    char ans[(length+1)/2];
    bool carry = false;

    string::iterator itr; int i;
    for(itr = half.end()-1 , i = (length-1)/2 ; itr >= half.begin();itr--, i--){

        int this_int = (*itr);
        cout<<this_int<<" ";
        if(itr==half.end()-1 || carry){
            this_int = this_int+1;
        }

        this_int = ((this_int%48)%10)+48;
        if(this_int == 48)
            carry = true;
        else
            carry = false;
        ans[i] = this_int;
        cout<<this_int<<' '<<ans[i]<<endl;
    }
    cout<<"length= "<<length<<endl;
    if(ans[0]!= 48 && length%2 == 0){
            cout<<"even\n";
        for(int i= 0; i<(length+1)/2;i++)

            cout<<ans[i];
        for(int i = (length - 1)/2 ; i>= 0; i--)
            cout<<ans[i];
    }
    else if(ans[0]!= 48 && length%2 != 0){
        cout<<ans[0]<<endl;
        cout<<" not even\n";
        for(int i= 0; i<(length-1)/2;i++)
            cout<<ans[i];
        for(int i = (length - 1)/2 ; i>= 0; i--)
            cout<<ans[i];
    }
    else{
        cout<<1;
        for(int i = 0; i < length-1;i++)
            cout<<0;
        cout<<1;
    }

}
