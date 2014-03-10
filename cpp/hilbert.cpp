#include<simplecpp>
void tree(int n,int i){
	if(n==1){
	repeat(3){
		forward(20);
		switch(i){
			case 0:
			case 3:
			case 5:
			case 6: left(90);break;
			case 1:
			case 4:
			case 7:
			case 2:right(90);break;
		}
		
		}return;
	}
	repeat(2){
		int j;
		if(n%2==0)j=0;
		if(n%2==1)j=4;
		for(int i=j;i<4+j;i++){
			tree(n-1,i);
			wait(1);
			right(180);
			if(i==2||i==7)right(90-180*(n%2));
			if(i==3||i==6)left(90-180*(n%2));
			forward(20);
			wait(1);
			if(i==1||i==4)left(90-180*(n%2));
			wait(2);
            if(i==2||i==7)right(90-180*(n%2));
		}
	}
		right(90);
		wait(2);
	}
	
	main_program{
		int f;
		cin>>f;
		turtleSim();
		tree(f,0);
		getClick();
	}
		
