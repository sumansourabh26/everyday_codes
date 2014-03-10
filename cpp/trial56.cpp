#include<iostream>
#include<vector>
#include<string>
using namespace std;

class movie{
public:
    string name;
    int starting, ending;

    movie(string n, int s, int e){
        name=n;
        starting=s;
        ending=e;
    }
};

void minimum(vector<movie>& sequence, string* answer, int i ){
    if(sequence.size()==0){
        cout<<(*answer);
    }
    else{
        vector<movie>::iterator itr;
        vector<movie>::iterator minima;
        minima = sequence.begin();

        for(itr = sequence.begin();itr!= sequence.end(); itr++){
            if((*minima).ending > (*itr).ending){
                minima = itr;
            }
        }
        cout<<"minima this time "<<(*minima).name<<endl;
        *answer = *answer + (*minima).name;


        for(itr = sequence.begin();itr!= sequence.end(); itr++){
            if((*minima).ending > (*itr).starting
                && minima!= itr){
                sequence.erase(itr);
                cout<<(*minima).ending<<"  "<< (*itr).starting<<endl;
                cout<<(*itr).name<<"-deleted...\n";
            }
        }
        sequence.erase(minima);
         cout<<sequence.size()<<endl;
         cout<<(*answer)<<endl<<endl;
         minimum(sequence, answer, i+1);
    }
}

int main()
{
    vector<movie> sequence;
    sequence.push_back(movie("ihls ",1,3));
    sequence.push_back(movie("beyond the enemy lines ",2,5));
    sequence.push_back(movie("cocktail ",4,7));
    sequence.push_back(movie("transformer ",6,9));
    sequence.push_back(movie("21 ",8,11));
    sequence.push_back(movie("the beautyful mind ",10,13));
    sequence.push_back(movie("waali ",12,15));
    sequence.push_back(movie("ironman ",14,17));
    sequence.push_back(movie("catch me if u can ",16,18));

    string answer="";
    int i = 0;
    minimum(sequence, &answer, i);


}
