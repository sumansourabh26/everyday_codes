#include<iostream>
#include<queue>

using namespace std;

int main(){

    while(true){
        int no_of_elements;
        cin>>no_of_elements;
        if(no_of_elements==0)
            break;

        queue<int> q;
        int sum = 0;
        for(int i = 0; i < no_of_elements; i++){
            int val; cin>>val;
            if(i%2==0){
                q.push(val);
                sum = sum+val;
            }
            else{
                sum = sum+val-q.front();
                q.push(val);
                q.pop();
            }
        }
        cout<<sum<<endl;
    }

}
