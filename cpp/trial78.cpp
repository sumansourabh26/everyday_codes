
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
void handler(vector<int> card_drawn, vector<int>card,long long *total, long steps );
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
        sort(card.begin(), card.end(),[](double x,double y){x<y;});

        vector<int> card_drawn;
        long steps = 0;
        if(card[0]!= 0)
            cout<<0;
        else
            handler(card_drawn, card, &total, steps );

        cout<<total<<endl;
    }
}

void handler(vector<int> card_drawn, vector<int> card, long long *total, long steps){
    long long temp_total = *total;
    vector<int>::iterator itr;
    if(card.size()==0){
            *total = (*total+1)%1000000007;
    }
    for(int i = 0; i<card.size();i++){
        if(steps>= card[i]){
            vector<int> clone_card_drawn=card_drawn, clone_card = card;
            clone_card_drawn.push_back(card[i]);
            clone_card.erase(clone_card.begin()+i);
            handler(clone_card_drawn, clone_card, total, steps+1);
        }
        else
            break;
    }
}
