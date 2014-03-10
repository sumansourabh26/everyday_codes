#include<iostream>

using namespace std;

//template<class int>
struct my_list;
struct my_item;
bool find(my_item, int);
struct my_item{
    int item;
    my_item* next = NULL;

    my_item(int x){
        item = x;
    }
};

struct my_list{
    my_item* point_first;
    my_item* point_last = NULL;

    my_list(int x){
        point_first = new my_item(x);
        point_last = point_first ;
    }
    void push_back(int x){
        point_last->next = new my_item(x);
        point_last = point_last->next ;
    }
};

bool find(my_item *i, int x){
    if(i->item ==x){
        return true;
    }
    else if(i->next==NULL){
        return false;
    }
    else
        return find(i->next,x);
}

int main(){
    my_list a(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    cout<<find(a.point_first, 6);
}



