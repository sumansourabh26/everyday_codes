#include<simplecpp>
void draw(double level,double x,double y,double n){
	for(double i=0;i<level;i++){
		if(i==0){
			Line line(x,y,x,y-500/n);
			line.imprint();
			Circle crl(x,y-500/n,abs(10-n));
			crl.setColor(COLOR("red"));
			crl.setFill();
			crl.imprint();
		}
		else{
			Line line(x,y,x+500*(pow(2,i-1))/(pow(2,n-1)-1),y-500/n);
			line.imprint();
			Circle crl(x+500*(pow(2,i-1))/(pow(2,n-1)-1),y-500/n,abs(10-n));
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
	cin>>n;
	initCanvas ("binomial",600,600);
	draw(n,20,580,n);
	Circle crl(20,580,abs(10-n));crl.setColor(COLOR("red"));crl.setFill();
	crl.imprint();
	wait(5);
	closeCanvas();
}
	
	
