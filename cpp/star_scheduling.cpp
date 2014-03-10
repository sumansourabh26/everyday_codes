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

void minimum(vector<movie>& sequence, string* answer,int i){
    if(sequence.size() == 1){
        cout<<(*answer)+sequence[0].name;
    }
    else if(sequence.size() == 0){
        cout<<(*answer);
    }
    else{
        cout<<sequence.size()<<endl;
        vector<movie>::iterator itr;
        vector<movie>::iterator minima;
        minima = sequence.begin();

        for(itr = sequence.begin();itr!= sequence.end(); itr++){
            if((*minima).ending > (*itr).ending){
                minima = itr;
            }
        }
        *answer = *answer + "\n"+(*minima).name;

        cout<<"minima : "<<minima->name<<endl;
        cout<<sequence.begin()->name<<endl;
        for(itr = sequence.begin();itr!= sequence.end();){
            if(((*minima).ending > (*itr).starting)
                && (*minima).name != (*itr).name){
                    sequence.erase(itr);
                    cout<<minima->name<<" not erased\n";
                    cout<<itr->name<<" erased\n";
            }
            else{
                itr++;
            }
        }
        sequence.erase(minima);
        minimum(sequence, answer, i+1);
    }
}

int main()
{
    vector<movie> sequence;
    sequence.push_back(movie("ihls ",3,20));
    sequence.push_back(movie("beyond the enemy lines ",2,5));
    sequence.push_back(movie("cocktail ",4,7));
    sequence.push_back(movie("transformer ",6,9));
    sequence.push_back(movie("21 ",8,11));
    sequence.push_back(movie("the beautiful mind ",10,13));
    sequence.push_back(movie("waali ",12,15));
    sequence.push_back(movie("ironman ",14,17));
    sequence.push_back(movie("catch me if u can ",16,18));

    string answer="";
    int i = 0;
    minimum(sequence, &answer, i);


}
