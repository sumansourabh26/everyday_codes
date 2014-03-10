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

        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());

        int min_diff = 1000000;
        for(int i = 0; i < s1; i++){
            int last_diff = 1000000;
            for(int j = 0; j< s2; j++ ){
                int diff = abs(vec1[i]-vec2[2]);
                if(diff < min_diff){
                    last_diff = diff;
                    min_diff = diff;
                    //cout<<vec1[i]<<' '<<vec2[j]<<' '<<temp_min<<endl;
                }
                if(diff > last_diff)
                    break;
                else{
                    last_diff = diff;
                }
            }
        }
        cout<<min_diff<<endl;
    }

}
