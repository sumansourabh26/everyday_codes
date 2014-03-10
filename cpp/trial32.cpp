#include<simplecpp>

int sqr(int x){
	return x*x;
}

bool intersecting( int x1,int y1, int r1, int x2, int y2, int r2){
	if((sqrt (sqr(x1-x2) + sqr(y1-y2))) < r1 + r2){
		
		 return (true) ;		 	
	else return (false);	
}
int main(){
	cout<<intersecting(0 ,0, 5, 2, 0, 7);

}
