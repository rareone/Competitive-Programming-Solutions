#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
#include "limits.h"
#define INF 1e9
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
typedef vector<ll > vi;
struct T{
    int small,large;
};
T node[200000];

void build(int v,int l,int r){
    if(r-l==1){
        scanf("%d",&node[v].small);
        node[v].large=node[v].small;
        return;
    }
    int mid=(l+r)/2;
    build(v<<1, l, mid);
    build(v<<1|1, mid, r);
    node[v].small=min(node[v<<1].small,node[v<<1|1].small);
    node[v].large=max(node[v<<1].large,node[v<<1|1].large);
}

ii ask(int v,int l,int r,int L,int R){
    if(L>=r||R<=l)return ii(INF,-INF);
    if(L<=l&&r<=R){
        return ii(node[v].small,node[v].large);
    }
    int mid=(l+r)/2;
    ii left=ask(v<<1, l, mid, L, R),right=ask(v<<1|1, mid, r, L, R);
    return ii(min(left.first, right.first),max(left.second, right.second));
}
int main(){
    int n,q,l,r;
    while(~scanf("%d%d",&n,&q)){
        build(1, 0, n);
        while (q--) {
            scanf("%d%d",&l,&r);--l,--r;
            ii ans=ask(1, 0, n, l, r+1);
            printf("%d\n",ans.second-ans.first);
        }
    }
    
}
