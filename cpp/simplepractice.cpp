#include<simplecpp>

struct dmy{
	int day, month,year;
	void print(){
		cout<<day<<"/"<<month<<"/"<<year<<endl;
}
};

struct student {
	char name[50];
	int rollno;
	char degree[50];
	dmy dob;
	float cpi;
	student( char x[50],int a,char y[50] ,dmy z ){
		strcpy(name,x);
		strcpy(degree,y);
		dob=z;
		a=rollno;
		cpi=0;
	}
	//student(){}
	void print(){
		cout<<"name: "<<name<<endl;
		cout<<"rollno: "<<rollno<<endl;
		cout<<"degree: "<<degree<<endl;
		cout<<"date: ";dob.print();
		if(cpi!=0){
			cout<<"cpi: "<<cpi<<endl;}
			}
};
int main(){
	dmy d={1,1,1993};
	student s1("Perry Mason",51005008 ,"LL.B", d);
	s1.print();
	
	student classof2012[5];
	for(int i=0;i<5;i++){
		cin.getline(classof2012[i].name,50);
		cin>>classof2012[i].rollno;
		cin.getline(classof2012[i].degree,50);
		cin>>classof2012[i].dob.day>>classof2012[i].dob.month>>classof2012[i].dob.year>>classof2012[i].cpi;
	}
	
	for(int j=0;j<5;j++)
	{
		classof2012[j].print();
	}
}
	
