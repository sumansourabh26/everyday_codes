#include<simplecpp>
void draw(double level,double x,double y,double n){
	for(double i=0;i<level;i++){
		if(i==0){
			Line l(x,y,x,y-500/n);
			l.imprint();
			Circle c(x,y-500/n,abs(10-n));
			c.setColor(COLOR("red"));
			c.setFill();
			c.imprint();
		}
		else{
			Line l(x,y,x+500*(pow(2,i-1))/(pow(2,n-1)-1),y-500/n);
			l.imprint();
			Circle c(x+500*(pow(2,i-1))/(pow(2,n-1)-1),y-500/n,abs(10-n));
			c.setColor(COLOR("red"));
			c.setFill();
			c.imprint();
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
	Circle c(20,580,abs(10-n));c.setColor(COLOR("red"));c.setFill();
	c.imprint();
	wait(5);
	closeCanvas();


}
	
	
