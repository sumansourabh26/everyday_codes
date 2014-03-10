#include <simplecpp>
int main(){
  initCanvas("Events", 800,500);
  XEvent event;  // class defined in simplecpp
  {
    Text t1(400,20,"Move mouse with or without some button pressed.");
    Text t2(400,40,"Press some key and see what is typed in command window");
    Text t3(400,60,"Press ESC key to go to next phase.");
    while(1){
      nextEvent(&event);  // wait for an event.
      if(mouseDragEvent(&event))
	Circle(event.xmotion.x, event.xmotion.y,2).imprint();

      if(mouseButtonPressEvent(&event)){
	cout << "Mouse button " << event.xbutton.button << "pressed.\n";
	Circle(event.xbutton.x, event.xbutton.y, 5).imprint();
      }
      if(keyPressEvent(&event)){
	char c = charFromEvent(&event);
	cout << "Read character: "<<int(c)<<' '<<c<<endl;
	if(c == '\33') break;  // ASCII code for ESC key in octal.
      }
    }
  } // text objects will be destroyed when control leaves this block.
  {
    Text t1(400,30,"Press l or r to turn the turtle anytime.");
    Text t2(400,50,"Press ESC to end.");
    Turtle t;
    while(true){
      XEvent event;
      if(checkEvent(&event)){  // returns false if no event has happened.
	if(event.type == KeyPress){
	  char c = charFromEvent(&event);
	  Circle(event.xkey.x, event.xkey.y, 10).imprint();
	  if(c == 'l') t.left(10);
	  else if(c == 'r') t.right(10);
	  else if(c == '\33') break; 
	}
      }
      else t.forward(1);
      wait(0.1);
    }
  }
}
