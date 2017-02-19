#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <complex>
#include <algorithm>
#include "limits.h"
#include <queue>
#include <sstream>
#include <bitset>
#include <stack>
#define INF 1e18
#define MAXN 200000
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
typedef complex<int> pt;


vector<int> g[MAXN];
ll T[MAXN],sum[MAXN],maxtree[MAXN];

ll ans(int i=0,int p=-1){
    ll t=-INF;vector<ll> subtreew;subtreew.clear();
    for(int v:g[i]){
        if(v!=p){
            t=max(ans(v,i) ,t);
            subtreew.push_back(maxtree[v]);
        }
    }
    if(subtreew.size()<2)return t;
    sort(subtreew.begin(), subtreew.end(),[=](ll a,ll b){return a>b;});
    return max(subtreew[0]+subtreew[1], t);
}
void dfs(int i=0,int p=-1){
    sum[i]=T[i],maxtree[i]=-INF;
    for(int v:g[i]){
        if(v!=p){
            dfs(v,i);
            sum[i]+=sum[v];
            maxtree[i]=max(maxtree[i], maxtree[v]);
        }
    }
    maxtree[i]=max(maxtree[i], sum[i]);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,u,v;
    cin>>n;
    FL(i, 0, n)cin>>T[i];
    FL(i, 0, n-1){
        cin>>u>>v;
        --u,--v;
        g[u].push_back(v),g[v].push_back(u);
    }
    dfs();
    ll a=ans();
    if(a<-1e15)cout<<"Impossible";
    else cout<<a;
}
