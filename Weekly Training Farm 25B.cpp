#include <iostream>
#include <algorithm>
#include <cstring>

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

LL Multiply(LL a,LL b,LL m){
    if(((a%=m)<INT_MAX && (b%=m)<INT_MAX)||a<100||b<100)
        return a*b%m;
    LL sa=a/10,r=a%10,sb=b/10,k=b%10;
    return (100*Multiply(sa,sb,m)+10*k*sa+10*r*sb+r*k)%m;
}

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

LL GCD(LL a,LL b){
    PLL gcd = Exd(a, b);
    return gcd.F*a+gcd.S*b;
}

LL Inv(LL b,LL p){
    return (Exd(b,p).F+p)%p;
}
LL bionomial(LL a,LL b,LL mod){
    LL ans=1;
    for(LL p=a,q=b;q||p;p/=mod,q/=mod){
        LL r=p%mod,t=q%mod;
        if(r<t)return 0;
        if(t>r/2)t=r-t;
        REP(i,t)ans=ans*(r-i)%mod,ans=ans*Inv(i+1,mod)%mod;
    }
    return ans%mod;
}
const LL mod=1e9+7;
LL f[1000010]={1};
int main(){
    REPP(i,1, 1000008)f[i]=f[i-1]*i%mod;
    DRII(l, r);
    if(l+r!=0||l%2)return 0*puts("0");
    else cout<<f[r]*Inv(f[r/2], mod)%mod;
}
