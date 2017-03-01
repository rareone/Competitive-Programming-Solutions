#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#define X real()
#define Y imag()
#define F first
#define S second
#define FL(i,j,k) for(int i=j;i<k;++i)

using namespace std;
const int N=50005;
const double eps=1e-8;

typedef complex<double> pt;
typedef pair<pt, pt> seg;

int n,polyn;
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
    return fabs(sum);
}

void HPXection()//半平面，點數，output凸包，凸包點數
{
    //sort(HP, HP+n, [=](seg a,seg b){return arg(a.S-a.F)<arg(b.S-b.F);});
    int l=0,r=0;
    deqHP[r++]=HP[0];
    deqHP[r++]=HP[1];
    deqP[r-2]=Xection(deqHP[r-1], deqHP[r-2]);
    FL(i,2,n){
        while (r-l>=2 && sign(XS(HP[i].S-HP[i].F, deqP[r-2]-HP[i].F))<0) --r;
        deqHP[r++]=HP[i];
        deqP[r-2]=Xection(deqHP[r-1], deqHP[r-2]);
    }
    while(r-l>=2){
        bool flag = 0;
        if(sign(XS(deqHP[r-1].S-deqHP[r-1].F, deqP[l]-deqHP[r-1].F)) <= 0)flag = 1,l++;
        if(sign(XS(deqHP[l  ].S-deqHP[l  ].F, deqP[r-2]-deqHP[l].F)) <= 0)flag = 1,r--;
        if(!flag) break;
    }
    deqP[r-1] = Xection(deqHP[l  ], deqHP[r-1]);
    FL(i, l, r)resultPoly[i-l]=deqP[i];
    polyn=r-l;
}

#define eat(n) int n;scanf("%d",&n);

int main(){
    while(~scanf("%d",&n)){
        FL(i, 0, n){
            eat(x)eat(y)
            P[i]=pt(x,y);
        }
        if(n==3||n==4){puts("1");continue;}
        int l=1,r=n-1,mid;
        while (l<r-1) {
            mid=(l+r)/2;
            FL(i, 0, n) HP[i]=seg(P[(i+1+mid)%n],P[i]);
            HPXection();
            if(area(resultPoly,polyn)<eps)r=mid;
            else l=mid;
        }
        printf("%d\n",r);
    }
}
