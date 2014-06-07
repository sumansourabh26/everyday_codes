#include <iostream>

using namespace std; 

//best(i,j) = min(k : i≤k<j) best(i,k) + best(k+1,j) + csum(i,k)*csum(k+1,j).

int main(){
	int total;
	while(cin>>total){
		
		int color[100];
		for(int i = 0; i < total; i++){
			cin>>color[i];
			//cout<<i <<"th color is"<<color[i]<<endl;
		}


		int color_sum[100][100];
		for(int i = 0; i < total; i++){
			color_sum[i][i] = color[i];
		}
		for(int i = 0; i < total; i ++){
			for(int j = i+1; j < total; j++){
				color_sum[i][j] = (color[j] + color_sum[i][j-1])%100;
				//cout<<"color_sum "<<i<<' '<<j<< ':'<<color_sum[i][j]<<endl;
			}
		}



		int ans[101][101];
		for (int i = 0; i < total; i++){
			for(int j = 0; j < total; j++){
				ans[i][j]=0;
			}
		}

		int mini;
		for(int diff = 1 ; diff <= total; diff++){
			for(int i = 0; i+diff<total; i++){
				int j = i+diff;
				mini = 100000000;
				//cout<<"i:"<<i<<",j:"<<j<<endl;
				for(int k = i ; k < j; k++){
					//cout<<"k:"<<k<<endl;
					mini = min(mini, ans[i][k]+ans[k+1][j]+color_sum[i][k]*color_sum[k+1][j]);
				}
				ans[i][j] = mini;
				//cout<<"ans for "<<i<<" and "<<j<<':'<<mini<<endl;
			}
		}
		cout<<ans[0][total-1]<<endl;
	}
}