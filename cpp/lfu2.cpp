#include<simplecpp>
void lfu(int* s,int* a,int slot){
    int frq[slot],slotfilled=0,hit=0,miss=0;bool found=false;
    for(int i=0;i<slot;i++)frq[i]=0;
    
    for(int j=0;j<10;j++){
		found=false;
        for(int i=0;i<slotfilled;i++){
			
            if(a[i]==s[j]){//if the new entry matches with the existing once then the frz of that should be increased
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
                    a[slotfilled]=s[j];
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
                            a[slotfilled-1]=s[j];
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


