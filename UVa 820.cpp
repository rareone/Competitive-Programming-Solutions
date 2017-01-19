#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>
#include "limits.h"
#define INF 1e9
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
typedef vector<ll > vi;

int C[100][100],R[100][100],dis[100],n,u,v,w,s,t,m;
bool BFS(int s,int t){
    FL(i, 0, n)dis[i]=INF;
    queue<int> q;q.push(s);dis[s]=0;
    while (!q.empty()) {
        int s=q.front();q.pop();
        FL(i, 0, n)if(dis[i]==INF && R[s][i])dis[i]=dis[s]+1,q.push(i);
    }return dis[t]!=INF;
}

int DFS(int s,int t,int cur_flow=INF){//return the aug using the current flow
    if(cur_flow==0||s==t)return cur_flow;
    int aug_flow=0,aug=0;
    FL(i, 0, n){
        if(R[s][i]>0 && dis[s]+1==dis[i]){
            aug=DFS(i, t,min(cur_flow,R[s][i]));
            R[s][i]-=aug,R[i][s]+=aug;
            aug_flow+=aug;
            if(!(cur_flow-=aug))break;
        }
    }
    return aug_flow;
}
int maximum(int s,int t){
    int aug_sum=0;
    while (BFS(s, t))aug_sum+=DFS(s,t);
    return aug_sum;
}
int main(){
    //freopen("in.txt", "r", stdin);
    int network=1;
    while (~scanf("%d",&n)) {
        if(n==0)return 0;
        FL(i, 0, n)FL(j, 0, n)C[i][j]=R[i][j]=0;
        scanf("%d%d%d",&s,&t,&m);--s,--t;
        while (m--) {
            scanf("%d%d%d",&u,&v,&w);--u,--v;
            R[u][v]+=w,R[v][u]+=w,C[u][v]+=w,C[v][u]+=w;
        }
        printf("Network %d\n",network++);
        printf("The bandwidth is %d.\n",maximum(s,t));
        puts("");
    }
}
