#include<iostream>

using namespace std;

int main(){
    int no, lines;
    cin>>no>>lines;

    long long combination[no+1];
    combination[0]=0;
    combination[1]=0;
    combination[2]=1;

    for(int i = 3; i < no+1; i++){
        combination[i]= ((i)* combination[i-1])/(i-2);
    }

    int pop_of_country[no+1];
    int person[no];
    for(int i=0;i<no;i++){
        person[i]=0;
    }

    int country_unfilled = 1;
    int p1, p2;
    for(int i = 0; i < lines; i++){
        cin>>p1>>p2;
        if(person[p1]== 0 && person[p2]==0 ){
            person[p1]=country_unfilled;
            person[p2]=country_unfilled;
            pop_of_country[country_unfilled] = 2;
            country_unfilled++;
        }
        else if(person[p1] != 0 && person[p2]==0){
            person[p2]=person[p1];
            pop_of_country[person[p1]]++;
        }
        else if(person[p2] != 0 && person[p1] == 0){
            person[p1]=person[p2];
            pop_of_country[person[p2]]++;
        }

        else if(person[p2] != 0 && person[p1] != 0){
            if(person[p2]!=person[p1]){

                pop_of_country[person[p2]] = pop_of_country[person[p1]] + pop_of_country[person[p2]];
                pop_of_country[person[p1]]=0;
                for(int i = 0;i < no; i++){
                    if(person[i]==person[p1])
                        person[p1]=person[p2];
                }
            }
        }
    }
    long long ans = combination[no];
    for(int i = 1; i < country_unfilled; i++){
        ans = ans - combination[pop_of_country[i]];
    }
    cout<<ans;
}
