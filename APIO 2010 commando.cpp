#ifdef __APPLE__
#include "bits:stdc++.h"
#define debug(A,N) PLLD(A,N)
#else
#include <bits/stdc++.h>
#define debug(A,n) ;
#endif


#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (LL I = 0; I < (N); ++I)
#define REPP(I, A, B) for (LL I = (A); I < (B); ++I)
#define RI(X) scanf("%lld", &(X))
#define RII(X, Y) scanf("%lld%lld", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%lld%lld%lld", &(X), &(Y), &(Z))
#define DRI(X) LL (X); scanf("%lld", &X)
#define DRII(X, Y) LL X, Y; scanf("%lld%lld", &X, &Y)
#define DRIII(X, Y, Z) LL X, Y, Z; scanf("%lld%lld%lld", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<LL>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
#define IO(s) freopen(s".in","r",stdin); freopen(s".out","w" ,stdout);
#define PLLD(A,N) REP(I,N)printf("%lld%c",*(A+I)," \n"[I==N-1])
#define PD(A,N) REP(I,N)printf("%d%c",*(A+I)," \n"[I==N-1])
#define PS(s) printf("%s\n",s)

using namespace std;
typedef long long LL;
#define MAXN 1000100
LL dq[MAXN],pre[MAXN],A[MAXN],dp[MAXN],l=0,r=0,a,b,c,choose[MAXN];
inline LL compute(LL i,LL j){
  return dp[j]+a*pre[j]*pre[j]-b*pre[j]-2*a*pre[i]*pre[j];
}

bool check(LL i,LL j,LL k){
  LL a1=-2*a*pre[i], b1 = dp[i]+a*pre[i]*pre[i]-b*pre[i];
  LL a2=-2*a*pre[j], b2 = dp[j]+a*pre[j]*pre[j]-b*pre[j];
  LL a3=-2*a*pre[k], b3 = dp[k]+a*pre[k]*pre[k]-b*pre[k];
  return (b1-b2)*(a1-a3)<=(b3-b1)*(a2-a1);
}
int main(){
  CASET{
    DRI(N);
    RIII(a,b,c);
    REP(i,N)RI(A[i+1]);
    pre[0]=0;
    l=r=0;
    REP(i,N)pre[i+1]=pre[i]+A[i+1];
    dp[0]=0;dp[1]=a*(A[1]*A[1])+b*A[1]+c,dq[r++]=0,dq[r++]=1;
    
    REPP(i,2,N+1){
      

      while(r-l>=2 && compute(i,dq[l])<=compute(i,dq[l+1]))++l;
      dp[i]=a*pre[i]*pre[i]+b*pre[i]+c+compute(i,dq[l]);
      choose[i]=dq[l];
      while(r-l>=2 && check(dq[r-2],dq[r-1],i))--r;
      dq[r++]=i;
    }
    printf("%lld\n",dp[N]);
    /*debug(dp,N+1);
    debug(choose,N+1);
    debug(pre,N+1);*/
  }
}
