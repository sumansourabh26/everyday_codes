#include<simplecpp>

void dance(Turtle &t){
	for(int i=0; i<4; i++){
		t.forward(100); wait(0.2); t.forward(-100);
		t.left(90);
	}
}

int main(){
	initCanvas("suman",600,600);
	Turtle t;
	dance(t);
	getClick();
}
