// The code is yet completed
// Including the algorithm of finding the intersection of two polygon in O(n) time
// Although I can use half-plane intersection algorithm


#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#define r real()
#define i imag()
#define PI 3.14159265358979363846251
typedef std::complex<double> P;
typedef std::vector<P> Poly;
struct Line{
    P p;// point
    P l;//vector
    Line(double x,double y,double p1,double p2):p(P(x,y)),l(P(p1,p2)){}
    Line(P _p,P _l):p(_p),l(_l){};
    Line(){}
};
typedef std::vector<Line> VL;
int n;
Poly prob;

double cross(P p1,P p2){
    return p1.r*p2.i-p1.i*p2.r;
}
inline P intersectionpoint(Line L1,Line L2){
    P s=L2.p-L1.p;
    return L1.p+L1.l*cross(L2.l,s)/cross(L2.l,L1.l);
}

inline VL IS(VL Li){
    VL q;q.clear();
    if(Li.size()==1){//INF half plane
        Line LLL(Li[0].p+1e8*Li[0].l/abs(Li[0].l),P(0,1)*1e8*Li[0].l/abs(Li[0].l));
        q.push_back(LLL);
        LLL.p+=LLL.l,LLL.l=P(0,2)*LLL.l;
        q.push_back(LLL);
        LLL.p+=LLL.l,LLL.l=P(0,0.5)*LLL.l;
        q.push_back(LLL);
        LLL.p+=LLL.l,LLL.l=q[0].p-LLL.p;
        q.push_back(LLL);
        return q;
    }
    VL left=IS(VL(Li.begin(),Li.begin()+Li.size()/2));
    VL right=IS(VL(Li.begin()+Li.size()/2+1,Li.end()));
    if(left.size()==0||right.size()==0)return q;
    
    
    
    
    //combine the two polygon
    
    
    
    
    
    return q;
}
inline bool check(int siz){
    std::vector<Line> L;
    /*
    L.push_back(Line(-1e9,1e9,0,-1e9));
    L.push_back(Line(-1e9,-1e9,1e9,0));
    L.push_back(Line(1e9,-1e9,0,1e9));
    L.push_back(Line(1e9,1e9,-1e9,0));
    */
    for(int j=0;j<n;++j){
        Line l;
        l.p=prob[j];
        l.l=prob[(j+siz)%n]-l.p;
        L.push_back(l);
    }
    if(IS(L).empty())return true;
    return false;
}

int lgfind(int but,int top){
    if(but==top)return but;
    if(check((but+top)/2)){
        return lgfind(but, (but+top)/2);
    }
    else{
        return lgfind((but+top)/2-1,top);
    }
}

int main(){
    while(~scanf("%d",&n)){
        int sx,sy;
        prob.clear();
        for(int k=0;k<n;++k){
            scanf("%d%d",&sx,&sy);
            prob.push_back(P(sx,sy));
        }
        if(n==3){
            printf("1");continue;
        }
        printf("%d",lgfind(1, n-3));
    }
}