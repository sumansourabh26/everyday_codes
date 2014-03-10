#include<iostream>
#include<list>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;


struct point{
    double x,y;
    bool is_int , is_down, is_visited, on_line ;
    list<point>::iterator ptr;
};
list<point> polygon_points,intersections;

bool operator<(point const &a,point const &b){
    if(a.x < b.x)
		return true;
	else if(a.x > b.x)
		return false;
	else
		return(a.y<b.y);
}

struct polygon{
    list<point> points_of_this;
    int no_of_sides;

    void input(){
        cout<<"enter the points\n";
        point temp_point;
        cin>>no_of_sides;
        for(int i = 0; i < no_of_sides;i++){
            cin>>temp_point.x>>temp_point.y;
            temp_point.is_int = false;
            temp_point.is_down = false;
            temp_point.is_visited=false;
            temp_point.on_line=false;
            polygon_points.push_back(temp_point);
        }
        points_of_this.assign(polygon_points.begin(),polygon_points.end());
    }

    void print(){
        for(list<point>::iterator it;it!=points_of_this.end();it++){
            cout<<"("<<(*it).x<<","<<(*it).y<<"),";
        }
        cout<<endl;
    }

    int find_itersection(int a,int b,int c){
        double v1,v2,v3;
        list<point>::iterator itr = polygon_points.begin(), itr2 = polygon_points.begin(), itr3 = polygon_points.begin();
        itr2++;itr3++;itr3++;

        for(;itr != polygon_points.end();itr++,itr2++,itr3++){
            if((*itr).y ==1)
                break;
            v1 = a*((*itr).x) + b*((*itr).y) - c;
            cout<<"value for v1 ("<<(*itr).x<<","<<(*itr).y<<") is" <<v1<<endl;

            if(itr2==polygon_points.end()){
                itr2=polygon_points.begin();
                v2 = a*((*itr2).x) + b*((*itr2).y) - c;
            }
            else
                v2 = a*((*itr2).x) + b*((*itr2).y) - c;
            cout<<"value for v2 ("<<(*itr2).x<<","<<(*itr2).y<<") is" <<v2<<endl;

            if(itr3==polygon_points.end()){
                itr3=polygon_points.begin();
                v3 = a*((*itr3).x) + b*((*itr3).y) - c;
            }
            else
                v3 = a*((*itr3).x) + b*((*itr3).y) - c;
            cout<<"value for v3 ("<<(*itr3).x<<","<<(*itr3).y<<") is" <<v3<<endl;

            //to check if points are on line itself
            if(v1==0){(*itr).on_line=true;}
            else {(*itr).on_line=false;}
            if(v2==0){(*itr2).on_line=true;}
            else {(*itr2).on_line=false;}

            //to check if points are i on right or left
            if(a==0){
                if((*itr).y>c/b){
                    (*itr).is_down = false;
                }
                else if((*itr).y<c/b){
                    (*itr).is_down = true;
                }
                if((*itr2).y>c/b){
                    (*itr2).is_down = false;
                }
                else if((*itr2).y<c/b){
                    (*itr2).is_down = true;
                }
            }
            else if(b==0){
                if((*itr).x<c/a){
                    (*itr).is_down = false;
                }
                else if((*itr).x>c/a){
                    (*itr).is_down = true;
                }
                if((*itr2).x<c/a){
                    (*itr2).is_down = false;
                }
                else if((*itr2).x>c/a){
                    (*itr2).is_down = true;
                }
            }
            else{
                double slope = -a/b;
                if(slope>0){
                    if(a*v1 > 0){
                        (*itr).is_down = true;
                    }
                    else if(a*v1 < 0){
                        (*itr).is_down = false;
                    }
                }
                else if(slope<0){
                    if(a*v1 > 0){
                        (*itr).is_down = true;
                    }
                    else if(a*v1 < 0){
                        (*itr).is_down = false;
                    }
                }
                if(slope>0){
                    if(a*v2 > 0){
                        (*itr2).is_down = true;
                    }
                    else if(a*v2 < 0){
                        (*itr2).is_down = false;
                    }
                }
                else if(slope<0){
                    if(a*v2 > 0){
                        (*itr2).is_down = true;
                    }
                    else if(a*v2 < 0){
                        (*itr2).is_down = false;
                    }
                }
            }



            if(v1*v2 < 0){
                point intersection;
                double c1=((*itr).x)*((*itr2).y)-((*itr).y)*((*itr2).x);
                double a1=((*itr2).y - (*itr).y);
                double b1=((*itr).x - (*itr2).x);

                intersection.x =(c1*a - c*a1)/(b1*a - b*a1);
                intersection.y= (c1*b - c*b1)/(a1*b - a*b1);
				intersection.is_int = true;
                list<point>::iterator temp1 = polygon_points.insert(itr2,intersection);
                list<point>::iterator temp2 = intersections.insert(intersections.end(),intersection);
                cout<<"("<<intersection.x<<","<<intersection.y<<") point being inserted\n";
                (*temp1).ptr = temp2;
                (*temp2).ptr = temp1;
                itr++;

            }

            intersections.sort();
            list<point>::iterator it = polygon_points.begin();
            cout<<"final polygon points:";
            for(;it!=polygon_points.end();it++){
                cout<<"("<<(*it).x<<","<<(*it).y<<"),";
            }cout<<endl;
            it = intersections.begin();
            for(;it!=intersections.end();it++){
                cout<<"("<<(*it).x<<","<<(*it).y<<"),";
            }cout<<endl;

            if(itr==polygon_points.end())
                break;
        }
    }
};


int main(){
    cout<<"its";
    polygon my_polygon;
    my_polygon.input();
    double line_a,line_b,line_c;
    cin>>line_a>>line_b>>line_c;
    cout<<"line assignment done\n";
    my_polygon.find_itersection(line_a,line_b,line_c);
    cout<<"point assignment done\n*********************";

}


