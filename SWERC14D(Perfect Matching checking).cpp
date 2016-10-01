//只是拿之前寫過的改
//不過之前寫的也很亂
//真的有需要的時候再來整理
#include <iostream>
#include <vector>
#define MAXN 2000
#include <queue>
#include "memory.h"
using namespace std;
typedef vector<int> vi;

vector<vi> adjx;
vi mx,my,py;
int X,Y,E,ans=0;
vector<bool> vy;

inline void Input(){
    scanf("%d%d",&X,&E);
    Y=X;
    mx.assign(X, -1),my.assign(Y,-1),py.assign(Y,-1);
    adjx.resize(X);
    while(E--){
        int u,v;//u boy, v girl
        scanf("%d%d",&u,&v);
        adjx[u].push_back(v);
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
    if(ans==X)printf("YES");
    else printf("NO");
}

int main(){
    Input();
    for(int i=0;i<X;++i )if(mx[i]==-1  && ans<min(X,Y)&& bfs(i)) ++ans;
    Output();
}
