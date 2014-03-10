#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int length;cin>>length;
    vector<int> input(length);

    for(int i = 0; i<length; i++){
        cin>>input[i];
    }

    vector<vector<int> > table={{input[0]}};

    vector<int> ans_table={1};

    int ans_with =1 , ans_without=0;

    for(int i = 1; i<length;i++){
        ans_without=max(ans_with,ans_without);
        ans_with = 0;

        for(int j = 0; j<i;j++){

            int counter = 0;
            for(int p = 0; p< i-j;p++){
                if(counter >2)
                    break;
                else if(input[j+p]==input[i]){
                    counter = counter+1;
                }
            }
            if(counter == 0){
                ans_table[j]=ans_table[j]+1;
            }
            else if(counter==1){
                ans_table[j]=ans_table[j]-1;
            }
            table[j].push_back(input[i]);
            if(ans_table[j]>ans_with)
                ans_with=ans_table[j];
        }
        table.push_back(vector<int> {input[i]});
        ans_table.push_back(1);

    }

    cout<< max(ans_with,ans_without);
}
