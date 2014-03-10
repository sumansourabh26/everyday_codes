#include<iostream>
#include<list>
#include<utility>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
struct point{
    float x;
    float y;
    bool intr;
    bool mark=false;
    list<point> :: iterator itr;
    };
     bool operator<(point p1,point p2){
        if(p1.x<p2.x)return true;
        if(p1.x == p2.x && p1.y<p2.y)return true;
        return false;}
//list<point> intrsc;
struct polygen{
    int vert;
    list<point> l,l1;
    list<point> intrsc;
    list<point> :: iterator intr_itr;
    void read(){
        point dummy;
        cin>>vert;
        for(int i=0;i<vert;i++){
            cin>>dummy.x;
            cin>>dummy.y;
            dummy.intr=false;
            l.push_back(dummy);
        }
    }
    void assgn(float a,float b,float c){
        float val1,val2;
        point ans;
        list<point>::iterator i,j,k,p2;
        i=l.begin();
        j=l.begin();
        k=l.end();
        k--;
        j++;
        for(;i!=l.end();i++,j++){
                point d1,d2;
                d1=*i;
                l1.push_back(d1);
               //cout<<d1.x<<"t"<<d1.y<<"t";
            val1=a*(d1.x)+b*(d1.y)-c;
            if(i == k){
                    j=l.begin();
                    d2=*j;
            val2=a*(l.front().x)+b*(l.front().y)-c;
            }
            else{
                    d2=*j;
                val2=a*(d2.x)+b*(d2.y)-c;
            }
            cout<<val1<<"m";
            cout<<val2<<"m";
            if(val1*val2 < 0){
                    int c1=(d1.x)*(d2.y)-(d1.y)*(d2.x);
                    int a1=(d2.y - d1.y);
                    int b1=(d1.x - d2.x);
                ans.y=(c1*a - c*a1)/(b1*a - b*a1);
                ans.x=(c1*b - c*b1)/(a1*b - a*b1);
                cout<<ans.x<<"p";
                cout<<ans.y<<"p";
                ans.intr=true;
                intrsc.push_back(ans);
                if(intrsc.size() == 1) intr_itr=intrsc.begin();
                else intr_itr++;
                ans.itr=intr_itr;
                list<point> ::iterator dum,d1;
                dum=intrsc.end();
                dum--;
                point p3=*dum;
                l1.insert(j,ans);
                d1=j;
                d1--;
                p3.itr=d1;
                }
            }
            intrsc.sort();
            p2=intrsc.begin();
            find(a,b,c);
            //cout<<"n"<<l1.size()<<"n"<<p2->x<<" "<<p2->y<<" ";
        }
        void find_poly(a,b,c){
            list<point> ans;
            int sz=0;
            bool found1=false,found2=false;
            list<point> ::iterator curnt;
            curnt=l1.begin();
            if(!curnt->intr){
                ans.push_back(*curnt);
                curnt->mark=true;
            }
            else {
                curnt++;
                ans.push_back(*curnt);
            }
            while((!curnt->mark) && (*curnt != ans.front())){
                if(curnt->intr){
                        ans.push_back
                        list<point> :: iterator dummy=curnt->itr;
                        dummy--;
                        point p4=*dummy;
                        ans.push_back(p4);
                        curnt=p4.itr;
                }
                else {
                    curnt->mark=true;
                    ans.push_back(*curnt);
                    curnt++;
                }
            }
            }
};

int main(){
    polygen p;
    p.read();
    float a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    p.assgn(a,b,c);
    //cout<<intrsc.size()<<intrsc.front().x;
}
