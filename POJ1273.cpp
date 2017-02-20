#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAXN 200
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef long long int ll;
vector<ll> g[MAXN];
vector<ll> f[MAXN];
ll M,N,u,v,c,d[MAXN];
ll Es[400],Ee[400],Ec[400],Ef[400],Er[400];

inline bool bfs(ll s,ll t){
    FL(i, 0, N)d[i]=-1;
    queue<ll> q;d[s]=0;q.push(s);
    while (!q.empty()) {
        ll s=q.front();q.pop();
        FL(i, 0, g[s].size()){
            ll e=g[s][i];
            if(!Er[e])continue;
            if(d[Ee[e]]==-1){
                q.push(Ee[e]);
                d[Ee[e]]=d[s]+1;
            }
        }
    }
    return d[t]!=-1;
}
inline ll dfs(ll u,ll t,ll cur_flow=1e18){
    if(u==t||!cur_flow)return cur_flow;
    ll df=0,tf=0;
    FL(i, 0,g[u].size()){
        ll e=g[u][i],to=Ee[e];
        if( d[to]==d[u]+1 && Er[e] ){
            if((df=dfs(to, t,min(cur_flow, Er[e])))){
                Ef[e]+=df,Ef[e^1]-=df,Er[e]-=df,Er[e^1]+=df;
                tf+=df;
                if(!(cur_flow-=df))break;
            }
        }
    }
    if(!df)d[u]=0;
    return tf;
}
inline ll Dinic(ll s,ll t){
    ll sum=0;
    while(bfs(s, t))
        sum+=dfs(s, t);
    return sum;
}


int main(){
    while(~scanf("%lld%lld",&M,&N)){
        FL(i, 0, N)g[i].clear();
        FL(i, 0, M){
            scanf("%lld %lld %lld",&u,&v,&c);
            --u,--v;
            Es[i<<1]=Ee[i<<1^1]=u;
            Ee[i<<1]=Es[i<<1^1]=v;
            Er[i<<1]=Ec[i<<1]=c;
            Ef[i<<1]=Ef[i<<1^1]=Er[i<<1^1]=Ec[i<<1^1]=0;
            g[u].push_back(i<<1);
            g[v].push_back(i<<1^1);
        }
        printf("%lld\n",Dinic(0, N-1));
    }
}
