#include <bits/stdc++.h>

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < N; ++I)
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
#define PLL pair<LL,LL>
#define VPLL vector<PLL >
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define F first
#define S second
typedef long long LL;
using namespace std;
const int _log=10;
LL ans[1025]={1},stay[1024]={1},mod=1000000007;

LL Power(LL b,LL p,LL mod){
    if(!p)return 1%mod;
    LL ans=1%mod;
    for (LL i=b; p; p>>=1,i=i*i%mod)if(p&1)ans=ans*i%mod;
    return ans;
}

PLL Exd(LL a,LL b){
    if(!(a%b))
        return PLL(0,1);
    PLL stay=Exd(b, a%b);
    return PLL(stay.S,stay.F-a/b*stay.S);
}

LL Inv(LL b,LL p){
    return (Exd(b,p).F+p)%p;
}


void XORtransform(LL *P, bool inverse=0,int k=_log) {
    for (int len = 1; 2 * len <= (1<<k); len <<= 1)
        for (int i = 0; i < (1<<k); i += 2 * len)
            for (int j = 0; j < len; ++j) {
                LL u = P[i + j] , v = P[i + len + j];
                P[i + j] = u + v % mod , P[i + len + j] = u - v % mod ;
            }
    if (inverse) for (int i = 0; i < (1<<k); ++i) P[i] = P[i] * Inv(1<<k,mod);
}

int main(){
    LL n,m;cin>>n>>m;
    fill(stay, stay+n+1, 1);
    XORtransform(ans);XORtransform(stay);
    for(;m;m>>=1){
        if(m&1)REP(i, 1024)ans[i]=ans[i]*stay[i]%mod;
        REP(i,1024)stay[i]=stay[i]*stay[i]%mod;
    }
    XORtransform(stay,1);
    XORtransform(ans,1);
    cout<<ans[0]%mod;
}
