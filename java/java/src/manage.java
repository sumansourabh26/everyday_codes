import java.awt.*;
import javax.swing.*;

import java.awt.event.*;

class workers{
	static worker[] stack = new worker[100];
	static int count = -1;
	
	public static int find(String name){ 
		int i = 0;
		for(; i<= count; i++){
			System.out.println(stack[i].name == name);
			if(stack[i].name.equals(name)){ 
				System.out.println("ghanta "+i);
				return i;
			}
		}
		JOptionPane.showMessageDialog(null, "wrong name"); 
		System.out.println("wrong name");
		return -1;
		
	}
}

class worker{
	public String name;
	public String experience;
	public String working_hrs;
	public String efficiency;
	public String age;
	public boolean  betterment = false;
	worker(String name, String experience, String working_hrs,String efficiency,String age){
		this.age = age;
		this.efficiency=efficiency;
		this.experience=experience;
		this.name= name;
		this.working_hrs=working_hrs;
		System.out.println("constructor");
	}
}

class enter_data extends JFrame{
	JTextField txt_name, txt_age, txt_efficiency,txt_working_hrs,txt_experience;
	JLabel instruction, l_name, l_age, l_efficiency,l_working_hrs,l_experience;
	JButton submit, get_data;
	enter_data(int i){
		super("employee data base");
		setLayout(new FlowLayout());
		
		if(i==0){
			instruction = new JLabel("                                enter the data of new employee                               ");
		}
		if(i==1){
			instruction = new JLabel("check previous employee (just enter the name)");
		}
		if(i==2){
			instruction = new JLabel("modify previous data");
		}
		add(instruction);
		
		l_name = new JLabel("enter your name");add(l_name);
		txt_name = new JTextField(20 );add(txt_name); 
		get_data = new JButton("get info about(dont fill following details in this case");
		if(i==1)add(get_data);
		
		l_age = new JLabel("enter your age");//	
		txt_age = new JTextField(20);	//
		l_experience = new JLabel("enter your experience"); //	
		txt_experience = new JTextField(20);//	
		l_efficiency = new JLabel("enter the efficiency");//	
		txt_efficiency = new JTextField(20);//	
		l_working_hrs = new JLabel("enter working hrs");//	
		txt_working_hrs = new JTextField(20)	;//
		submit = new JButton("submit the details");	//
		submit.addActionListener(new handler());
		get_data.addActionListener(new handler());
		if(i != 1){
			add(l_age);add(txt_age);
			add(l_experience);add(txt_experience);
			add(l_efficiency);add(txt_efficiency);
			add(l_working_hrs);add(txt_working_hrs); add(submit);
		}
	}
	
	private class handler implements ActionListener{
		public void actionPerformed(ActionEvent action){
			if(action.getSource()== submit){
				workers.count++;System.out.println("count is " + workers.count);
				workers.stack[workers.count]= new worker(txt_name.getText(),txt_experience.getText(),txt_working_hrs.getText(),txt_efficiency.getText(),txt_age.getText()) ;
				txt_name.setText(null);txt_experience.setText(null);txt_age.setText(null);
				txt_working_hrs.setText(null);txt_efficiency.setText(null);
			}
			else if(action.getSource()==get_data){
				int pos = workers.find(txt_name.getText()); System.out.println("in get_data "+ pos +txt_name.getText());
				
				if(pos == -1){
					JOptionPane.showMessageDialog(null, "the "+ txt_name.getText()+" is invalid name" );
				}
				else{
					txt_experience.setText(workers.stack[pos].experience);
					txt_efficiency.setText(workers.stack[pos].efficiency);
					txt_working_hrs.setText(workers.stack[pos].working_hrs);
					txt_age.setText(workers.stack[pos].age);
					System.out.println("getname");
					add(l_age); add(l_age);
					add(l_experience);add(txt_experience);
					add(l_efficiency);add(txt_efficiency);
					add(l_working_hrs);add(txt_working_hrs);
					
				}
			}
			//else if(action.getSource())
			
		}
	}
}

class manage{
	static public void main(String[] args){
		Object[] options = {"enter new employee","check previous employee", "modify privious data"};
		int i = JOptionPane.showOptionDialog(null, "click on your option", "hello", JOptionPane.YES_NO_CANCEL_OPTION,JOptionPane.DEFAULT_OPTION,null,options,options[1]);
		enter_data new_emp = new enter_data(i);
		new_emp.setSize(400, 500);
		new_emp.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		new_emp.setVisible(true);
	
	}
}