/*Code is modified from others*/
#include<cstdio>
#include<algorithm>
#include<vector>
#include <iostream>
#define FL(i,j,k) for(int i=j;i<k;++i)
const int MAXN = 2e6;
using namespace std;
typedef long long ll;
ll color[MAXN]={0},n,m,num[MAXN][2]={0},pos[MAXN];//pos:區間->節點
ll leaf[MAXN]={0},nut[MAXN]={0};//顏色＆標記
vector<ll> adj[MAXN];

void dfs(ll v,ll p=-1){
    static ll t=0;
    pos[t]=v;
    num[v][0]=t++;
    for(ll u:adj[v]){
        if(u!=p)dfs(u,v);
    }
    num[v][1]=t;
}

void build(ll v=1,ll begin=0,ll end=n){
    if(end-begin==1){
        leaf[v]=1LL<<color[pos[begin]];
        return;
    }
    ll mid=(end+begin)/2;
    build(v<<1,begin,mid);
    build(v<<1^1,mid,end);
    leaf[v]=leaf[v<<1^1]|leaf[v<<1];
}
void fill(ll s/*seed*/, ll left,ll right,ll begin,ll end,ll color){//[begin,end) 要修改的區間
    if(begin<=left && right<=end){
        leaf[s]=1LL<<color,nut[s]=color;return;
    }
    if(left>=end||right<=begin)return;
    ll mid=(left+right)/2;
    if(nut[s]!=0){
        nut[s<<1] = nut[s<<1^1] = nut[s];
        leaf[s<<1]=leaf[s<<1^1]=1LL<<nut[s];
        nut[s]=0;
    }
    fill(s<<1,left,mid,begin,end,color);
    fill(s<<1^1,mid,right,begin,end,color);
    leaf[s]=leaf[s<<1^1]|leaf[s<<1];
}

ll got(ll s/*seed*/, ll left,ll right,ll begin,ll end){
    if(begin<=left && right<=end) return leaf[s];
    if(left>=end||right<=begin) return 0;
    ll mid=(left+right)/2;
    if(nut[s]!=0){
        nut[s<<1] = nut[s<<1^1] = nut[s];
        leaf[s<<1]=leaf[s<<1^1]=1LL<<nut[s];
        nut[s]=0;
    }
    return got(s<<1,left,mid,begin,end)|got(s<<1^1,mid,right,begin,end);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    FL(i,0,n)cin>>color[i];
    FL(i,0,n-1){
        ll u,v;
        cin>>u>>v;--u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    build();
    ll q,v,c;
    FL(i, 0, m){
        cin>>q>>v;--v;
        if(q==1){
            cin>>c;
            fill(1,0,n,num[v][0],num[v][1],c);
        }else{
            cout<<__builtin_popcountll(got(1,0,n,num[v][0],num[v][1]))<<'\n';
        }
    }
}
