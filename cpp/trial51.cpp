#include<iostream>
#include<string>
using namespace std;

class date{
public:
    int day, month, year;
    date(int day,int month, int year){
        this->day=day;
        this->month=month;
        this->year= year;
    }
};

class birthday{
public:
    string name;
    date day1;
    birthday(string n,int d,int m, int y):name(n), day1(date(d,m,y)){}

    void print(){
        cout<<name<<" was born on "<<this->day1.day<<"/"<<this->day1.month<<"/"<<this->day1.year;
    }
};

int main(){
   // date d(8,3,1995);
    birthday d1("i", 8,3,1996);
    d1.print();
}
