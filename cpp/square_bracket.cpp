#include<iostream>
#include<vector>

using namespace std;

int f(vector<bool>& brackets, vector<bool>::iterator itr, int total){
    if(total<0) return 0;
    else if(total> brackets.size()-(itr-brackets.begin())) return 0;
    else if(itr== brackets.end()){
        if(total == 0) return 1;
        else return 0;
    }
    else if(itr== brackets.end()-1){
        itr++;
        return f(brackets,itr,total-1);
    }
    else{
        if(*itr == true || total ==0){
            itr++;
            return f(brackets,itr,total+1);
        }
        else{
            itr++;
            return (f(brackets,itr,total+1) + f(brackets,itr,total-1));
        }
    }

}

int main(){
    int no_of_input;
    cin>>no_of_input;
    for(int j = 0; j < no_of_input; j++){
        int size_of_list, no_pos,pos;
        cin>>size_of_list>>no_pos;

        vector<bool> brackets(2*size_of_list);
        brackets[0]=true;
        for(int i = 0; i < no_pos; i++){
            cin>>pos;
            brackets[pos-1]=true;
            //cout<<brackets[pos-1]<<endl;
        }
        vector<bool>::iterator it = brackets.begin();
        cout<<f(brackets,it,0)<<endl;
    }
}
