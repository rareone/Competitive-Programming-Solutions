#include <iostream>
#include <vector>
#define MAXN 500
#include <queue>
#include "memory.h"
using namespace std;
typedef vector<int> vi;

vector<vi> adjx,adjy;
vi mx,my,py;
int X,Y,E,ans=0;
vector<bool> vy;

inline void Input(){
    scanf("%d%d%d",&X,&Y,&E);
    mx.assign(X, -1),my.assign(Y,-1),py.assign(Y,-1);
    adjx.resize(X),adjy.resize(Y);
    while(E--){
        int u,v;//u boy, v girl
        scanf("%d%d",&u,&v);
        --u,--v;
        adjx[u].push_back(v);
        adjy[v].push_back(u);
    }
}
inline bool bfs(int u){
    queue<int> q;q.push(u);vy.assign(Y,0);
    while(!q.empty()){
        int w=q.front();q.pop();
        for(int c:adjx[w])
            if(!vy[c]){
                vy[c]=1,py[c]=w;
                if(my[c]==-1){
                    while(1){
                        int stay=mx[w];
                        mx[w]=c,my[c]=w;
                        if(stay==-1)return 1;
                        c=stay; w=py[c];
                    }
                }
                else q.push(my[c]);
            }
    }
    return false;
}
inline void Output(){
    printf("%d\n",ans);
    for(int u:mx) printf("%d ",u==-1?0:u+1);
}

int main(){
    Input();
    for(int i=0;i<X;++i )if(mx[i]==-1  && ans<min(X,Y)&& bfs(i)) ++ans;
    Output();
}