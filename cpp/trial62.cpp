#include<iostream>
#include<cstring>

using namespace std;

int main(){
    int i;
    cin>>i;

    for(int j = 0; j< i; j++){
        string input;
        cin>>input;
        int length = input.size();

        string half;
        half.assign(input,0,(length+1)/2);

        char ans[(length+1)/2];
        bool carry = false;

        string::iterator itr; int i;
        for(itr = half.end()-1 , i = (length-1)/2 ; itr >= half.begin();itr--, i--){

            int this_int = (*itr);
            if(itr==half.end()-1 || carry){
                this_int = this_int+1;
            }

            this_int = ((this_int%48)%10)+48;
            if(this_int == 48)
                carry = true;
            else
                carry = false;
            ans[i] = this_int;
        }
        if(ans[0]!= 48 && length%2 == 0){
            for(int i= 0; i<(length+1)/2;i++)

                cout<<ans[i];
            for(int i = (length - 1)/2 ; i>= 0; i--)
                cout<<ans[i];
            cout<<endl;
        }
        else if(ans[0]!= 48 && length%2 != 0){
            for(int i= 0; i<(length-1)/2;i++)
                cout<<ans[i];
            for(int i = (length - 1)/2 ; i>= 0; i--)
                cout<<ans[i];
            cout<<endl;
        }
        else{
            cout<<1;
            for(int i = 0; i < length-1;i++)
                cout<<0;
            cout<<1;
            cout<<endl;
        }

    }

}
