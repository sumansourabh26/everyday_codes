#include<simplecpp> //r1 has been given more priority than r2




bool intersect(double r1px1, double r1py1,double r1px2,double r1py2, double r2px1,double r2py1, double r2px2,double r2py2){
	if(((r1px1<r2px1&&r1px2>r2px1)||(r1px1<r2px2&&r1px2>r2px2))&&((r1py1<r2py1&&r1py2>r2py1)||(r1py1<r2py2&&r1py2>r2py2))){
		return true;
	}
	else return false;
}
	

int main(){
	int n;
	cout<<"ur n=";
	double rect[n][4];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			cin>> rect[i][j];
		}
	}
	
	for(int i=n;i>1;i--){
		 
	
	
