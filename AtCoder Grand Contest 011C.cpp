#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;

#define MAXN 100100



VI g[MAXN];
int vis[MAXN]={0};
bool bi(int v,int c){
    vis[v]=c;bool ok=1;
    for(int u:g[v]){
        if(vis[u]==0){
            if(!bi(u,-c))ok=0;
        }else{
            if(vis[u]==c)ok=0;
        }
    }
    return ok;
}
int main(){
    DRII(N,M);
    REP(i,M){
        DRII(v, u);--v,--u;
        g[v].push_back(u),g[u].push_back(v);
    }
    LL single=0,flower=0,bip=0;
    REP(i, N){
        if(!vis[i]){
            if(g[i].size()==0)++single;
            else{
                if(bi(i, 1)){
                    ++bip;
                }else{
                    ++flower;
                }
            }
        }
    }
    //cout<<single<<' '<<flower<<' '<<bip<<endl;
    LL ans=2*single*N-single*single+bip*bip*2+bip*flower*2+flower*flower;
    cout<<ans;
}
