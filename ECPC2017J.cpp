#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define MAXN 500000
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vi;//road weight,vertice
//超爽得，終於寫出來了
#define FL(i,j,k) for(int i=j;i<k;++i)
vi g[MAXN];
ll T,N,u,v,w,d[MAXN],c[MAXN],X[MAXN],mark[MAXN],ans[MAXN];
bool vis[MAXN];
void dis(ll v=0,ll p=-1){
    for(ii pai: g[v]){
        ll w=pai.first,e=pai.second;
        if(e!=p){
            d[e]=d[v]+w;
            c[e]=d[e]-X[e];
            dis(e,v);
        }
    }
}
vi path;ll sum=0;
void dfs(ll v=0,ll p=-1,ll h=0){
    ll sta=sum;
    path.push_back(ii(d[v],v));
    for(ii pai: g[v]){
        ll e=pai.second;
        if(e!=p){
            mark[h+1]=0;
            dfs(e,v,h+1);
        }
    }
    sum-=mark[h];
    ans[v]=sum-sta;
    auto it=lower_bound(path.begin(), path.end(),ii(c[v],0),[=](ii a,ii b){return a.first<b.first;});
    ++mark[it-1-path.begin()],++sum;
    path.pop_back();
}

int main(){
    //freopen("car.in", "r", stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    FL(t, 0, T){
        cin>>N;path.clear();sum=0;
        FL(i, 0, N){
            cin>>X[i],g[i].clear();
            c[i]=ans[i]=mark[i]=0;
        }
        FL(i, 0, N-1){
            cin>>u>>v>>w;--u,--v;
            g[u].push_back(ii(w,v));
            g[v].push_back(ii(w,u));
        }
        d[0]=0,c[0]=d[0]-X[0];
        dis(),dfs();
        FL(i, 0, N)cout<<ans[i]<<' ';
        cout<<'\n';
    }
    
}
