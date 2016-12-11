#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define MAXN 100
#define F first
#define S second
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > ii;
vector<ll> T[MAXN];
ll p[MAXN],r[MAXN],n,testcase,m,u,v,w;
ll parent(ll i){
    if(p[i]==i)return i;
    else return p[i]=parent(p[i]);
}
inline void UN(ll a,ll b){
    ll A=parent(a),B=parent(b);
    if(A==B) return;
    if(r[A]<r[B])p[A]=p[B];
    else r[A]+=r[A]==r[B],p[B]=p[A];
}
pair<ll, ii> Elist[MAXN*MAXN];
bool istree[MAXN*MAXN];

ll dp[MAXN][MAXN],cur[MAXN+10],lar[MAXN+10];
priority_queue<ll> pq;
void dfs(ll r,ll i,ll h=0,ll p=-1){
    FL(t,0,T[i].size()){
        ll e=T[i][t],next=Elist[e].S.S==i?Elist[e].S.F:Elist[e].S.S;
        if(next==p)continue;
        cur[h]=Elist[e].F,lar[h]=h==0?cur[h]:max(lar[h-1],cur[h]);
        dfs(r,next,h+1,i);
    }
    dp[r][i]=dp[i][r]=h==0?0:lar[h-1];
}


int main(){
    scanf("%lld",&testcase);
    while (testcase--) {
        scanf("%lld%lld",&n,&m);
        FL(i, 0, n)T[i].clear();
        FL(i, 0, m){
            scanf("%lld%lld%lld",&u,&v,&w);--u,--v;
            Elist[i]=pair<ll, ii>(w,ii(u,v));
            istree[i]=0;
        }
        sort(Elist, Elist+m);
        FL(i, 0, n)p[i]=i,r[i]=0;
        ll sum=0,sec=100000000;
        FL(i, 0, m){
            if(parent(Elist[i].S.F)!=parent(Elist[i].S.S)){
                UN(Elist[i].S.F, Elist[i].S.S);
                sum+=Elist[i].F;
                T[Elist[i].S.F].push_back(i);
                T[Elist[i].S.S].push_back(i);
                istree[i]=1;
            }
        }
        FL(i, 0, n){
            dfs(i,i);
        }
        FL(i, 0, m){
            if(istree[i])continue;
            sec=min(sum+Elist[i].F-dp[Elist[i].S.S][Elist[i].S.F],sec);
        }
        printf("%lld %lld\n",sum,sec);
    }
}
