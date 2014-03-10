#include<simplecpp>
void draw(double level,double x,double y,double n){
	int r;
	if(n<10) r=10-n;
	else r=1;
	for(double i=0;i<level;i++){
		if(i==0){
			Line line(x,y,x,y-500/n);
			line.imprint();
			Circle crl(x,y-500/n,r);
			crl.setColor(COLOR("red"));
			crl.setFill();
			crl.imprint();
		}
		else{
			Line line(x,y,x+500*(pow(2,i-1))/(pow(2,n-1)-1),y-500/n);
			line.imprint();
			Circle crl(x+500*(pow(2,i-1))/(pow(2,n-1)-1),y-500/n,r);
			crl.setColor(COLOR("red"));
			crl.setFill();
			crl.imprint();
			draw(i,x+500*(pow(2,i-1))/(pow(2,n-1)-1),y-500/n,n);
		}
	}
		return ;
}
		
main_program{
	int n;
	int r;
			if(n<10) r=10-n;
			else r=1;
	cout<<"enter no. of levels";
	cin>>n;
	initCanvas ("its me",600,600);
	draw(n,20,580,n);
	Circle crl(20,580,r);crl.setColor(COLOR("red"));crl.setFill();
	crl.imprint();
	
	getClick();
	closeCanvas();
}
	
	
