import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class rb extends JFrame{
	private JTextField tf;
	private Font pf, bf, itf,bif;
	private JRadioButton pb, bb, ib, bib;
	private ButtonGroup group;
	
	rb(){
		super ("the title");
		setLayout(new FlowLayout());
		
		tf = new JTextField("its a text", 20);add(tf);
		pb = new JRadioButton("plain",true);add(pb);
		bb = new JRadioButton("bold",false);add(bb);
		ib = new JRadioButton("italic",false);add(ib);
		bib = new JRadioButton("bold and italic",false);add(bib);
		group = new ButtonGroup();
		group.add(bb);group.add(pb);group.add(ib);group.add(bib);
		
		
		pf = new Font("serif",Font.PLAIN,14);
		bf = new Font("serif",Font.BOLD,14);
		itf = new Font("serif",Font.ITALIC,14);
		bif = new Font("serif",Font.ITALIC+Font.BOLD,14);
		tf.setFont(pf);
		//wait for event to happen, pass in font object as argument
		pb.addItemListener(new Handler(pf));
		bb.addItemListener(new Handler(bf));
		ib.addItemListener(new Handler(itf));
		bib.addItemListener(new Handler(bif));
	}
	private class Handler implements ItemListener{
		private Font font;
		
		// the font object get variable font
		public Handler (Font f){
			 font = f;	 
		}
		
		public void itemStateChanged(ItemEvent event){
			tf.setFont(font);
		}
	}
}

public class radio_button {
	public static void main(String[] args){
		rb screen = new rb();
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		screen.setSize(300, 300);
	}
}
