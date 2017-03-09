#include <iostream>
#include <stack>
//#include <bits/stdc++.h>
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
using namespace std;
typedef long long int LL;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

#define MAXN 100010

LL A[MAXN],Pre[MAXN]={0},dp[MAXN]={0},K;
iii st[MAXN];

inline LL f(int i,int j){return dp[j]+K+(Pre[i]-Pre[j])*(Pre[i]-Pre[j])*(Pre[i]-Pre[j]);}//It is convex!!!
int main(){
    DRI(T);
    while (T--) {
        
        DRI(N);scanf("%lld",&K);
        REPP(i, 1, N+1){
            scanf("%lld",A+i);
        }Pre[0]=dp[0]=0;
        REPP(i, 1, N+1)Pre[i]=Pre[i-1]+A[i];
        
        
        
        int l=0,r=0;
        st[r++]=iii(ii(1,N+1),0);//(0.....N)
        dp[1]=f(1, 0);
        //dp[i-1]已算出來
        //rightmost in queue is newly updated(may be empty)
        
        REPP(i, 2, N+1){
            while(l<r && f(st[r-1].F.F,st[r-1].S)>=f(st[r-1].F.F,i-1))--r;
            if(l==r){
                st[r++]=iii(ii(i,N+1),i-1);
            }else{
                int L=st[r-1].F.F,orgL=L,R=st[r-1].F.S,jt=st[r-1].S;
                while (L<R-1) {
                    int mid=(L+R)/2;
                    (f(mid,jt)<f(mid,i-1)?L:R)=mid;
                }--r;
                if(orgL<R)st[r++]=iii(ii(orgL,R),jt);
                if(R<N+1)st[r++]=iii(ii(R,N+1),i-1);
            }
            if (st[l].F.S==i) ++l;
            dp[i]=f(i,st[l].S);
        }
        printf("%lld\n",dp[N]);
        
    }
}

//https://judge.ioicamp.org/problems/91
