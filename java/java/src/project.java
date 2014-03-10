
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class employee{
	public String name;
	String experience;
	String working_hrs;
	String effciency;
	String age; 
	
	employee(String name, String experience,String age, String working_hrs,String effciency){
		this.age=age;
		this.effciency=effciency;
		this.name=name;
		this.experience= experience;
		this.working_hrs=working_hrs;
		
	}
}
class g{
	public static employee_array array = new employee_array();
	
}
class employee_array{
	public static employee[] group = new employee[100];
	public static int count = -1;
	static void add_employee(employee e){
		group[count+1] = e;
		count++ ;
	}
	
	
	public static employee find(String n){ 
		int i = 0;
		for(; i<= count; i++){
			if(group[i].name == n) return group[i];
		}
		if (i>count) {
			JOptionPane.showMessageDialog(null, "wrong name"); 
		}
		return null;
	}
	
	void show_employee(String n){
		employee e = find(n);
		JOptionPane.showMessageDialog(null, "name: "+e.name+"\n"+"age: "+e.age+"\n" +"experience: "+e.experience+"\n"+
											"working hrs now: "+e.working_hrs, "biodata of"+n,JOptionPane.PLAIN_MESSAGE);
	}
}

class class_project extends JFrame{
	JTextField txt_name, txt_age, txt_efficiency,txt_working_hrs,txt_experience;
	JLabel l_name, l_age, l_efficiency,l_working_hrs,l_experience;
	JButton submit;
	class_project(){
		super("enter details");
		setLayout(new FlowLayout());
		
		l_name = new JLabel("enter your name");add(l_name);
		txt_name = new JTextField( );add(txt_name);
		l_age = new JLabel("enter your age");add(l_age);
		txt_age = new JTextField();add(txt_age);
		l_experience = new JLabel("enter your experience");add(txt_experience);
		txt_experience = new JTextField();add(txt_experience);
		l_efficiency = new JLabel("enter the efficiency");add(l_efficiency);
		txt_efficiency = new JTextField();add(txt_efficiency);
		l_working_hrs = new JLabel("enter working hrs");add(l_working_hrs);
		txt_working_hrs = new JTextField();add(txt_working_hrs);
		submit = new JButton("submit the details"); add(submit);
		submit.addActionListener(new handler());
	}
	private class handler implements ActionListener{
		void ActionPerformed(ActionEvent action){
			
		}
	}
}


public class project {
	public static void main(String[] args) {
		Object[] options = {"enter new employee","check previous employee"};
		int i = JOptionPane.showOptionDialog(null, "click on your option", "hello", JOptionPane.YES_NO_OPTION,JOptionPane.DEFAULT_OPTION,null,options,options[1]);
	}
}
