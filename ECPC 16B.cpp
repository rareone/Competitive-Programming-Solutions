#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <utility>
#define MAXN 500000
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef long long int ll;
typedef pair<double,ll> ii;
typedef vector<ii> vi;//road weight,vertice
ll N;
double adj[102][102],d[102];
int P[100][2],H[100];
bool S[100],vis[100];

double dis(int i,int j){
    if(P[j][1]<P[i][1])swap(i, j);
    ll y=max(0, P[j][1]-P[i][1]-H[i]);
    if(S[i]^S[j]){
        if(S[i])swap(i, j);
        ll x=max(0, P[j][0]-P[i][0]);
        return sqrt(x*x+y*y);
    }else{
        return y;
    }
}
inline void Dijsktra(){
    FL(i, 0, N+2) {
        d[i]=9223372036854775807LL;
        vis[i]=0;
    }
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push(ii(0,N));d[N]=0;
    while (!pq.empty()) {
        ll front=pq.top().second; pq.pop();
        FL(i, 0, N+2){
            if(vis[i])continue;
            d[i]=min(d[front]+adj[i][front],d[i]);
            if(!vis[i]){
                pq.push(ii(adj[i][front],i));
            }
        }
        vis[front]=1;
        if(front==N+1)return;
    }
}
int main(){
    freopen("street.in", "r", stdin);
    int T,l,U,w,b;scanf("%d",&T);
    FL(t, 0, T){
        scanf("%d%d%d",&N,&l,&U);
        adj[N+1][N]=adj[N][N+1]=l;
        FL(i, 0, N){
            scanf("%d%d%d%d",&H[i],&w,&P[i][1],&S[i]);
            P[i][0]=S[i]?U-w:w;
            adj[N][i]=adj[i][N]=max(0,P[i][1]);
            adj[N+1][i]=adj[i][N+1]=max(0,l-P[i][1]-H[i]);
        }
        FL(i, 0, N){
            FL(j, i+1, N){
                adj[j][i]=adj[i][j]=dis(i, j);
            }
        }
        Dijsktra();
        printf("%.6f\n",d[N+1]);
        

    }
}
