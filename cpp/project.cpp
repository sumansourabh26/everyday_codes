#include<simplecpp>
int main()
{
initCanvas("ARCHERY",1300,700);
	Line l(900,0,900,700);
	l.imprint();
	Circle c;
	Text t;
	Rectangle r(650,350,1300,700);
	r.setColor(COLOR(200,247,97));
	r.setFill(1);
	r.imprint();
	for(int i=0;i<6;i++)
	{
		c.reset(1100,350,150-25*i);
		c.setColor(COLOR(242*(5-i)%255,141*(5-i)%255,42*(5-i)%255));
		c.setFill(1);
		c.imprint();
		r.reset(888+2*i,350,24-4*i,50+50*i);
		r.setColor(COLOR(242*i%255,141*i%255,42*i%255));
		r.setFill(1);
		r.imprint();
		t.reset(910,340-i*25,50-i*10);
		t.setColor(COLOR(255,0,0));
		t.setFill(1);
		t.imprint();
		
	}
	Text t1(450,50,"***It's level 1***");
	t1.imprint();
	
	t1.setColor(COLOR(252,92,72));
	getClick();
}
