
#include<iostream>
#include<fstream>

using namespace std;
int getwhattheywant();
void displayitems(int x);

//main function
int main(){

    int whattheywant= getwhattheywant();
    while(whattheywant != 4){
            switch(whattheywant){
        case 1:
            displayitems(1);break;
        case 2:
            displayitems(2);break;
        case 3:
            displayitems(3);break;
        case 4:
            displayitems(4);break;

            }

        whattheywant = getwhattheywant();
    }
}

//getwhattheywant() function;
int getwhattheywant(){
     int whattheywant;
     cout<<"1- just for plain item\n"
         <<"2 - helpful items\n"
         <<"3 - harmful itmes"
         <<"4 - quit it\n";
     cin>>whattheywant;
     return whattheywant;
}

//displayitems function

void displayitems(int x){
    ifstream objectsfile("objects.txt");
    string name;
    double power;
    if(x==1){
        while(objectsfile>>name>>power){
            if (power==0){
                cout<<name<<' '<<power<<endl;
            }
        }
    }
    else if(x==2){
        while(objectsfile>>name>>power){
            if (power>0){
                cout<<name<<' '<<power<<endl;
            }
        }
    }
    else if(x==3){
        while(objectsfile>>name>>power){
            if (power<0){
                cout<<name<<' '<<power<<endl;
            }
        }
    }
}
