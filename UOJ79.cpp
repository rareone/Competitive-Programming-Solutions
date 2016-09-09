#include <iostream>
#include <vector>
#include <queue>
#include "memory.h"
#define MAXN 500
#define qpush(u) q.push(u),S[u]=0
#define qpop() q.front();q.pop()
/*template provided by Sunmoon*/
using namespace std;
int V,ans=0,pa[MAXN],match[MAXN],Flower[MAXN],S[MAXN],vis[MAXN];
vector<int> adj[MAXN];
queue <int> q;

inline int lca(int i,int j,int root){
    static int t=1;
    for(t++;;swap(i,j)){
        if(i!=j&&i==root) continue;
        if(vis[i]==t) {vis[i]=t;return i;}
        vis[i]=t;
        i=Flower[pa[match[i]]];//go to stem if it has
    }
}//

inline void flower(int i,int j,int l){
    while(Flower[i]!=l){
        pa[i]=j;
        if(S[j=match[i]]==1) qpush(j);
        Flower[i]=Flower[j]=l,i=pa[j];
    }
}

inline bool bfs(int i){
    memset(S, -1, V*sizeof(int));
    while(!q.empty())q.pop();qpush(i);
    for(int a=0;a<V;a++) Flower[a]=a;
    
    while(!q.empty()){
        int v=qpop();
        for(int u:adj[v]){//v must be even
            if(S[u]==-1){//the edge must be non-match
                pa[u]=v,S[u]=1;
                if(match[u]==-1){//v is unsaturated
                    while(1){
                        int stay=match[v];
                        match[v]=u,match[u]=v;
                        if(stay==-1) return true;
                        u=stay;v=pa[u];
                    }
                }
                qpush(match[u]);//alternating
            }
            if(!S[u] && Flower[u]!=Flower[v]){
                int l=lca(u, v,i);
                flower(u,v,l); flower(v,u,l);
            }
        }
    }
    return false;
}


inline void greedy(){
    for(int i=0;i<V;++i)
        if(match[i]==-1)
            for(int v:adj[i])
                if(match[v]==-1) {match[i]=v,match[v]=i,++ans;break;}
}

int main(){
    int E,u,v;
    scanf("%d%d",&V,&E);
    for(int i=0;i<V;++i) adj[i].clear();
    while (E--) {
        scanf("%d%d",&u,&v); --u; --v;
        adj[u].push_back(v),
        adj[v].push_back(u);
    }
    
    memset(match, -1, V*sizeof(int));
    memset(Flower, -1, V*sizeof(int));
    memset(pa, -1, V*sizeof(int));
    
    greedy();
    for(int i=0;i<V and ans<V/2;++i)
        if(match[i]==-1 && bfs(i))++ans;
    
    printf("%d\n",ans);
    for(int i=0;i<V;i++)
        printf("%d ",match[i]==-1?0:match[i]+1);
}