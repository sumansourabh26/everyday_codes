#include<iostream>
#include<vector>

using namespace std;

//template<class st>

class perm{
public:
    int count_now;
    vector<int> data;
    vector<int> inv_data;
    bool id=true;
    bool inv=true;

    perm(int size_of_data){
        inv_data.resize(size_of_data);
        data.resize(size_of_data);
        for(int i = 0; i<size_of_data;i++){
            data[i]=-1;inv_data[i]=-1;
        }
        count_now=0;
    }

    void my_push_back(int x){
        inv_data[x]=count_now;
        data[count_now]=x;
        if(id && x!=count_now){
            id=false;
        }
        if(inv && (data[x]!=count_now && p[x]!=-1){
            inv=false;
        }
        count_now++;

    }
    void swap(int x, int y){
        int dummy1 = data[x];
        int dummy2 = data[y];
        data[y] dummy1;
        data[x] dummy2;
        inv_data[dummy1]=y;
        inv_data[dummy2]=x;

    }
    bool identity(){
        return id;
    }

    bool involution(){
        return inv;
    }
};

int main(){
    int size_of_data;
    cin>>size_of_data;
    perm element(size_of_data);


}
