#include<simplecpp>

void change(int totallevel,int level, int domination[],int countlvl[], int left){
	if(level>totallevel){
		cout<<"-1";
		return ;
	}
	if(level<=totallevel){
		if(left==0){
			int count=0;
			 for(int i=0;i<totallevel;i++){
				count=count+countlvl[i];
			 }
			 cout<<count;
			 return ;
		}
		
		if(left!=0){
			if(countlvl[>0){
				countlvl[level]=left/domination[level];
				left=left%domination[level];
				change(totallevel,level-1,domination[],countlvl[],left);
			}
			if(level==0){
				countlevel[level]=countlevel[level]-1;
				change(totallevel,level+1,domination,countlevel,left=left+domination[level+1];
		}
	}
}	
			
			
int main(){
	int level;
	cin>>level; int totallevel=level;
	int domination[level];
	for(int i=0;i<level; i++){
		cin>>domination[i];
	}
	int left,countlvl[level]; cin>>left;
	for(int i=0;i<level;i++){
		countlvl[i]=0;
	}
	change(totallevel,level-1, domination,countlvl,left);
}
		
