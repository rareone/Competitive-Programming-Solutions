#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>
#define MAXN 500
#define F first
#define S second
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int > ii;
int adj[MAXN][MAXN],dis[MAXN],testcase,N,M,W,v,u,w;
int main(){
    scanf("%d",&testcase);
    while (testcase--) {
        scanf("%d%d%d",&N,&M,&W);
        FL(i, 0, N){FL(j, 0, N)adj[i][j]=1e9*(i!=j);dis[i]=1e9*(i!=0);}
        while (M--) {
            scanf("%d%d%d",&u,&v,&w);
            --u,--v;
            adj[u][v]=adj[v][u]=min(adj[u][v],w);
        }
        while (W--) {
            scanf("%d%d%d",&u,&v,&w);
            --u,--v;
            adj[u][v]=min(adj[u][v],-w);
        }
        FL(t, 0, N-1)FL(i, 0, N)FL(j, 0, N){
            if(dis[i]+adj[i][j]<dis[j])dis[j]=dis[i]+adj[i][j];
        }
        bool ok=1;
        FL(i, 0, N)FL(j, 0, N)
        if(dis[i]+adj[i][j]<dis[j])ok=0;
        printf("%s\n",ok?"NO":"YES");
    }
}

