
#include<simplecpp>
void help();
void home();
void game(int level);
struct color
{
	int red,green,blue;
};
int ycoord=350;
struct button// draw button and check if the click is inside the button
{
	double cx,cy,w,h;char name[50];color button_color ;
		button(double a,double b,double c,double d,char nam[],color buttoncolor)
		{
			cx=a,cy=b,w=c,h=d;strcpy(name,nam); 
			button_color=buttoncolor;
			Rectangle r1(cx,cy,w,h);
			r1.setColor(COLOR(button_color.red,button_color.green,button_color.blue));r1.setFill(1);
			r1.imprint();
			Text t1(cx,cy,name);
			t1.imprint();
		}	
	bool inside(int where) // To check whether click is inside or outside button
	{
		int clickx=where/65536, clicky=where%65536;
		return((abs(clickx-cx)<w/2) && (abs(cy-clicky)<h/2));
	}
};
void end(double score) //displays the end page and displays the final score
{
	initCanvas("end",1300,700);
	for(int i=0;i<=100;i++)
	{
		double points[4][2]={{650-3.9*i,350-2.1*i},{650-3.9*i,-350+2.1*i},{-650+3.9*i,-350+2.1*i},{-650+3.9*i,350-2.1*i}};
		Polygon rect(650,350,points,4);
		rect.setColor(COLOR(250+(i/18),51+i*3,106+i*2));//0*(6-i)%255,55*(6-i)%255));
		rect.setFill(1);
		rect.imprint();
	}
	double points[4][2]={{650-78*5,350-42*5},{650-78*5,-350+42*5},{-650+78*5,-350+42*5},{-650+78*5,350-42*5}};
	Polygon rect(650,350,points,4);
	rect.setColor(COLOR(200,247,97));
	rect.setFill(1);
	rect.imprint();
	rect.reset(0,0,0,0);
	Text final(650,350,"arrow didn't hit the board... your game is over");
	final.imprint();
	Text scor(630,375,"your score is:");
	scor.imprint();
	scor.reset(700,375,score);
	scor.imprint();
	color c1={0,255,0};
	button close(560,450,78,30,"close",c1);
	button play(750,450,100,30,"play again",c1);
	int click=getClick();
	if(play.inside(click))
	{
		closeCanvas();
		game(1);
	}
}
void help() // explains some of the rules of game
{
	initCanvas("help",1300,700);
	for(int i=0;i<101;i++)
	{
		double points[4][2]={{650-3.9*i,350-2.1*i},{650-3.9*i,-350+2.1*i},{-650+3.9*i,-350+2.1*i},{-650+3.9*i,350-2.1*i}};
		Polygon rect(650,350,points,4);
		rect.setColor(COLOR(38+2*i,253+(i/34),15+2*i));
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
	int where=getClick(); 
	int ptx=where/65536,pty=where%65536;
	if(ptx<750&&ptx>550&&pty>430&&pty<510)
	{
		closeCanvas();
		home();
	}
}
void home() // its the introduction page
{
	initCanvas("ARCHERY-Home",1300,700);
	for(int i=0;i<26;i++)
	{
		double points[4][2]={{650-15.6*i,151.66666-4.2*i},{650-15.6*i,-151.66666+4.2*i},{-650+15.6*i,-151.66666+4.2*i},{-650+15.6*i,151.66666-4.2*i}};
		Polygon rect(650,151.66666+4.2*i,points,4);
		rect.setColor(COLOR((255/25)*i,(255/25)*i,0));
		rect.setFill(1);
		rect.imprint();
		double points2[4][2]={{650-15.6*i,46.666},{650-15.6*i,-46.666},{-650+15.6*i,-46.666},{-650+15.6*i,46.666}};
		Polygon rect2(650,350,points2,4);
		rect2.setColor(COLOR(0,(255/25)*i,(64/25)*i));
		rect2.setFill(1);
		rect2.imprint();
		double points1[4][2]={{650-15.6*i,151.66666-4.2*i},{650-15.6*i,-151.66666+4.2*i},{-650+15.6*i,-151.66666+4.2*i},{-650+15.6*i,151.66666-4.2*i}};
		Polygon rect1(650,700-(151.66666+4.2*i),points1,4);
		rect1.setColor(COLOR(0,(255/25)*i,(255/25)*i));
		rect1.setFill(1);
		rect1.imprint();
	}
	color rc0={255,255,0},rc1={0,255,64},rc2={0,255,255};
	button level0_button(450,256.666,400,93.333,"****LEVEL0****",rc0);
	button level1_button(850,256.666,400,93.333,"****LEVEL1****",rc0);
	button help_button(650,256.666+93.333,520,93.333,"***HOW TO PLAY***",rc1);
	button exit_button(650,256.666+93.333*2,520,93.333,"GET ME OUT OF HERE",rc2);
	while(true)
	{
		int where=getClick(); // Ask for click for further instruction
		if (level0_button.inside(where)==true)
		{
			closeCanvas();
			game(0);
			break;
		}
		if (level1_button.inside(where)==true)
		{
			closeCanvas();
			game(1);
			break;
		}
		if(help_button.inside(where)==true)
		{
			closeCanvas();
			help();
			break;
		}
		if(exit_button.inside(where)==true) 
			exit(0);
	}
}
double mod(double x, double y) //calculates and return distance between two points
{
	return sqrt(x*x+y*y);
}
double projectile(Polygon &arrow,double v,double angle, double acc,double x,double y)  //gives projectile motion to the arrow and returns y coordinate
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
	return y+90*sine(angle);
}
double  setscore(double yend) //returns points earned after each shot
{
	double point;
	if (abs(yend-ycoord)<25)
		point=50;
	else
		if(abs(yend-ycoord)<50)
			point=40;
		else
		if(abs(yend-ycoord)<75)
			point=30;
		else
			if(abs(yend-ycoord)<100)
				point=20;
			else
				if(abs(yend-ycoord)<125)
					point=10;
				else
					if(abs(yend-ycoord)<150)
						point=0;
					else
						point=-10;
						
	return point;
}
void cross(double yend,int color) //imprints a cross on the point on the front view of board, where the arrow hits it
{
	Line l1(1095,yend-5,1105,yend+5);
	if(color==1)
	    l1.setColor(COLOR("white"));
	l1.imprint();
	l1.reset(1105,yend-5,1095,yend+5);
	if(color==1)
	    l1.setColor(COLOR("black"));
	l1.imprint();	
	wait(2);				
}
void game(int level)
{
		initCanvas("ARCHERY",1300,700);
		double v=0,x,y,angle=0,acc,point=0,angle1=0;
		double score=0;
		Line l(900,0,900,700);
		acc=randuv(0,0.3);// Use acc as random variable
		l.imprint();
		Circle c[6];
		Rectangle r1[6];
		Text t[6];
		Rectangle r(650,350,1300,700);
		r.setColor(COLOR(200,247,97));
		r.setFill(1);
		r.imprint();
		r.reset(0,0,0,0);
		color c1={253,140,57};
		button back(1278,10,40,20,"back",c1);//Back button to come back to home page
		Text(1100,50,"score:").imprint();
		Text printscore(1150,50,score);
		Text(1100,80,"gravity:").imprint();
		Text gravity(1150,80,acc*100);
		Text _score;
		Text scoreNow;
		for(int i=0;i<6;i++)// Making of archary board in front view and in side view with 6  circles

		{
			c[i].reset(1100,350,150-25*i);
			c[i].setColor(COLOR(242*(5-i)%255,141*(5-i)%255,42*(5-i)%255));
			c[i].setFill(1);
			r1[i].reset(888+2*i,350,24-4*i,50+50*i);
			r1[i].setColor(COLOR(242*i%255,141*i%255,42*i%255));
			r1[i].setFill(1);
			t[i].reset(910,340-i*25,50-i*10);
			t[i].setColor(COLOR(255,0,0));
			t[i].setFill(1);
		}
		double arrow_coord[10][2]={{80,2.5},{80,5},{90,0},{80,-5},{80,-2.5},{5,-2.5},{-5,-5},{0,0},{-5,5},{5,2.5}};// Initialise arrow coordinates
		double bow_coord[][2]={{0,0},{0,100},{15,86},{30,67},{40,49},{50,0},{40,-49},{30,-67},{15,-86},{0,-100}};// Initialise bow coorinates
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
		int z=0;
		while(1)
		{	
			if(z==0)
			{
				if(level==1)
				 ycoord=randuv(300,500);
				for(int i=0;i<6;i++)
				{
					c[i].moveTo(1100,ycoord);
					r1[i].moveTo(888+2*i,ycoord);
					t[i].moveTo(910,ycoord-10-i*25);
				}
				z=1;
			}
		nextEvent(&event);
		if(mouseButtonPressEvent(&event)&&z==1)//To select the end point of arrow to stretch the thread
		{
			z=0;
			if(back.inside(65536*event.xbutton.x+event.xbutton.y))
			{
				closeCanvas();
				home();
				break;
			}
			if(event.xbutton.x>65&&event.xbutton.x<75&&event.xbutton.y>345&&event.xbutton.y<355)
			{ 
				while(1)
				{
					nextEvent(&event);
					if(mouseDragEvent(&event))// to drag the  arrow
					{	
						x=event.xmotion.x;
						y=event.xmotion.y;
						if(x<70&&x>35&&y>325&&y<375)
						{	
							arrow.moveTo(x,y);
							bow_fixed[0][0]=-mod(x-70,y-350);
							v=0.5*mod(x-70,y-350);//initial velocity proportional to stretch of bow's thread;
							angle=180*atan((y-350)/(x-70))/PI;
							for(int i=0;i<10;i++)
							{
								bow_coord[i][0]=bow_fixed[i][0]*cosine(angle)-bow_fixed[i][1]*sine(angle);//to change bow coordinate for rotation
								bow_coord[i][1]=bow_fixed[i][1]*cosine(angle)+bow_fixed[i][0]*sine(angle);
							}
							bow.reset(70,350,bow_coord,10);
							arrow.right(angle-angle1);
							angle1=angle;
						}
					}
					if(mouseButtonReleaseEvent(&event))// Release mouse button for start of projectile motion
					{
						bow_fixed[0][0]=0;
						bow.reset(70,350,bow_fixed,10);
						y=projectile(arrow,v,angle,acc,x,y);
						point=setscore(y);
						if(point>=0)
							score+=point;
						else 
						{
							wait(1);
							closeCanvas();
							end(score);
							return;
						}
						_score.reset(550,350,"score +");
						_score.show();
						scoreNow.reset(590,350,point);
						scoreNow.show();
						printscore.reset(1150,50,score);
						if(level==0)
						{
						    if(y>325&&y<375)
							cross(y,1);
						    else
							if(y>200&&y<500)
							cross(y,0);
						}
						_score.hide();
						scoreNow.hide();
						break;
					}
				}
				arrow.reset(arrowx,arrowy,arrow_coord,10);
				arrow.setColor(COLOR(130,130,130));
				arrow.setFill(1);
				angle1=0;
				acc=randuv(0,0.3);
				gravity.reset(1150,80,acc*100);
			}	

		}	

	}	
		getClick();
}
int main() //main body, required to just call the home function. :)
{
	home();
}



