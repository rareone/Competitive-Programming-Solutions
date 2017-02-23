#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#define X real()
#define Y imag()
#define F first
#define S second
#define eat(a) int a;scanf("%d",&a)
#define FL(i,j,k) for(int i=j;i<k;++i)

using namespace std;
const int N=1010;
const double eps=1e-8;

typedef complex<double> pt;
typedef pair<pt, pt> seg;

int n,polyn;//半平面數，多邊形頂點
pt P[N],resultPoly[N],deqP[N];
seg HP[N],deqHP[N];

int sign(double d){return d<-eps?-1:(d>eps);}
inline double XS(pt a,pt b){return a.X*b.Y-a.Y*b.X;}//叉積
inline pt Xection(seg a, seg b)//線段焦點
{
    double t=XS(a.S-a.F, b.S-b.F);
    return XS(a.S-a.F,b.S-a.F)/t*b.F-XS(a.S-a.F,b.F-a.F)/t*b.S;
}
double area(pt *poly,int n){
    if(n<=2)return 0;
    double sum=0;
    FL(i, 2, n)sum+=XS(poly[i-1]-poly[0], poly[i]-poly[0]);
    return fabs(sum)/2;
}

void HPXection()//半平面交集
{
    sort(HP, HP+n, [=](seg a,seg b){return arg(a.S-a.F)>arg(b.S-b.F);});
    int ne=0;
    FL(i, 0, n){
        if(ne!=i && fabs(arg(HP[i].S-HP[i].F)-arg(HP[ne].S-HP[ne].F))<eps){
            if(XS(HP[i].S-HP[i].F, HP[ne].S-HP[ne].F)>eps)
                HP[ne++]=HP[i];
        }else{
            HP[ne++]=HP[i];
        }
    }n=ne;
    int l=0,r=0;
    deqHP[r++]=HP[0];
    deqHP[r++]=HP[1];
    deqP[r-2]=Xection(deqHP[r-1], deqHP[r-2]);
    FL(i,2,n){
        while (r-l>=2 && sign(XS(HP[i].S-HP[i].F, deqP[r-2]-HP[i].F))<eps) --r;
        deqHP[r++]=HP[i];
        deqP[r-2]=Xection(deqHP[r-1], deqHP[r-2]);
    }
    while(r-l>=2){
        bool flag = 0;
        if(sign(XS(deqHP[r-1].S-deqHP[r-1].F, deqP[l]-deqHP[r-1].F)) < eps)flag = 1,l++;
        if(sign(XS(deqHP[l  ].S-deqHP[l  ].F, deqP[r-2]-deqHP[l].F)) < eps)flag = 1,r--;
        if(!flag) break;
    }
    deqP[r-1] = Xection(deqHP[l  ], deqHP[r-1]);
    FL(i, l, r)resultPoly[i-l]=deqP[i];
    polyn=r-l;
}

int main(){
    eat(T);
    while (T--) {
        eat(N);eat(M);
        FL(i, 0, N){
            eat(x);eat(y);
            P[i]=pt(x,y);
        }n=0;
        FL(i, 0, M){
            eat(a);eat(b);eat(k);
            if(k==N+1)continue;
            sort(P, P+N, [=](pt p1,pt p2){return p1.X*a+p1.Y*b>p2.X*a+p2.Y*b;});
            HP[n++]=seg(P[k-1],P[k-1]-pt(0,1)*pt(a,b));
        }
        HP[n++]=seg(pt(0,0),pt(100,0));
        HP[n++]=seg(pt(100,0),pt(100,100));
        HP[n++]=seg(pt(100,100),pt(0,100));
        HP[n++]=seg(pt(0,100),pt(0,0));
        HPXection();
        double a=area(resultPoly, polyn);
        printf("%.6lf\n",a/10000);
    }
}
