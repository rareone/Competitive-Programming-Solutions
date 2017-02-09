#include <bits/stdc++.h>
#define FL(i,j,k) for (int i=j;i<k;++i)
#define MAXN 100010
#define X real()
#define Y imag()
typedef int ll;
#define eat(a) ll a;scanf("%lld",&a)
using namespace std;
typedef complex<double> pt;
typedef vector<pt> poly;
pt A[1000];
int a1,b1,k;

inline bool cmp(pt a,pt b){
	return a.X*a1+a.Y*b1<b.X*a1+b.Y*b1;
}

int ori(pt a,pt b){
	return  a.X*b.Y-a.Y*b.X;
}
double cross(pt a,pt b){
	return ori(a,b);
}
inline pt intersection(pt p1,pt p2,pt p3,pt p4){
	return cross(p2-p1,p4-p1)/cross(p2-p1,p4-p3)*p3-cross(p2-p1,p3-p1)/cross(p2-p1,p4-p3)*p4;
}
inline area(vector<pt> &v){
	double x=0;
	FL(i,1,v.size()-1){
		x+=cross(v[i+1]-v[0],v[i]-v[0])/2;
	}
	return x;
}
int main(){
	eat(T);
	while(T--){
		poly convex;
		convex.push_back(pt(0,0));
		convex.push_back(pt(100,0));
		convex.push_back(pt(100,100));
		convex.push_back(pt(0,100));
		eat(N);eat(M);
		FL(i,0,N){
			eat(x);eat(y);
			A[i]=pt(x,y);
		}
		FL(i,0,M){
			scanf("%d %d %d",&a1,&b1,&k);
			if(k==N+1)continue;
			sort(A,A+N,cmp);
			pt con=A[k-1];
			double c=a1*con.X+b1*con.Y;
			poly newcon;int j=convex.size();
			FL(i,0,j){
				convex[i].X*a1+convex[i].Y*b1>=c;
				newcon.push_back(convex[i]);
				if((convex[i].X*a1+convex[i].Y*b1-c)*(convex[(i+1)%j].X*a1+convex[(i+1)%j].Y*b1-c)<0){
					newcon.push_back(intersection(convex[i],convex[(i+1)%j],pt(0,c/b1),pt(c/a1,0)));
				}
			}
			convex=newcon;
		}
		printf("%lf\n",area(convex));
	}
}
