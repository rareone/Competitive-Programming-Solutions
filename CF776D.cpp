#include <iostream>
#include <vector>
#include <utility>
#define eat(a) int a;scanf("%d",&a);
#define FL(i,j,k) for(int i=j;i<k;++i)

using namespace std;
typedef pair<int, bool> ii;
int A[100010][2]={0},size[100010]={0};
int cur[100010];
vector<ii> g[100010];
int vis[100010];
bool bi(int v=0,bool c=0){
    vis[v]=c;
    for(ii x:g[v]){
        int u=x.first;bool b=x.second;
        if(vis[u]==-1){
            if(!bi(u,(b xor c)))return false;
        }else if(vis[u]!=(b xor c))return false;
    }
    return true;
}
int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);
    eat(n);eat(m);
    fill(vis, vis+100010, -1);
    FL(i, 0, n)scanf("%d",cur+i);
    FL(i, 0, m){
        eat(x);
        FL(j, 0, x){
            eat(u);--u;
            A[u][size[u]++]=i;
        }
    }
    FL(i, 0, n){
        g[A[i][0]].push_back(ii(A[i][1],cur[i]==0)),g[A[i][1]].push_back(ii(A[i][0],cur[i]==0));
    }
    FL(i, 0, m){
        if(vis[i]!=-1)continue;
        if(!bi(i)){
            return 0*puts("NO");
        }
    }
    puts("YES");
}
