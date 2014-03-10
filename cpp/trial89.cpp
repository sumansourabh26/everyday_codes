#include<iostream>
#include<list>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;


class point{
public:
    double x,y;
    bool isint = false, is_right=false, is_visited = false;
    list<point>::iterator ptr;
    bool operator<(point a){
        return x<a.x;
    }

};
list<point> polygon_points,intersections;

bool sorting(point a, point b){
    return a.x<b.x;
}
class polygon{
public:
    list<point> points_of_this;
    int no_of_sides;
    void input(){
        point temp_point;
        cin>>no_of_sides;
        for(int i = 0; i < no_of_sides;i++){
            cin>>temp_point.x>>temp_point.y;
            polygon_points.push_back(temp_point);
        }
        points_of_this.assign(polygon_points.begin(),polygon_points.end());
    }


    void find_itersection(int a,int b,int c){
        double v1,v2;
        list<point>::iterator itr = polygon_points.begin(), itr2 = polygon_points.begin();
        itr2++;

        for(;itr != polygon_points.end();itr++,itr2++){
            double v1 = a*((*itr).x) + b*((*itr).y) - c;
            if(itr2==polygon_points.end()){
                double v1 = a*((*(polygon_points.begin())).x) + b*((*(polygon_points.begin())).y) - c;
            }
            else
                double v1 = a*((*itr2).x) + b*((*itr2).y) - c;
            if(v1>0)
                (*itr).is_right = true;
            if(v2>0)
                (*itr2).is_right = true;

            if(v1*v2 < 0){
                point intersection;
                intersection.x = ((c/b)-((((*itr2).x)*((*itr).y) -((*itr).x)*((*itr2).y))/(((*itr).x)-((*itr2).y))))/(((((*itr2).y)-((*itr).y))/((*itr2).x)-((*itr).x))+a/b);
                intersection.y= (c-a* (intersection.x))/b;

                list<point>::iterator temp1 = polygon_points.insert(itr2,intersection);
                list<point>::iterator temp2 = intersections.insert(intersections.end(),intersection);

                (*temp1).ptr = temp2;
                (*temp2).ptr = temp1;

            }
        }
        intersections.sort();
    }
};
int main(){
    polygon my_polygon;
    my_polygon.input();
    double line_a,line_b,line_c;
    cin>>line_a>>line_b>>line_c;
    my_polygon.find_itersection(line_a,line_b,line_c);

    list<point>::iterator itr = polygon_points.begin();

    for(;!polygon_points.empty();){
        polygon temp_polygon;
        list<point>::iterator temp_itr = itr;
        for(; ;temp_itr++){
            if((*temp_itr).isint)
        }
    }
}
