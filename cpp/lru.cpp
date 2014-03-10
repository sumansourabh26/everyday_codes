#include<simplecpp>
void lru(int* s,int*a,int memory)
{
    int memoryfilled=0,hit=0,miss=0;bool found=false;
    for(int j=0;j<10;j++){found=false;
        for(int i=0;i<memoryfilled;i++){//determines if page is already present
            if(a[i]==s[j]){
                hit++;
                found=true;int z=a[i];
                for(int k=i;k<memoryfilled-1;k++){//pages are arrenged in accord of the use
					a[k]=a[k+1];   //terms are mutually changed
					}
					a[memoryfilled-1]=z;//the term is changed for next iteration
             
            }
            }
            if(!found){        //words will be placed in spaces or replacd only and only if the page is not present already
                if(memoryfilled<memory){miss++;//miss will increase by one since the page is not present
                    a[memoryfilled]=s[j];
                    memoryfilled++;//since the new no. is put in the space thus the memory filled increases by one
                }
                else {miss++;
                    for(int i=0;i<memoryfilled-1;i++){
                        a[i]=a[i+1];
                     }//shifting the terms towards the a[0]
                    a[memory-1]=s[j];//new terms find place in the last terms 
                    }   
                }}
    cout<<"LRU:"<<endl;
    cout<<"hit:"<<10-miss<<endl<<"miss:"<<miss<<endl;
    for(int i=memoryfilled-1;i>=0;i--){
        cout<<a[i]<<" ";}cout<<endl;
       
        return;}   

