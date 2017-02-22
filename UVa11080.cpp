#include <bits/stdc++.h>
//#include "bits:stdc++.h"
#define MAXN 200
#define FL(i,j,k) for(int i=j;i<k;++i)
#define eat(a) int a;scanf("%d",&a);
using namespace std;
vector<int> g[MAXN];
int color[MAXN],even[2];

bool dfs(int v,int p=-1,bool c=1){
    color[v]=c,++even[c];
    for(int u:g[v]){
        if(u==p)continue;
        if(color[u]==-1){if(!dfs(u,v,!c))return false;}
        else if(color[v]==color[u])return false;
    }
    return true;
}
int main(){
    eat(T);
    while (T--) {
        memset(color, -1, sizeof(color));
        for(auto &G:g)G.clear();
        eat(V)eat(E)
        while (E--) {
            eat(u)eat(v)
            g[u].push_back(v),g[v].push_back(u);
        }
        int num=0;bool success=1;
        FL(i, success && 0, V){
            if(color[i]!=-1)continue;
            if(g[i].size()==0){++num;continue;}
            even[0]=even[1]=0;
            if(dfs(i)){
                num+=min(even[0],even[1]);
            }else success=0;
        }
        if(success)printf("%d\n",num);
        else puts("-1");
    }
}
