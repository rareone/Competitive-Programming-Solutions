#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <utility>
#define MAXN 10000
#define FL(i,j,k) for(ll i=j;i<k;++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;


ll vertice,edge,u,v,w;



vector<ii> g[MAXN]={}; // weight vertice

ll d[MAXN]={0};
inline void Dijsktra(){
    FL(i, 1, vertice) d[i]=9223372036854775807LL;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push(ii(0,0));d[0]=0;
    while (!pq.empty()) {
        ll front=pq.top().second,dis=pq.top().first; pq.pop();
        if(dis>d[front])continue;
        for(ii s : g[front]){
            ll p=s.second,w=s.first;
            if(d[p]>d[front]+w){
                d[p]=d[front]+w;
                pq.push(s);
            }
        }
    }
}

ll dp[MAXN]={0};
inline ll findpath(ll s){
    if(s==0)return dp[s];
    else if (dp[s])return dp[s];
    else{
        ll sum=0;
        for(ii E:g[s]){
            if(E.first==d[s]-d[E.second])sum+=E.first;
        }sort(g[s].begin(), g[s].end(),[=](ii a, ii b){return a.second<b.second;});
        FL(i, 0, g[s].size()){
            ii E=g[s][i];
            if(E.first==d[s]-d[E.second]){
                sum+=findpath(E.second);
                while(i<g[s].size()-1 && g[s][i+1]==E)++i;
            }
        }
        return dp[s]=sum;
    }
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>vertice>>edge;
    while (edge--) {
        cin>>u>>v>>w;
        g[u].push_back(ii(w,v)),g[v].push_back(ii(w,u));
    }
    FL(i, 0, vertice)sort(g[i].begin(), g[i].end(),[=](ii a,ii b){return ii(a.second,a.first)<ii(b.second,b.first);});
    Dijsktra();
    cout<<findpath(vertice-1)*2;
}
