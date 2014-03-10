import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

class class_font extends JFrame{
	JRadioButton n,b,i,bi;
	JTextField t,t2;
	ButtonGroup g;
	
	public class_font(){
		super("change font");
		setLayout(new FlowLayout());
		n = new JRadioButton("normal",true);add(n);
		b = new JRadioButton("bold",false);add(b);
		i = new JRadioButton("italic",false);add(i);
		bi = new JRadioButton("italic + bold",false);add(bi);
		t = new JTextField("enter your text here",20);add(t);
		t2 = new JTextField("enter 2",20);add(t2);
		g = new ButtonGroup();
		g.add(n);g.add(b);g.add(i);g.add(bi);
		
		n.addItemListener(new ihandler(new Font("Serif",Font.PLAIN, 14 )));
		b.addItemListener(new ihandler(new Font("Serif",Font.BOLD, 14 )));
		bi.addItemListener(new ihandler(new Font("Serif",Font.BOLD+Font.ITALIC, 14)));
		i.addItemListener(new ihandler(new Font("Serif",Font.ITALIC, 14 )));
		//t.addItemListener(new thandler());
	}
	
	private class ihandler implements ItemListener{
		Font f;
		public ihandler(Font x){
			f = x;
		}		
		public void itemStateChanged(ItemEvent arg0) {
			if(arg0.getStateChange()==ItemEvent.SELECTED){
				t.setFont(f);
			}
			else if(arg0.getStateChange()!=ItemEvent.SELECTED){
				t2.setFont(f);
			}
		}
	}
	private class thandler implements ItemListener{
		Font f;		
		public void itemStateChanged(ItemEvent arg0) {
			if(arg0.getStateChange()==ItemEvent.SELECTED){
				t.setFont(f);
			}
			else if(arg0.getStateChange()!=ItemEvent.SELECTED){
				t2.setFont(f);
			}
		}
	}	
	
	private class handler implements ActionListener{
		Font f;
		public handler(Font x){
			f = x;
		}
		public void actionPerformed(ActionEvent event) {
			t.setFont(f);
		}	
	}
}

public class font {
	public static void main(String[] args) {
		class_font screen = new class_font();
		screen.setSize(500,500);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}