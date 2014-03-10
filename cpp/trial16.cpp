#include<simplecpp>
void help();
void home();
void game();
void end(int score);

void end(double score){
	initCanvas("end",1300,700);
	for(int i=0;i<6;i++){
		double points[4][2]={{650-78*i,350-42*i},{650-78*i,-350+42*i},{-650+78*i,-350+42*i},{-650+78*i,350-42*i}};
		Polygon rect(650,350,points,4);
		rect.setColor(COLOR(242*(6-i)%255,141*(6-i)%255,42*(6-i)%255));
		rect.setFill(1);
		rect.imprint();
	}
	Text final(650,350,"arrow didn't hit the board...your game is over");
	final.setColor(COLOR("RED"));
	final.imprint();
	Text scor(650,375,"your score is:");
	scor.setColor(COLOR("RED"));
	scor.imprint();
	scor.reset(700,375,score);
	scor.setColor(COLOR("RED"));
	scor.imprint();
	getClick();
}
	
struct color{
	int red,green,blue;
};

struct button{
	double cx,cy,w,h;char name[50];color button_color ;
	
	button(double a,double b,double c,double d,char nam[],color buttoncolor){
		cx=a,cy=b,w=c,h=d;strcpy(name,nam); 
		button_color=buttoncolor;
		Rectangle r1(cx,cy,w,h);
		r1.setColor(COLOR(button_color.red,button_color.green,button_color.blue));r1.setFill(1);
		r1.imprint();
		Text t1(cx,cy,name);
		t1.setColor(COLOR("RED"));
		t1.imprint();
	}	
	bool inside(int where){
		int clickx=where/65536, clicky=where%65536;
		return((abs(clickx-cx)<w/2) && (abs(cy-clicky)<h/2));
	}
};
		

void help(){
	initCanvas("help",1300,700);
	for(int i=0;i<6;i++){
		double points[4][2]={{650-78*i,350-42*i},{650-78*i,-350+42*i},{-650+78*i,-350+42*i},{-650+78*i,350-42*i}};
		Polygon rect(650,350,points,4);
		rect.setColor(COLOR(242*(6-i)%255,141*(6-i)%255,42*(6-i)%255));
		rect.setFill(1);
		rect.imprint();
	}
	color c={93,93,93};
	button bth(650,470,100,40,"back to home",c);
		
	Text t1( 620,220,"-->Adjust your arrow on the bow by clicking the rear side of the arrow");
	t1.imprint();
	Text t2(610,240,"-->Arrow must hit the board otherwise you will be thrown out of the game");
	t2.imprint();
	Text t3(540,260,"-->The value of gravity is random...be cautious");
	t3.imprint();
	int where=getClick(); int ptx=where/65536,pty=where%65536;
	if(ptx<750&&ptx>550&&pty>430&&pty<510){closeCanvas();home();}
}

void home(){
	initCanvas("ARCHERY-Home",1300,700);
	
	for(int i=0;i<6;i++){
		double points[4][2]={{650-78*i,350-42*i},{650-78*i,-350+42*i},{-650+78*i,-350+42*i},{-650+78*i,350-42*i}};
		Polygon rect(650,350,points,4);
		rect.setColor(COLOR(242*(6-i)%255,141*(6-i)%255,42*(6-i)%255));
		rect.setFill(1);
		rect.imprint();
	}
	
	color rc0={255,255,0},rc1={0,255,0},rc2={0,0,255};
	button play_button(650,256.666,520,93.333,"****PLAY****",rc0);
	button help_button(650,256.666+93.333,520,93.333,"***HOW TO PLAY***",rc1);
	button exit_button(650,256.666+93.333*2,520,93.333,"GET ME OUT OF HERE",rc2);
	while(true){
		int where=getClick();
		if (play_button.inside(where)==true){closeCanvas();game();break;}
		if(help_button.inside(where)==true){closeCanvas();help();break;}
		if(exit_button.inside(where)==true) {break;}
	
	/*Rectangle r1(0,0,0,0);
	for(int i=0;i<3;i++){
		r1.reset(650,256.666+93.333*i,520,93.333); r1.setColor(COLOR(60+60*i,60+60*i,60+60*i));r1.setFill(1);r1.imprint();
		}r1.reset(0,0,0,0);
	Text t(650,256.666,"****PLAY****"); t.setColor(COLOR("YELLOW"));t.imprint();
	Text t1(650,350,"**HOW TO PLAY**");t1.setColor(COLOR("GREEN"));t1.imprint();
	Text t2(650,443.334," GET ME OUT OF HERE");t2.setColor(COLOR("BLUE"));t2.imprint();
	
	while(true){
		int where=getClick();
		int ptx=where/65536, pty=where%65536;
		if(ptx<910&&ptx>390&&pty>210&&pty<303.333) {closeCanvas();game();break;}
		if(ptx<910&&ptx>390&&pty>303.333&&pty<396.666) {closeCanvas();help();break;}
		if(ptx<910&&ptx>390&&pty>396.666&&pty<490) {break;}*/
	}
}


double mod(double x, double y)
{
	return sqrt(x*x+y*y);
}
double projectile(Polygon &arrow,double v,double angle, double acc,double x,double y)
{
	double vx=v*cosine(angle);
	double vy=v*sine(angle);
	while(x<=900-90*cosine(angle))
	{
		vy+=acc;
		arrow.move(vx,vy);
		arrow.right(180*atan(acc/vx)/PI);
		angle+=180*atan(acc/vx)/PI;
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
void game()
{
	initCanvas("ARCHERY",1300,700);
	double v=0,x,y,angle=0,acc=0.15,point=0,angle1=0;
	double score=0;
	Line l(900,0,900,700);
	l.imprint();
	Circle c;
	Text t;
	Rectangle r(650,350,1300,700);
	r.setColor(COLOR(200,247,97));
	r.setFill(1);
	r.imprint();
	Rectangle back(1284,10,30,20);
	back.setColor(COLOR("yellow"));
	back.setFill(1);
	back.imprint();
	back.reset(0,0,0,0);
	Text bac(1285,10,"back");
	
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
	double bow_fixed[10][2];
	for(int i=0;i<10;i++)
	{
		bow_fixed[i][0]=bow_coord[i][0];
		bow_fixed[i][1]=bow_coord[i][1];
	}
	Polygon arrow(arrowx,arrowy,arrow_coord,10);
	Polygon bow(70,350,bow_coord,10);
	arrow.setColor(COLOR(130,130,130));
	arrow.setFill(1);
	while(1)
	{	
			nextEvent(&event);
			if(mouseButtonPressEvent(&event))
			{
				if(event.xbutton.x>1270&&event.xbutton.x<1300&&event.xbutton.y>0&&event.xbutton.y<20)
				{
					//home();
					break;
				}
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
								//arrow.left(angle);
								arrow.moveTo(x,y);
								//arrow.setColor(COLOR(130,130,130));
								//arrow.setFill(1);
								bow_fixed[0][0]=-mod(x-70,y-350);
								v=0.5*mod(x-70,y-350);
								angle=180*atan((y-350)/(x-70))/PI;
								for(int i=0;i<10;i++)
								{
									bow_coord[i][0]=bow_fixed[i][0]*cosine(angle)-bow_fixed[i][1]*sine(angle);
									bow_coord[i][1]=bow_fixed[i][1]*cosine(angle)+bow_fixed[i][0]*sine(angle);
								}
								bow.reset(70,350,bow_coord,10);
								//bow.right(angle);
								arrow.right(angle-angle1);
								angle1=angle;
							}
						}
						if(mouseButtonReleaseEvent(&event))
						{
							
							
							bow_fixed[0][0]=0;
							bow.reset(70,350,bow_fixed,10);
							y=projectile(arrow,v,angle,acc,x,y);
							point=setscore(y);
							if(point>=0)
								score+=point;
							else 
								{wait(2);closeCanvas();end( score);return;
							}
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
				angle1=0;
				}		
					
			}	
				
	}			
	 
	getClick();
}


int main(){
	home();
}

