#include<simplecpp>
int main()
{
	initCanvas("car to plane",1000,800);
	getClick();					//click to start
	double p[8][2]={{150,250},{250,250},{350,150},{450,150},{550,250},{650,250},{650,350},{150,350}};//initially coordinates of point of car
	Polygon car(0,0,p,8);
	double v[8][2]={{-2.5,-2.5},{-5,-2.5},{-5,5},{0,5},{5,0},{2.5,2.5},{0,0},{0,0}};

	for (int i=0; i<20; i++) {
		for (int j=0; j<8; j++) {
			for (int k=0; k<2; k++) {
				p[j][k]=p[j][k]+v[j][k];		//changing each point iteratively
			};
		};

		car.reset(0,0,p,8);  //making new polygon car

		wait(0.1);				//b/n each trastition time is 0.1 sec
	};

	getClick();				//click to close
}
