import java.awt.FlowLayout; //will give default layout to thing
import javax.swing.JFrame; //gives all basic window feature      //all this we import is classes
import javax.swing.JLabel; //is simply for the text

class tuna extends JFrame{ 
	private JLabel item1; // item1 is a object of type JLabel 
	public tuna(){ 
		super("the title-bar"); //super gives the title
		setLayout(new FlowLayout()); //setLayout gives layout but as said earlier Flowlayout gives default layout
		item1 = new JLabel("it is a text");
		item1.setToolTipText("suman");
		add(item1);
	}
}

public class trial24 {
	public static void main(String args[]){
		tuna object1 = new tuna();
		object1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		object1.setSize(300,300);
		object1.setVisible(true); 
	}
}
