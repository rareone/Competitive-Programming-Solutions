#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#define MAXN 50010
#define F first
#define S second
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int > ii;
vector<ii> g[MAXN];
ll cost[MAXN],d[MAXN],V,M,v1,v2,w,v,sum=0,testcase;
bool vis[MAXN];

priority_queue<ii,vector<ii>,greater<ii>> pq;
int main(){
    scanf("%lld",&testcase);
    while (testcase--) {
        scanf("%lld%lld",&V,&M);
        FL(i, 0, V) g[i].clear(),d[i]=1e18,vis[i]=false;
        FL(i, 0, V)scanf("%lld",&cost[i]);
        FL(i,0,M){
            scanf("%lld%lld%lld",&v1,&v2,&w);--v1,--v2;
            g[v1].push_back(ii(w,v2));
            g[v2].push_back(ii(w,v1));
        }
        pq.push(ii(0,0));d[0]=0,sum=0;
        while (!pq.empty()) {
            v=pq.top().S,w=pq.top().F;pq.pop();
            if( vis[v])continue;
            vis[v]=true;
            FL(i, 0, g[v].size()){
                ll wei=g[v][i].F,next=g[v][i].S;
                if(!vis[next] ){
                    d[next]=d[v]+wei<d[next]?d[v]+wei:d[next];
                    pq.push(g[v][i]);
                }
            }
        }
        FL(i, 0, V)sum+=cost[i]*d[i];
        if(sum<1e18){
            printf("%lld\n",sum);
        }else{
            printf("No Answer\n");
        }
    }
    return 0;
}
