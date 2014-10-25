#include <iostream>

using namespace std;


int array[] = {1, 2, 5, 10, 20, 50,100,200};

int change(int left, int index){
	if((left < 0) || index > 8){
		return 0;
	}
	else if(left == 0){
		return 1;
	}
	return change(left,index+1) + change(left-array[index], index);
}

int main(){
	int n;
	cin>>n;

	int array[n][8] = 

	while(n--){
		int total;
		cin>>total;
		cout<<change(total,0)<<endl;
	}
}