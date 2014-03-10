#include<iostream>
#include<vector>
using namespace std;

int main(){
    int no;
    cin>>no;
    while(no--){
        int lengthby2, k;
        cin>>lengthby2;
        //cout<<"lengthby2 ass\n";
        cin>>k;
        //cout<<"k ass\n";

        vector< vector<int> > solution(lengthby2+1, vector<int>(lengthby2+1,0));
        vector<bool> openbr(lengthby2*2+1, false);

        for(int i = 0; i <k ; i++){
            int temp;
            cin>>temp;
            openbr[temp] = true;
            //cout<<"openbr assigned\n";
        }
        solution[0][0] = 1;
        for(int column = 0; column < lengthby2+1; column++){
            solution[0][column] = 1;
        }
        for(int row = 1; row < lengthby2+1; row++){
            for(int column = row; column < lengthby2+1; column++ ){
                if(openbr[row+column]){
                    solution[row][column]=solution[row][column-1];
                    //cout<<"solution "<<row<<' '<<column<<'='<<solution[row][column]<<endl;
                }
                else{
                    solution[row][column] = solution[row-1][column]+solution[row][column-1];
                    //cout<<"solution "<<row<<' '<<column<<'='<<solution[row][column]<<endl;
                }

            }
        }
        cout<<solution[lengthby2][lengthby2]<<endl;

    }
}
