#include <iostream>
#include <vector> 
#include <cstdio>

using namespace std;

long long func(vector< vector<long long> > &array, long A[], long i, long k, long &length){
	if(k == 0 ){
		//cout<<"for"<<i<<' '<<k<<" returned 1 : case 1"<<endl;
		return 1;
	}

	if(k > length-i){
		//cout<<"for"<<i<<' '<<k<<"returned 0: case 2"<<endl;
		return 0;
	}
	if(((length - i) == 1)&& k==1){
		//cout<<"for"<<i<<' '<<k<<"returned "<<A[i]<<"case 5"<<endl;
		return A[i];
	}

	if(array[i][k] == -1){
		array[i][k] = ((A[i]*(func(array, A, i+1, k-1, length)%100003))%100003 + func(array, A, i+1, k, length)%100003)%100003;
		//cout<<"for"<<i<<' '<<k<<"returned "<<array[i][k]<<"case 4"<<endl;
		return array[i][k];
	}

	//cout<<"for"<<i<<' '<<k<<"returned "<<array[i][k]<<"case 3"<<endl;
	return array[i][k];
	
}


int main(){
	long length;
	cin>> length;

	long A[length];

	vector< vector<long long> > array(length, vector<long long>(length+1,-1));

	array[length-1][0] = 0;

	for(long i = 0; i < length; i++){
		cin>>A[i];
		//array[i][0]=0;
		//cout<<endl<<A[i]<<endl;
	}
	
	long testcasesCount;
	cin>>testcasesCount;
	long k;

	while(testcasesCount--){
		cin>>k;
		cout<< func(array,A,0,k,length)<< endl;
	}
}