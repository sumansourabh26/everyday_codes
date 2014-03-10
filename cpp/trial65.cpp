
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
void handler(vector<int> card_drawn, vector<int>card,long long *total, int steps );
int main(){
    int count;
    cin>>count;

    for(int i = 0; i < count ; i++){
        int no_of_cards;
        cin>>no_of_cards;

        vector<int> card;
        int temp_card;
        for(int j = 0;j<no_of_cards; j++){
            cin>>temp_card;
            card.push_back(temp_card);
        }
        long long total=0;
        sort(card.begin(), card.end());
        cout<<"sorted\n";
        vector<int> card_drawn;
        int steps = 0;
        if(card[0]!= 0)
            cout<<0;
        else
            handler(card_drawn, card, &total, steps );

        cout<<total;

    }

}

void handler(vector<int> card_drawn, vector<int> card, long long *total, int steps){
    for(int j = 0; j<card_drawn.size();j++){
        cout<<card_drawn[j]<<" ";
    }cout<<endl;
    for(int j = 0; j<card.size();j++){
        cout<<card[j]<<" ";
    }cout<<endl;

    long long temp_total = *total;
    vector<int>::iterator itr;
    cout<<"total="<<temp_total<<endl;
    cout<<"card size="<<card.size()<<endl;
    if(card.size()==0){
            cout<<"total increased\n";
            *total = *total+1;
    }

    for(int i = 0; i<card.size();i++){
        if(steps>= card[i]){
            vector<int> clone_card_drawn=card_drawn, clone_card = card;
            clone_card_drawn.push_back(card[i]);
            clone_card.erase(clone_card.begin()+i);
            handler(clone_card_drawn, clone_card, total, steps+1);
        }
    }


}
