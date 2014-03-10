#include<iostream>
#include<list>
#include<utility>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;


struct point{
    double x,y,value;
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
        //cout<<"enter the points\n";
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
        //cout<<points_of_this.size()<<endl;
        for(list<point>::iterator it=points_of_this.begin();it!=points_of_this.end();it++){
            //cout<<"("<<(*it).x<<","<<(*it).y<<"),";
        }
        //cout<<endl;
    }

    void find_itersection(double a,double b,double c){
        //assigning the sides
        list<point>::iterator itr = polygon_points.begin();
        for(;itr!=polygon_points.end();itr++){
            (*itr).value = ((*itr).x)*a + b*((*itr).y) -c;
            if( (*itr).value == 0){
                (*itr).on_line = true;
            }
            if(a==0){
                if((*itr).y<c/b){
                    (*itr).is_down = true;
                    //cout<<"value true\n";
                }
            }
            else if(b==0){
                if((*itr).x>c/a){
                    (*itr).is_down = true;
                    //cout<<"value true\n";
                }
            }
            else{
                double slope = -a/b;
                if(slope>0){
                    if(a*((*itr).value) > 0){
                        (*itr).is_down = true;
                        //cout<<"value true\n";
                    }
                }
                else if(slope<0){
                    if(a*((*itr).value) > 0){
                        (*itr).is_down = true;
                        //cout<<"value true\n";
                    }
                }
            }
        }

        double v1,v2,v3;
        itr = polygon_points.begin();
        list<point>::iterator itr2 = polygon_points.begin(), itr3 = polygon_points.begin();
        itr2++;itr3++;itr3++;

        for(;itr != polygon_points.end();itr++,itr2++,itr3++){
            v1 = (*itr).value;
            //cout<<"value for v1 ("<<(*itr).x<<","<<(*itr).y<<") is" <<v1<<endl;

            if(itr2==polygon_points.end()){
                itr2=polygon_points.begin();
            }
            v2 = (*itr2).value;
            //cout<<"value for v2 ("<<(*itr2).x<<","<<(*itr2).y<<") is" <<v2<<endl;

            if(itr3==polygon_points.end()){
                itr3=polygon_points.begin();
            }
            v3 = (*itr3).value;
            //cout<<"value for v3 ("<<(*itr3).x<<","<<(*itr3).y<<") is" <<v3<<endl;

            if(v1*v2 < 0){
                point intersection;
                double c1=((*itr).x)*((*itr2).y)-((*itr).y)*((*itr2).x);
                double a1=((*itr2).y - (*itr).y);
                double b1=((*itr).x - (*itr2).x);

                intersection.y =(c1*a - c*a1)/(b1*a - b*a1);
                intersection.x= (c1*b - c*b1)/(a1*b - a*b1);
				intersection.is_int = true;
				intersection.is_visited = false;
				intersection.is_down=false;
                list<point>::iterator temp1 = polygon_points.insert(itr2,intersection);
                list<point>::iterator temp2 = intersections.insert(intersections.end(),intersection);
                //cout<<"("<<intersection.x<<","<<intersection.y<<") point being inserted\n";
                (*temp1).ptr = temp2;
                (*temp2).ptr = temp1;
                itr++;

            }
            /*list<point>::iterator it = polygon_points.begin();
            cout<<"final polygon points:";
            for(;it!=polygon_points.end();it++){
                cout<<"("<<(*it).x<<","<<(*it).y<<"),";
            }cout<<endl;
            it = intersections.begin();
            for(;it!=intersections.end();it++){
                cout<<"("<<(*it).x<<","<<(*it).y<<"),";
            }cout<<endl;*/

            if(itr==polygon_points.end())
                break;
        }
        intersections.sort();
    }
};
bool operator<(polygon p1, polygon p2){
    if(((p1.points_of_this.front()).x)<((p2.points_of_this.front()).x))
        return true;
    else return
        (((p1.points_of_this.front()).y)<((p2.points_of_this.front()).y));
}

int main(){
    polygon my_polygon;
    my_polygon.input();
    double line_a,line_b,line_c;
    cin>>line_a>>line_b>>line_c;
    //cout<<"line assignment done\n";
    my_polygon.find_itersection(line_a,line_b,line_c);
    //cout<<"point assignment done\n*********************\n";

    list<polygon> answer;
    polygon temp_poly;
    list<point>::iterator itr_copy=polygon_points.begin(),itr=polygon_points.begin(), last_one = polygon_points.end(),waste;
    last_one--;
    int point_counted = 0,polygon_count=0, range = polygon_points.size()-intersections.size();

    while(point_counted<range){
        polygon_count++;
        //cout<<"entered first loop\n";

        while((*itr).is_int || ((*itr).is_visited &&((*itr).is_visited))) {
            if(itr == last_one){
                itr=polygon_points.begin();
            }
            else itr++;
        }
        itr_copy = itr;
        temp_poly.points_of_this.push_back(*itr_copy);
        (*itr_copy).is_visited = true;
        itr_copy++;
        point_counted++;

        while(itr!=itr_copy){
            //cout<<(*itr).x<<","<<(*itr).y<<" and "<<(*itr_copy).x<<","<<(*itr_copy).y<<endl;
            //cout<<"entered second loop\n";

            if((*itr_copy).is_int){
                //temp_poly.points_of_this.push_back(*itr_copy);

                point p1 = temp_poly.points_of_this.back();
                waste = (*itr_copy).ptr;
                temp_poly.points_of_this.push_back(*itr_copy);
                //cout<<"("<<(*itr_copy).x<<','<<(*itr_copy).y<<"),joined\n";
                if(p1.is_down) waste++;
                else waste--;

                point p2 = *waste;
                temp_poly.points_of_this.push_back(p2);
                //cout<<"("<<p2.x<<','<<p2.y<<"),joined\n";
                itr_copy=p2.ptr;
            }

            else {
                //cout<<"("<<(*itr_copy).x<<','<<(*itr_copy).y<<"), joined\n";
                (*itr_copy).is_visited = true;
                temp_poly.points_of_this.push_back(*itr_copy);
                //cout<<"("<<(*itr_copy).x<<','<<(*itr_copy).y<<"), joined\n ";
                point_counted=point_counted+1;
            }
            if(itr_copy==last_one)
                itr_copy=polygon_points.begin();
            else itr_copy++;
        }
        //temp_poly.points_of_this.sort();
        answer.push_back(temp_poly);
        temp_poly.points_of_this.clear();
        itr++;
        //cout<<endl<<answer.size()<< point_counted<<endl;
    }
    answer.sort();
    cout<<answer.size()<<endl;
    for(list<polygon>::iterator i1 = answer.begin(); i1 != answer.end();i1++ ){
        polygon p = *i1;
        list<point>::iterator l2, l =min_element(p.points_of_this.begin(),p.points_of_this.end());
        cout<<p.points_of_this.size()<<endl;
        cout<<(*l).x<<" "<<(*l).y<<' ';
        l2 = l;l++;

        for(;l!=l2;){
            cout<<(*l).x<<" "<<(*l).y<<' ';
            if(l==p.points_of_this.end()--)
                l = p.points_of_this.begin();
            else l++;

        }
        cout<<endl;
    }
}
