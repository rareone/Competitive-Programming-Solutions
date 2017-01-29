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
#define INF 1e18
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
typedef complex<int> pt;

int p[1010],r[1010];
int parent(int i){return p[i]==i?i:p[i]=parent(p[i]);}
void UN(int i,int j){
    if(parent(i)==parent(j))return;
    i=parent(i),j=parent(j);
    if(r[i]>r[j])p[j]=i;
    else p[i]=j,r[i]+=r[i]==r[j];
}

ll V[1010]={0},n,m,w,u,v;ii item[1010];
bool seen[1010]={0};

ii total(vector<ll> &v){
    ll weight=0,cost=0;
    FL(i, 0, v.size())weight+=item[v[i]].first,cost+=item[v[i]].second;
    return ii(weight,cost);
}
vector<ll> group[1010];
int main(){
    scanf("%d%d%d",&n,&m,&w);
    FL(i, 0, n)scanf("%d",&item[i].first);
    FL(i, 0, n)scanf("%d",&item[i].second);
    FL(i, 0, n)p[i]=i;
    FL(i, 0, m){
        scanf("%d%d",&u,&v);--u,--v;
        UN(v, u);
    }
    int g=0;
    FL(i, 0, n){
        if(seen[i])continue;
        FL(j, i, n){
            if(parent(j)==parent(i)){
                seen[j]=1,group[g].push_back(j);
            }
        }
        ++g;
    }
    FL(i, 0, g){
        ll stay[1010]={0};
        FL(j, 0, group[i].size()){
            ll c=item[group[i][j]].first,w=item[group[i][j]].second;
            FL(k, 0, 1001){
                if(k-c>=0)stay[k]=max(stay[k], V[k-c]+w);
            }
        }
        ii T=total(group[i]);
        int c=T.first,w=T.second;
        FL(k, 0, 1001){
            if(k-c>=0)stay[k]=max(stay[k], V[k-c]+w);
        }
        FL(i, 0, 1001){
            V[i]=max(stay[i], V[i]);
        }
    }
    cout<<V[w];
}
