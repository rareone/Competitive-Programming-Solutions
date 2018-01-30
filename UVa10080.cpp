#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include "limits.h"
#define f first
#define s second
#define MAXN 200
#define p 100003
#define FL(i,j,N) for(int i=j;i<N;++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;


ii gcd(ll a,ll b){
    if(!(a%b))return ii(0,1);
    ii d=gcd(b, a%b);
    return ii(d.s,d.f-a/b*d.s);
}
inline ll Inv(ll b){return (gcd(b,p).f+p)%p;}

ll M[MAXN][MAXN],I[MAXN][MAXN];//matrix, inverse

ll GE(int N){//O(n^3),return the rank of the matrix,if inverse exist then it's I;
    ll S[MAXN][MAXN];FL(i,0,N)FL(j,0,N)S[i][j]=M[i][j],I[i][j]=i==j;//define & copy
    FL(k,0,N){
        ll mul;
        int a=k;while(a<N && S[a][k]==0)++a;swap(S[k],S[a]);swap(I[k], I[a]);
        mul=Inv(S[k][k]);
        FL(i, 0, N)S[k][i]=S[k][i]*mul%p,I[k][i]=I[k][i]*mul%p;
        FL(i,0,N){//如果只做triangluar的話可以從k開始
            if(i==k)continue;
            mul=S[i][k]%p;
            FL(j, 0, N)
            S[i][j]=(p+S[i][j]-mul*S[k][j]%p)%p,I[i][j]=(p+I[i][j]-mul*I[k][j]%p)%p;
        }
    }
    ll m=0;FL(i,0,N)m+=S[i][i]==1;
    return m;
}

bool edge(double x,double y, double xx, double yy, int sp,int v){
    return (x-xx)*(x-xx)+(y-yy)*(y-yy)<=sp*v*sp*v;
}
double G[MAXN][2],H[MAXN][2];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,sp,v;
    while(cin>>n>>m>>sp>>v){
        FL(i, 0, n)cin>>G[i][0]>>G[i][1];
        FL(i, 0, m)cin>>H[i][0]>>H[i][1];
        FL(i, 0, n)FL(j, 0, m){
            M[i][n+j]=(edge(G[i][0],G[i][1],H[j][0],H[j][1],sp,v))?rand()%(p-1)+1:0;
            M[n+j][i]=(p-M[i][n+j])%p;
        }
        cout<<n-GE(n+m)/2<<'\n';
    }
}
