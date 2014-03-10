#include<simplecpp>
#include<string>
#include<vector>
class mTurtle: public Turtle{
	double distance;
	public:
	mTurtle(double x, double y): Turtle(x,y){
		distance=0;
	}
	void forward(double d){
		distance=distance+d;
		Turtle :: forward(d);
	}
	double how_far(){
		return distance;
	}
};

int main(){
	initCanvas();
	mTurtle t1(100,400);
	t1.forward(10);getClick();t1.forward(10);
	cout<< t1.how_far();
}
