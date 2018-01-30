#include "math.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#define prime 1000000007
using namespace std;
typedef long long int ll;
ll v[200001]={0};
ll pow(ll b,ll p){
    if(p==0)return 1;
    ll s=pow(b,p/2);
    return (s*s)%prime*(p%2==0?1:b)%prime;
}

int main(){
    int cas;scanf("%d",&cas);
    int i=0;
    while(cas--){
        int p;scanf("%d",&p);
        v[i++]=p;
    }
    sort(v,v+i);
    vector<pair<ll,ll>> vp(0);//<prime,power>
    for(ll h:v){
        if(!h)break;
        if(!vp.empty() && h==vp.back().first) vp.back().second=vp.back().second+1;
        else vp.push_back(pair<ll,ll>(h,1));
    }
    ll ans=1;
    long long int mul=1;
    for(int i=0;i<vp.size();++i) mul=mul*((int)vp[i].second+1)%(2*(prime-1));
    for(int i=0;i<vp.size();++i){
        ans=ans*pow(vp[i].first,mul*vp[i].second/2)%prime;
    }
    cout<<ans;
    
}
