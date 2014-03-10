#include<iostream>
using namespace std;

int main(){
    int team1 = 0, team2 = 0;
    int w, b, r, totalw=0, totalb=0, totalr=0;
    int valwA, valbA, valwB, valbB;
    for(int i = 0; ; i++){
        char team;
        cin>>team;
        if(team=='#') break;
        cin>>w>>b>>r;
        totalw = totalw+w;
        totalr = totalr+r;
        totalb = totalb+b;
        if(i == 0){
            if(team=='A'||team=='C'){
                valwA=1;valbA=0;
                valwB=0;valbB=1;
            }
            else if(team=='B'||team=='D'){
                valwB=1;valbB=0;
                valwA=0;valbA=1;
            }
        }

        else if(team == 'A'||team=='C'){
            team1 = team1 + r*5 + w*valwB+ b*valbA;
        }
        else if(team == 'B'||team=='D'){
            team2 = team2 + r*5 + b*valbB+w*valwB;
        }
    }
    if((totalb<9 && totalw<9)||(totalr<1))
        cout<<"Incomplete game.\n";
    else if(team1>team2)
        cout<<"Team-1 win and the point is "<<team1<<".\n";
    else if(team2<team1)
        cout<<"Team-2 win and the point is "<<team2<<".\n";
}
