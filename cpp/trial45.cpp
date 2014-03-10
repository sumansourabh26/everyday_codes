#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    vector<string> sentance;
    string init; cout<<"enter the sentance here";
    //getline(cin,init);
    init = "its me";
    string word = "";
    string letter;
    letter = init.at(0);
    for( int i = 0 ; i< init.size() ;i++  )
    {
        cout<<init[0];
        if(letter == " ") {
                sentance.push_back(word);
                letter = init[i+1];
                word="";
        }
        else
        {
            word.push_back(letter);
            letter = init[i+1];

        }
    }
    for(int i = sentance.size()-1; i >= 0; i--)
    {
        cout<<sentance[i];
    }

}
