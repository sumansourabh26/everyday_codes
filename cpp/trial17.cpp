//our project  on archery
#include <simplecpp>



double mod(double x, double y)
{
	return sqrt(x*x+y*y);
}

double projectile(Polygon &arrow,double vx,double vy, double acc)
{
	double x=70, y=350;
	while(x<=900)
	{
		vy+=acc;
		arrow.move(vx,vy);
		arrow.right(180*atan(acc/vx)/PI);
		x+=vx;
		y+=vy;
		
	}
	return y;
}
double  setscore(double yend)
{
	double point;
	if (abs(yend-350)<25)
		point=50;
	else
		if(abs(yend-350)<50)
			point=40;
		else
		if(abs(yend-350)<75)
			point=30;
		else
			if(abs(yend-350)<100)
				point=20;
			else
				if(abs(yend-350)<125)
					point=10;
				else
					if(abs(yend-350)<50);
					else
						point=-10;
						
	return point;
}
void cross(double yend,int color)
{
	Line l1(1095,yend-5,1105,yend+5);
	if(color==1)
		l1.setColor(COLOR("yellow"));
	l1.imprint();
	l1.reset(1105,yend-5,1095,yend+5);
	if(color==1)
	l1.setColor(COLOR("yellow"));
	l1.imprint();					
}
int main()
{
	initCanvas("ARCHERY",1300,700);
	double v=0,x,y,angle=0,acc=0.05,vx,vy,point=0;
	double score=0;
	Line l(900,0,900,700);
	l.imprint();
	Circle c;
	Text t;
	Rectangle r(650,350,1300,700);
	r.setColor(COLOR(200,247,97));
	r.setFill(1);
	r.imprint();
	Text(1100,50,"score:").imprint();
	Text printscore(1150,50,score);
	Text(1100,80,"gravity:").imprint();
	Text gravity(1150,80,acc);
	Text _score(550,350,"SCORE   +");
	Text scoreNow;
	_score.hide();
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
	c.reset(0,0,0);
	double arrow_coord[10][2]={{80,2.5},{80,5},{90,0},{80,-5},{80,-2.5},{5,-2.5},{-5,-5},{0,0},{-5,5},{5,2.5}};
	double bow_coord[][2]={{0,0},{0,100},{15,86},{30,67},{40,49},{50,0},{40,-49},{30,-67},{15,-86},{0,-100}};
	XEvent event;
	double arrowx=70,arrowy=350;
	
	Polygon arrow(arrowx,arrowy,arrow_coord,10);
	Polygon bow(70,350,bow_coord,10);
	arrow.setColor(COLOR(130,130,130));
	arrow.setFill(1);
	while(1)
	{	
			nextEvent(&event);
			if(mouseButtonPressEvent(&event))
			{
				if(event.xbutton.x>65&&event.xbutton.x<75&&event.xbutton.y>345&&event.xbutton.y<355)
				{ 
					while(1)
					{
						nextEvent(&event);
						if(mouseDragEvent(&event))
						{	
							x=event.xmotion.x;
							y=event.xmotion.y;
							
							if(x<70&&x>40&&y>325&&y<375)
							{	
								arrow.reset(x,350,arrow_coord,10);
								arrow.setColor(COLOR(130,130,130));
								arrow.setFill(1);
								bow_coord[0][0]=-mod(x-70,y-350);
								v=0.5*mod(x-70,y-350);
								bow.reset(70,350,bow_coord,10);
								angle=180*atan((y-350)/(x-70))/PI;
								bow.right(angle);
								arrow.right(angle);
							}
						}
						if(mouseButtonReleaseEvent(&event))
						{
							vx=v*cosine(angle);
							vy=v*sine(angle);
							
							bow_coord[0][0]=0;
							bow.reset(70,350,bow_coord,10);
							y=projectile(arrow,vx,vy,acc);
							point=setscore(y);
							score+=point;
							_score.show();
							scoreNow.reset(590,350,point);
							scoreNow.show();
							
							printscore.reset(1150,50,score);
							gravity.reset(1150,80,acc);
							if(y>325&&y<375)
								cross(y,1);
							else
								if(y>200&&y<500)
								cross(y,0);
							wait(2);
							_score.hide();
							scoreNow.hide();
							break;
						}
					}
				arrow.reset(arrowx,arrowy,arrow_coord,10);
				arrow.setColor(COLOR(130,130,130));
				arrow.setFill(1);
				}		
					
			}	
				
	}			
	 
	getClick();
}
