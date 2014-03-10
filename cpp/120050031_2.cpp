
#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;

class term;
// This is called forward declaration
// term is needed in defining boolean functions
// which is needed in defining terms.

class boolfunc;

unsigned int power[32]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,pow(2,13),pow(2,14)
                        ,pow(2,15),pow(2,16),pow(2,17),pow(2,18),pow(2,19),pow(2,20),pow(2,21)
                        ,pow(2,22),pow(2,23),pow(2,24),pow(2,25),pow(2,26),pow(2,27),pow(2,28)
                        ,pow(2,29),pow(2,30),pow(2,31)};
// Stores the powers of 2, needed for bit manipulation.
class term
{
	unsigned int l, nl; // l represents the +ve literals, nl the negative.
                    // the ith bit of l is 1 if variable i is present in
                    // the term in positive form. So l = 5, nl = 10,
	                  // represents the term  1 -2 3 -4.
	public:
	void read_term(){
        unsigned int length_of_term, temp_l=0,temp_nl=0;
        int a;
        cin>>length_of_term;
        for(int t = 0; t < length_of_term;t++){
            cin>>a;
            if(a>0){
                temp_l = temp_l|power[a-1];
            }
            if(a<0){
                temp_nl = temp_nl|power[-1-a];
            }
        }
        this->l=temp_l;
        this->nl = temp_nl;

	}
	void print_term(){
	    unsigned int l1 = l, nl1 = nl;
	    for(int i = 0; l1 > 0 || nl1 >0; i++){


	    }
	}
	bool is_zero(){
        return (l == nl);
	}; // checks whether a term is 0
	bool dominates(term const &t){
	    unsigned int l2 = t.l, nl2 = t.nl, l1 = l, nl1 = nl;
        for(int i = 0; l1>0 || nl1>0;i++){
            if((l1%2)==1 && (l2%2)==0)||(nl1%2)==1 && (nl2%2)==0){
                return false;
            }
            l1 = l1/2;l2=l2/2;
            nl1 = nl1/2;nl2=nl2/2;
        }
        return true;
	} // Checks whether a term is redundant
	bool operator()(unsigned int); // evaluates a term for specified value
	friend term operator&(term const &t1,term const &t2){
        unsigned int t1_l = t1.l, t1_nl=t1.nl, t2_l= t2.l,t2_nl = t2.nl;

        unsigned int temp_val;
        term temp_term;
        temp_val = ((t1_l|t2_l)&(t1_nl|t2_nl));
        if(temp_val==0){
            temp_term.l=0;
            temp_term.nl=0
            return temp_term;
        }
        else{
            temp_term.l=(t1_l|t2_l);
            temp_term.nl=t1_nl|t2_nl;
            return temp_term;
        }

	}
	friend bool operator<(term const &,term const &);
	friend boolfunc operator~(term const &t){
        boolfunc temp_f;
        term temp_term;
        unsigned int l1 = t.l,nl1 = t.nl;
        for(int i = 0; nl1>0 || l1>0:i++){
            if(l1%2==1){
                temp_term.l=0;
                temp_term.nl=power[i];
            }
            else if(nl1%2==0){
                temp_term.l=power[i];
                temp_term.nl=0;
            }
            l1 = l1/2; nl1 = nl1/2;
            temp_f.T.push_back(temp_term);
            return temp_f;
        }
	}
};


class boolfunc
{
    public:
	vector<term> T; // a boolean function is just a sequence of terms
	void reduce(){
    } // eliminates redundant terms and keeps them in sorted order

	void read_func(){
	    cout<<"enter no. of terms\n";
        int no_of_terms;
        for(int i = 0; i<no_of_terms; i++){

            term temp_term;
            temp_term.read_term();
            T.push_back(temp_term);
        }

    }
    void print_func(){
        cout<<T.size()<<endl;
        for(int i = 0; i<T.size();i++){
            T[i].print_term();
        }
    }
 	friend boolfunc operator&(boolfunc const &a,boolfunc const &b){
 	    boolfunc temp_f;
        for(int i = 0; i<a.T.size();i++){
            for(int j = 0; j<b.T.size();b++){
                temp_f.T.push_back( a.T[i] & a.T[j] );
            }
        }
        return temp_f;
 	}
	friend boolfunc operator|(boolfunc const &t1, boolfunc const &t2){
        boolfunc temp_f;
        temp_f.T = t1.T;
        temp_f.T.append(t2.T.begin(),t2.T.end());
	}
	friend boolfunc operator~(boolfunc const &f){
        boolfunc temp_f = ~f.T[0];

        for(int i = 1; i<f.T.size();i++){
            temp_f = temp_f & (~ f.T[i]);
        }
        return temp_f;

	}
	bool operator()(unsigned int num){
	    bool ans = true;
        int p[64];
        for(int i = 0; i<64; i++){
            p[i] = num%2;
            num = num / 2;
        }



	}
};


// Usually operators for a class are defined outside the class
// and declared as friends so that they can access private variables.
// You can also define them as member functions. The () operator
// must be a member function.




// The < operator is used to sort the terms. You can use the
// built in sort function available in the algorithms library.
// An easy way of implementing NOT operation is to apply NOT
// to each term to get a boolean function, and then AND all
// those functions. NOT for a term returns a function.
int main(){
    int no_of_input;
    cin>> no_of_input;

    for(int i = 0; i < no_of_input; i++){
        char opr;cin>>opr;
        if(opr=='&'||opr=='|'){
            boolfunc func1;
            func1.read_func();

        }
    }
}
