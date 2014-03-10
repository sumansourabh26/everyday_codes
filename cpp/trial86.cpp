#include<iostream>

using namespace std;

//template<class int>
struct my_list;
struct my_item;
bool find(my_item, int);
struct my_item{
    int item;
    my_list* next = NULL;
    my_item(int x){
        item = x;
    }
};

struct my_list{
    my_item* point_first;

    my_list(int x){
        point_first = new my_item(x);
    }
    void push_back(int x){
        point_first->next = new my_list(x);
    }
};


int main(){
    my_list a(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    cout<< a.point_first->next->point_first->item;
}



