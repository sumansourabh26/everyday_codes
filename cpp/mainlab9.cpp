#include<simplecpp>
void lru(int* supply,int*a,int slot)
{
    int slotfilled=0,hit=0,miss=0;bool found=false;
    for(int j=0;j<10;j++){found=false;
        for(int i=0;i<slotfilled;i++){//determines if page is already present
            if(a[i]==supply[j]){
                hit++;
                found=true;int z=a[i];
                for(int k=i;k<slotfilled-1;k++){//pages are arrenged in accord of the use
					a[k]=a[k+1];   //terms are mutually changed
					}
					a[slotfilled-1]=z;//the term is changed for next iteration
             
            }
            }
            if(!found){        //words will be placed in spaces or replacd only and only if the page is not present already
                if(slotfilled<slot){miss++;//miss will increase by one since the page is not present
                    a[slotfilled]=supply[j];
                    slotfilled++;//since the new no. is put in the space thus the slot filled increases by one
                }
                else {miss++;
                    for(int i=0;i<slotfilled-1;i++){
                        a[i]=a[i+1];
                     }//shifting the terms towards the a[0]
                    a[slot-1]=supply[j];//new terms find place in the last terms 
                    }   
                }}
    cout<<"LRU:"<<endl;
    cout<<"hit:"<<10-miss<<endl<<"miss:"<<miss<<endl;
    for(int i=slotfilled-1;i>=0;i--){
        cout<<a[i]<<" ";}cout<<endl;
       
        return;}   


void lfu(int* supply,int* a,int slot){
    int frq[slot],slotfilled=0,hit=0,miss=0;bool found=false;
    for(int i=0;i<slot;i++)frq[i]=0;
    
    for(int j=0;j<10;j++){
		found=false;
        for(int i=0;i<slotfilled;i++){
			
            if(a[i]==supply[j]){//if the new entry matches with the existing once then the frz of that should be increased
                hit++;
                found=true;
                frq[i]++;
                int z=a[i];
                
                for(int k=i;k<slotfilled-1;k++){//arrenge according to the latest use
					a[k]=a[k+1];  //shifts the terms such that last is least 
					}
					a[slotfilled-1]=z;//latest term is updated according to input
            }}
            if(!found){
                if(slotfilled<slot){
                    a[slotfilled]=supply[j];
                    miss++;
                    frq[slotfilled]++;
                    slotfilled++;
                }
           else { 
		
                int minfrq=frq[0];
                miss++;
                for(int k=1;k<slot;k++){
                    if(frq[k]<minfrq) minfrq=frq[k];
                    }
                    for(int k=0;k<slotfilled;k++){	
                        if(frq[k]==minfrq){
							for(int p=k;p<slot-1;p++){
								a[p]=a[p+1];}
                            a[slotfilled-1]=supply[j];
                            frq[slotfilled-1]=1;
                            break;}
                            }
                            }
                            }}
                cout<<"LFU:"<<endl;
                cout<<"hit:"<<10-miss<<endl<<"miss:"<<miss<<endl;
                for(int k=0;k<slotfilled;k++){
                    cout<<a[k]<<" ";               
                } 
            return;
}        

int main(){
    int slot;
    cout<<"slot:";
    cin>>slot;
    int s[10],b[slot],a[slot];
    for(int i=0;i<10;i++){
        cout<<"input reference pages:";
        cin>>s[i];
     }
        lru(s,a,slot);
        lfu(s,b,slot);
        return 0;
}
