#include <iostream>
#include <cstdio>
#define elp 1e-8

struct Double{
    double d;
    inline Double(double b=0):d(b){}
    inline Double& operator=(const Double p){d=p.d;return *this;}
    inline Double operator+(const Double p){return p.d+d;}
    inline Double operator-(const Double p){return d-p.d;}
    inline Double operator*(const Double p){return p.d*d;}
    inline Double operator/(const Double p){return d/p.d;}
    inline int cmp(Double p){
        if(p.d-d<elp and p.d-d>-elp) return 0;
        else if(d-p.d>=elp) return 1;
        else return -1;
    }
    inline bool operator==(const Double p){return cmp(p)==0;}
    inline bool operator!=(const Double p){return !(cmp(p)==0);}
    inline bool operator< (const Double p){return cmp(p)==-1;}
    inline bool operator> (const Double p){return cmp(p)==1;}
    inline bool operator<=(const Double p){return cmp(p)==0||cmp(p)==-1;}
    inline bool operator+=(const Double p){return d+=p.d;}
    inline bool operator-=(const Double p){return d-=p.d;}
    inline bool operator-(){return -d;}
    inline bool operator!(){return !(-elp<d<elp);}
    inline Double operator[](const int a){return *(this+sizeof(double)*a);}
    inline operator double()const{return d;}
};


struct point;
inline Double cpt(point p1,point p2);
inline Double ipt(point p1,point p2);
struct point{
    Double p[2];
    inline point(){}
    inline point(Double _x,Double _y){p[0]=_x,p[1]=_y;}
    inline point operator+(point &m){return point(p[0]+m.p[0],p[1]+m.p[1]);}
    inline point operator-(point &m){return point(p[0]-m.p[0],p[1]-m.p[1]);}
    inline Double operator[](size_t i){return p[i];}
    inline bool operator==(point &m){return p[0]==m.p[0]&&p[1]==m.p[1];}
    inline bool operator!=(point &m){return !(*this==m);}
    inline friend point operator*(Double,point);
    inline bool ccw(point p1,point p2){//weakly countreclockwise
        point a=p1-*this;
        point b=p2-*this;
        double sa=cpt(a,b);//cast
        if(sa>0)return true;
        return false;
    }
};
inline Double cpt(point p1,point p2){//crossproduct
    return p1.p[0]*p2.p[1]-p1.p[1]*p2.p[0];
}
inline Double ipt(point p1,point p2){//innerproduct
    return p1.p[0]*p2.p[0]+p1.p[1]*p2.p[1];
}
inline point operator*(Double d,point &p){
    return point(d*p.p[0],d*p.p[1]);
}





#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<point > store;
vector<point > st;
point core;

inline bool cmp(point p1,point p2){
    return core.ccw(p1,p2);
}
int points;
void Input(){
    scanf("%d",&points);
    int key=0;
    for(int i=0;i<points;++i){
        int x,y;
        scanf("%d %d",&x,&y);
        if(key==0||(double)store[key].p[0]>x)key=i;
        store.push_back(point(x,y));
    }
    swap(store[key],store[0]);
    core=store[0];
    sort(store.begin()+1,store.end(),cmp);
}

void GrahamScan(){
    st.push_back(store[0]);
    st.push_back(store[1]);
    st.push_back(store[2]);
    for(int i=3;i<points;++i){
        while(!st[st.size()-2].ccw(st[st.size()-1], store[i])){
            st.pop_back();
        }
        st.push_back(store[i]);
    }
}

int countarea(){
    double sum=0;
    for(int i=1;i<st.size()-1;++i){
        sum+=(double)cpt(st[i]-core,st[i+1]-core)/2;
    }
    return sum/50;
}

int main(){
    Input();
    GrahamScan();
    printf("%d",countarea());
}