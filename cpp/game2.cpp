/*the main point used is that each particular square can be assigned a no.  and that if in a line all are 1, there product is 1 && similarly for 2 its 8 */
#include<simplecpp>
int main(){
	initCanvas("tic-tac-toe",150,150);
	int checkout;
	for (int i=0; i<2; i++) {
		Line l1(50+i*50,0,50+i*50,150);
		l1.imprint();
		Line l2(0,50+i*50,150,50+i*50);
		l2.imprint();
	}; // just prints a 3X3 cube
	
	int square[3][3],a,b;
	for(a=0;a<3;a++){
		for( b=0;b<3;b++){
			square[a][b]=0;
		}
	} // assigns a definite variable to each square, eg., a[i][j] to square (i,j)
	int n,pos;
	for(n=1;n<10;n++){
		pos=getClick();			//getClick...click the required slot
		int i=(pos/65536)/50;			
		int j=(pos%65536)/50;
		
		double g=(pos/65536)/50;
		double h=(pos%65536)/50;
		if(n%2==1){
			Text t(25+50*g,25+50*h,"x"); 
			t.imprint();
		}
		if(n%2==0){
			Text t(25+50*g,25+50*h,"0");
			t.imprint();
		}												//print X or O accordingly
		
		if(n%2==1) square[i][j]=1;			// first player virtually denoted by 1,thus assign all its square 1
		if(n%2==0) square[i][j]=2;		//2nd player by 2,thus assign all its square 2
		
		if(n>4){									//before n=5, its impossible to complete the game
			int q;								
			if((square[0][0]*square[1][1]*square[2][2]==1)||(square[0][2]*square[1][1]*square[2][0]==1)){
				checkout=1;
				cout<<"player 1 wins"<<endl;
				break;
				}										//check diagonal for p1
			if((square[0][0]*square[1][1]*square[2][2]==8)||(square[0][2]*square[1][1]*square[2][0]==8)){
				checkout=1;
				cout<<"player 2 wins"<<endl;
				break;
			}											//check diagonal for p1
			for(q=0;q<3;q++){
				int b=square[q][0]*square[q][1]*square[q][2], c=square[0][q]*square[1][q]*square[2][q]; 
				if(b==1||c==1){
					checkout=1;
					cout<<"player 1 wins"<<endl;
					break;							//check horizontal and vertical for p1
				}
				if(b==8||c==8){
					checkout=1;
					cout<<"player 2 wins";
					break;							//check horizontal and vertical for p1
				}
			}
		}
		if(checkout==1) break;				//breaks the main for loop if someone wins
	}
	if(n==10)
	cout<<"invalid";								//in case no one wins...its a LOL.
}
