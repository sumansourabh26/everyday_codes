
// * what is the integer return value of is selected type of true/false */ 
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class class31 extends JFrame{
	JRadioButton[] b = new JRadioButton[4];
	private Icon[] i = {new ImageIcon(getClass().getResource("image/fat.png")),
						new ImageIcon(getClass().getResource("image/dating.png")),
						new ImageIcon(getClass().getResource("image/healthy.png")),
						new ImageIcon(getClass().getResource("image/k.png")),};
	JLabel pic;
	
	class31(){
		super("the title"); setLayout(new FlowLayout());
		b[0] = new JRadioButton("k",false);add(b[0]);
		b[1] = new JRadioButton("fat",false);add(b[1]);
		b[2] = new JRadioButton("date",false);add(b[2]);
		b[3] = new JRadioButton("healthy",false);add(b[3]);ButtonGroup g = new ButtonGroup();
		g.add(b[0]);g.add(b[1]);g.add(b[2]);g.add(b[3]);
		pic = new JLabel();
		add(pic);
		for(int i=0; i< 4;i++){
			b[i].addActionListener(new handler(i));
		}
		
	}
	private class handler implements ActionListener{
		int index;
		handler(int  index){
			this.index = index;
		}
		public void actionPerformed(ActionEvent action){
			pic.setIcon(i[index]);
		}
	}
}


public class trial31 {
	public static void main(String[] args) {
		class31 screen = new class31();
		screen.setSize(200,200);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
