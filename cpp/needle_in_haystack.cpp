#include<iostream>

using namespace std;

void assign_s(string &pattern, int s[]){
    s[0]=0;
    int i = 1;
    int l = 0;
    for(; i<pattern.size();){
        l=i-1;
        while(true){
            if(pattern[s[l]]==pattern[i]){
                s[i]=s[l]+1;
                i++;
                break;
            }
            else{
                if(l==0){
                    s[i]=0;
                    i++;
                    break;
                }
                else{
                    l = s[l-1];
                }
            }
        }
    }
}

void assign_f(string &pattern,int s[], int f[]){
    f[0]=-1;
    int i = 1;
    int l = 0;
    for(; i<pattern.size();){
        l=s[i-1];
        while(true){
            if(pattern[l]!=pattern[i]){
                f[i]=l;
                i++;
                break;
            }
            else{
                if(l==0){
                    f[i]=-1;
                    i++;
                    break;
                }
                else{
                    l = s[l-1];
                }
            }
        }
    }
}

int main(){
    int size_of_pattern;string pattern1, text;
    while(cin>>size_of_pattern>>pattern1>>text){
        bool found = false;

        int s[size_of_pattern];
        int f[size_of_pattern];
        assign_s(pattern1, s);
        assign_f(pattern1, s, f);

        int p = 0;
        for(int st = 0; st < text.size();){
            if(pattern1[p]==text[st]){
                p++;
                st++;
                if(p==size_of_pattern){
                    if(pattern1[s[p-1]] == text[st]){
                        p = s[p-1];
                    }
                    else{
                        p = 0;
                    }
                    cout<<st-size_of_pattern<<endl;
                    found = true;
                }
            }
            else{
                if( f[p] == -1){
                    p = 0;
                    st++;
                }
                else{
                    p = f[p];
                }
            }
        }
        if(!found)cout<<"\n\n";
    }
}


