#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

struct account{
    public:
    long long acc_no;
    int balance;
    account(long long acc_no, int balance){
        this->acc_no= acc_no;
        this->balance= balance;
    }
};

struct compare_bal{
    bool operator()(account x, account y){
        if(x.balance<y.balance){
            return true;
        }
        else if(x.balance > y.balance){
            return false;
        }
        else{
            if(x.acc_no < y.acc_no){
                return true;
            }
            else
                return false;
        }
    }
};


int main(){
    map<long long, int> no_map;
    set<account,compare_bal> bal_set;

    char command;
    long long acc;
    int transaction;

    while(true){
        cin>>command;
        if(command=='T'){
            cin>>acc;
            cin>>transaction;

            account dummy(acc,no_map[acc]);
            bal_set.erase(dummy);
            no_map[acc] = transaction + no_map[acc];
            if(no_map[acc]!=0){
                account dummy2(acc,no_map[acc]);
                bal_set.insert(dummy2);
            }
            cout<<"balance of "<<acc<<' '<<no_map[acc]<<endl;
        }
        else if(command=='Q'){
            cin>>acc;
            cout<<acc<<' '<<no_map[acc]<<endl;
        }
        else if(command=='L'){
            cin>>transaction;
            set<account,compare_bal>::iterator itr = bal_set.begin();

            vector<long long> to_print;
            for(; itr!=bal_set.end() && (*itr).balance <= transaction; itr++ ){
                to_print.push_back((*itr).acc_no);
            }
            sort(to_print.begin(),to_print.end());
            vector<long long>::iterator it = to_print.begin();
            for(; it!= to_print.end(); it++){
                cout<<*it<<' ';
            }
            cout<<endl;
        }
        else if(command=='e'){
            break;
        }

    }

//    set<account,compare_bal>::iterator itr = bal_set.begin();
//    cout<<"printing bal_set\n";
//    for(; itr != bal_set.end(); itr++){
//        cout<< (*itr).acc_no<<' '<<(*itr).balance<<endl;
//    }
//    cout<<"done bal_set\n";

}










