#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;



int main(){
    int no_of_input, temp;
    cin>>no_of_input;

    for(int m = 0; m < no_of_input; m++){
        int s1, s2;
        cin>> s1;
        vector<int> vec1;
        for(int i = 0; i < s1; i++){
            cin>>temp;
            vec1.push_back(temp);
        }
        cin>> s2;
        vector<int> vec2;
        for(int i = 0; i < s2; i++){
            cin>>temp;
            vec2.push_back(temp);
        }

        int min_d = 10000001;
        for(int i = 0; i < s1; i++){
            for(int j = 0; j < s2; j++){
                if(abs(vec1[i]-vec2[j]) < min_d )
                    min_d = abs(vec1[i]-vec2[j]);
            }
        }

        cout<<min_d<<endl;

    }
}
