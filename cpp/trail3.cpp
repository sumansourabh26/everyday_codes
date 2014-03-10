#include<simplecpp>

struct dmy{
	int day, month,year;
	/*dmy(int x, int y, int z){
		day=x,month=y,year=z;
	}*/
	void print(){
		cout<<day<<"/"<<month<<"/"<<year<<endl;
}
};

struct student {
	char name[50];
	int rollno;
	char degree[50];
	dmy dob;
	
	/*student( char x[50],int a,char y[50] ,dmy z ){
		name=x,degree=y,dob=z;a=rollno;
		cpi=0;
	}*/
	student(){}
	student print(){
		cout<<"name"<<name<<endl;
		cout<<"rollno"<<rollno<<endl;
		cout<<"degree"<<degree<<endl;
		cout<<"date";dob.print();
	}
};
int main(){
	student s1={"Perry Mason",51005008 ,"LL.B", {1,1,93} };
	s1.print();
	
	student classof2012[5];
	for(int i=0;i<5;i++){
		cin>>classof2012[i].rollno>>classof2012[i].dob.day>>classof2012[i].dob.month>>classof2012[i].dob.year;
		cin.getline(classof2012[i].name,50);
		cin.getline(classof2012[i].degree,50);
	}
	
	for(int j=0;j<5;j++)
	{
		classof2012[j].print();
	}
}
	
