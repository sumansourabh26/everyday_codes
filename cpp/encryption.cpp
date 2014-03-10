#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main(){
    string input;
    cin>>input;

    int length = input.size();
    int row = ceil(sqrt(length));
    int n = floor(sqrt(length));

    //cout<<"row :"<<row<<endl<<"col :"<<n<<endl;

    string::iterator itr;

    for(int j = 0; j< row; j++){
        itr = input.begin()+j;
        for(; itr<input.end(); ){
            cout<< *itr;
            itr=itr+row;
        }
        cout<<' ';
    }
}

