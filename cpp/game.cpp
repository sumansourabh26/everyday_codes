#include<simplecpp>
int main()
{
	initCanvas("tic-tac-toe",1000,800);

	for (int i=0; i<4; i++) {
		Line l1(200+i*200,100,200+i*200,700);
		l1.imprint();
		Line l2(200,100+i*200,800,100+i*200);
		l2.imprint();
	};

	int v[3][3]={{10,10,10},{10,10,10},{10,10,10}};

	for (int i=0; i<9; i++) {
		double x,y;
		int pos,s=1;
		pos=getClick();
		x=pos/65536;
		y=pos%65536;

		if ((x>200)&&(x<=800)&&(y>100)&&(y<900)) {
			int p=(x-200)/200,q=(y-100)/200;

			if (i%2==0) {
				Text t(300+p*200,200+q*200,"x");
				t.imprint();
				v[p][q]=0;
			}

			if (i%2==1) {
				Text t(300+p*200,200+q*200,"0");
				t.imprint();
				v[p][q]=1;
			}

			for (int p=0; p<3; p++) {
				bool goon=true;

				for (int q=0; q<3; q++) {
					goon=goon&&(v[q][p]==0);
				}

				if (goon) {
					if (i%2==0) {
						cout<<"winner is x"<<endl;
						s=-1;
						break;
					} else {
						cout<<"winner is 0"<<endl;
						s=-1;
						break;
					};
				};
			}

			for (int p=0; p<3; p++) {
				bool goon=true;

				for (int q=0; q<3; q++) {
					goon=goon&&(v[p][q]==0);
				}

				if (goon) {
					if (i%2==0) {
						cout<<"winner is x"<<endl;
						s=-1;
						break;
					} else {
						cout<<"winner is 0"<<endl;
						s=-1;
						break;
					};
				}

				if ((v[0][0]+v[1][1]+v[2][2]==0)||((v[0][2]+v[2][0]+v[1][1]==0))
				    ||(v[1][1]+v[0][0]+v[2][2]==3)||(v[0][2]+v[2][0]+v[1][1]==3)) {
					if (i%2==0) {
						cout<<"winner is x"<<endl;
						s=-1;
						break;
					} else {
						cout<<"winner is 0"<<endl;
						s=-1;
						break;
					};
				}
			};

			if (s==-1) {
				cout<<"game ends"<<endl;
				break;
			}
		} else {
			cout<<"invalid entry"<<endl;
			break;
		}

		;
	}

	;
}

