#include<simplecpp>
int main()
{initCanvas();
	repeat(5)
	{	double p[20][2];
		for(int i=0;i<20;i++)
		{
			int click=getClick();
			p[i][0]=click/65536;
			p[i][1]=click%65536;
			
			if(i>0)
			{
				Line l(p[i-1][0],p[i-1][1],p[i][0],p[i][1]);
				l.imprint();
				if((p[i][1]==p[0][1]&&p[i][0]==p[0][0]))
				{	double pcopy[i][2];
					for(int j=0;j<i;j++)
					{
						pcopy[j][0]=p[i][0];pcopy[j][1]=p[i][1];
					}
					Polygon pol(0,0,pcopy,i);pol.setFill(true);
					pol.setColor(COLOR(230,67,67));
					
					break;
				}
			}
		}
	}
}
					
				
