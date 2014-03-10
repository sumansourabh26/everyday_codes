#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    cout<<"enter the order\n";
    int order;
    cin>>order;

    vector<vector<double>> matrix;

    double temp_val;
    for(int i = 0; i < order; i++){
        vector<double> temp;
        //cout<<"size of temp is:"<<temp.size()<<endl;
        for(int j = 0; j < order; j++){
            cin>>temp_val;
            temp.push_back(temp_val);
        }
        matrix.push_back(temp);
    }
    cout<<endl;

    bool sign = true;
    for(int row = 0; row<order; row++){
        cout<<"entering row:"<<row<<endl;
        for(int row_to_be_swapped = row + 1; matrix[row][row] == 0 && row_to_be_swapped < order ; row_to_be_swapped++ ){
            if(matrix[row_to_be_swapped][row] != 0){
                swap(matrix[row_to_be_swapped], matrix[row]);
                sign = !sign;
                break;
            }
        }
        cout<<"printing after removing zero\n";
        for(int i = 0; i < order; i++){
            for(int j = 0; j < order; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }

        for(int row_to_be_subtracted = row+1; row_to_be_subtracted < order; row_to_be_subtracted++){
            double factor = matrix[row_to_be_subtracted][row]/matrix[row][row];
            for(int column = row; column<order; column++){
                matrix[row_to_be_subtracted][column] = matrix[row_to_be_subtracted][column] - matrix[row][column]*factor;
            }
        }

    }
    for(int i = 0; i < order; i++){
        for(int j = 0; j < order; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    double det=1;
    for(int i = 0; i<order;i++){
        det = det*matrix[i][i];
    }
    cout<<"det is:"<<det* ((-1)+ 2*sign);




}
