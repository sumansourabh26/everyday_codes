import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import javax.swing.text.TabableView;

import sun.management.Agent;

class level2 extends JFrame{
	JRadioButton yes,no;
	ButtonGroup group;
	JLabel ins;
	Icon figure = new ImageIcon(getClass().getResource("image/measure-diagram.png"));
	Icon thin = new ImageIcon(getClass().getResource("image/thin.png"));
	Icon fat = new ImageIcon(getClass().getResource("image/fat.png"));
	Icon out = new ImageIcon(getClass().getResource("image/out.png"));
	Icon perfect = new ImageIcon(getClass().getResource("image/perfect.png"));
	Icon merry = new ImageIcon(getClass().getResource("image/merry.png"));
	Icon healthy = new ImageIcon(getClass().getResource("image/healthy.png"));
	Icon reject = new ImageIcon(getClass().getResource("image/urejected.png"));
	Icon dating = new ImageIcon(getClass().getResource("image/dating.png"));
	
	
	level2(){
		super ("level2");
		setLayout(new FlowLayout());
		ins = new JLabel("are you interested i me?"); add(ins);
		String s= "suman";
		yes= new JRadioButton("yes",false);
		no= new JRadioButton("no",false);
		group = new ButtonGroup();
		handler handle = new handler();
		add(yes);add(no); group.add(yes); group.add(no);
		yes.addActionListener(handle);no.addActionListener(handle);
	}
	private class handler implements ActionListener{
		public void actionPerformed(ActionEvent action){
			Object[] figures = {"<33,<28,<33","36,32,36","33-41,28-35,33-38",">41,>35,>38"}; 
			if(yes.isSelected()){
				String result = (String)JOptionPane.showInputDialog(null, "enter ur figures", "level3", EXIT_ON_CLOSE, figure, figures,figures[1]);
				if(result == "<33,<28,<33"){
					JOptionPane.showMessageDialog(null, "go get some food","too thin",EXIT_ON_CLOSE,thin);
				}
				else if(result == ">41,>35,>38"){
					JOptionPane.showMessageDialog(null, "go loose some wait","too fat",EXIT_ON_CLOSE,fat);
				}
				else if(result == "36,32,36" ){
					Object[] yes_no = {"yes", "no"};
					int p = JOptionPane.showOptionDialog(null, "do u look like her?", "level3", DISPOSE_ON_CLOSE, DISPOSE_ON_CLOSE, perfect,yes_no,yes_no[0]);
					if(p == 0){
						int p1 = JOptionPane.showOptionDialog(null, "will you marry me", "proposal", DISPOSE_ON_CLOSE, DISPOSE_ON_CLOSE, merry, yes_no, yes_no[0]);
						if(p1 == 0)
							JOptionPane.showMessageDialog(null, "best couple ever", "finally", DISPOSE_ON_CLOSE,perfect);
						if(p1 == 1)
							JOptionPane.showMessageDialog(null, "ok...thats later, at least we should date", "okey ", DISPOSE_ON_CLOSE,dating );
						}
					else JOptionPane.showMessageDialog(null, "okey no probs...still we can date", "okey ", DISPOSE_ON_CLOSE,out );
				}
				else if(result=="33-41,28-35,33-38") JOptionPane.showMessageDialog(null, "still....lets date", "",DISPOSE_ON_CLOSE , healthy);
			}
			if(no.isSelected())
				//no.setSelected(false);
				JOptionPane.showMessageDialog(null, "u r rejected","go away",EXIT_ON_CLOSE,reject);
		}
	}
}

class class30 extends JFrame{
	String name="";
	int minAge, maxAge;
	JButton resetbutton, submitButton;
	JTextField nameField, ageField;
	Icon a = new ImageIcon(getClass().getResource("image/sister.png"));
	Icon b = new ImageIcon(getClass().getResource("image/2.png"));
	Icon c = new ImageIcon(getClass().getResource("image/k.png"));
	Icon d = new ImageIcon(getClass().getResource("image/urejected.png"));
	Icon little = new ImageIcon(getClass().getResource("image/small_girl.png"));
	public class30(int minAge1, int maxAge1){
		super("profile");
		this.minAge = minAge1;
		this.maxAge = maxAge1;
		
		setLayout(new FlowLayout());
		
		
		nameField= new JTextField("Enter your name",15);add(nameField);
		ageField = new JTextField("Enter your age", 15);add(ageField);
		
		resetbutton = new JButton("reset");
		submitButton = new JButton("submit");
		add(resetbutton);
		add(submitButton);
		
		resetbutton.addActionListener(
			new ActionListener() {

				public void actionPerformed(ActionEvent e) {
					// TODO Auto-generated method stub
					name = "";
					
					nameField.setText("");
					ageField.setText("");
				}
			}
		);
		submitButton.addActionListener(
			new ActionListener() {
				int ageOfGirl = 0;
				public void actionPerformed(ActionEvent arg0) {
					name = nameField.getText();
					ageOfGirl = Integer.parseInt(ageField.getText());
					if(ageOfGirl < minAge) {
						ageField.setText("");
						nameField.setText("");
						JOptionPane.showMessageDialog(null, "grow up baby come after "+ String.valueOf(minAge-ageOfGirl), "", DISPOSE_ON_CLOSE, little);	
					}
					else if(ageOfGirl>=minAge && ageOfGirl <= maxAge) {
						level2 frame2= new level2();
						frame2.setSize(400, 200);
						frame2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
						frame2.setVisible(true);
					}
					else {
						JOptionPane.showMessageDialog(null, null, ":(", DISPOSE_ON_CLOSE, a);
					}
					
				}
			}
		);
	
	}
	
}


public class trial33 {
	public static void main(String args[]){
		int min = 20, max = 40;
		class30 frame= new class30(min,max);
		frame.setSize(400, 200);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}
