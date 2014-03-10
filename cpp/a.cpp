#include<simplecpp>
int main(){
	initCanvas();
	Text t(340,430,"qwerty");
	t.imprint();
	
	t.setScale(10);
	t.imprint();
	getClick();
}
