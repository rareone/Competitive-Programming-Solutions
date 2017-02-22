#include <bits/stdc++.h>
//#include "bits:stdc++.h"
#define X real()
#define Y imag()
#define eat(a) int a;scanf("%d",&a)
#define FL(i,j,k) for(int i=j;i<k;++i)


using namespace std;
typedef complex<double> pt;

const int N=30100;
pt P[N];

int main(){
    eat(T);
    while (T--) {
        eat(n);
        FL(i, 0, n){
            eat(x);eat(y);
            P[i]=pt(x,y);
        }
        sort(P, P+n,[=](pt a,pt b){return b.X<a.X;});
        int maxY=0;
        double sum=0;
        FL(i, 0, n){
            if(P[i].Y<=maxY)continue;
            double k=(P[i].Y-P[i-1].Y)/(P[i].X-P[i-1].X),x=(P[i].Y-maxY)/k;
            sum+=sqrt(x*x+(P[i].Y-maxY)*(P[i].Y-maxY));
            maxY=P[i].Y;
        }
        printf("%.2lf\n",sum);
    }
}
