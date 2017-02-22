//#include <bits/stdc++.h>
#include "bits:stdc++.h"
#define MAXN 100
#define FL(i,j,k) for(int i=j;i<k;++i)
#define eat(a) int a;scanf("%d",&a);
using namespace std;
typedef long long int ll;
vector<int> g[MAXN];
set<int> ok;
vector<int> ans,large;
void IDA(){
    if(ans.size()>large.size())large=ans;
    if(ok.size()==0)return;
    int v=*ok.begin();
    ok.erase(v);
    IDA();
    set<int> cur;
    for(int u:g[v]){
        if(ok.find(u)==ok.end())continue;
        cur.insert(u);
        ok.erase(u);
    }
    ans.push_back(v);
    IDA();
    ans.pop_back();
    ok.insert(cur.begin(),cur.end());
    ok.insert(v);
}
int main(){
    eat(T);
    while (T--) {
        ok.clear();large.clear();
        for(auto &G:g)G.clear();
        eat(V);eat(E);
        while (E--) {
            eat(v);eat(u);--u,--v;
            g[v].push_back(u),g[u].push_back(v);
        }
        FL(i, 0, V)ok.insert(i);
        IDA();
        printf("%d\n",large.size());
        FL(i,0,large.size())printf("%s%d",i==0?"":" ",large[i]+1);
        puts("");
    }
}
