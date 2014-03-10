#include<simplecpp>
struct button{
	double cx,cy,w,h;
	char txt[50];
	
	void draw(){
		Rectangle r(cx,cy,w,h);
		r.imprint();
	}
		
	bool inside(double clickx, double clicky){
		return((abs(clickx-cx)<w/2) && (abs(cy-clicky)<h/2));
	}
};

main_program{
	button b;
	cin>>b.cx>>b.cy>>b.w>>b.h>>b.txt;
	initCanvas("suman",800,800);
	b.draw();
	int click=getClick();
	int bol=b.inside(click/65536,click%65536);
	cout<<bol;
}
