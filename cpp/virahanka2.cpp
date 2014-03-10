#include<simplecpp>
void vir(int n,double r,float k, float x1,float y1){
	if(r==1||r==2) return ;
	else{
		Line l1(x1,y1,x1+k,y1+480/(n-2));
		l1.imprint();
		Text t1(x1-5,y1,r);
		vir(n,r-1,k/2,x1+k,y1+480/(n-2));
		
		Line l2(x1,y1,x1-k,y1+480/(n-2));
		l2.imprint();
		
		vir(n,r-2, k/2,x1-k,y1+480/(n-2));
	}
}



main_program{
	int n,r;
	cin>>n;
	r=n;
	initCanvas("its", 1000,500);
	 float k=100;
	 vir(n,r,k,500,10);
	 getClick();
 }
