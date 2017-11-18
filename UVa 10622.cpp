#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ccomplex>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>


#define SZ(X) ((X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (LL I = 0; I < N; ++I)
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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long LL;
using namespace std;

VL ptt,ans;
bool sieve[1000000]={1 ,1};
int main(){
    for(LL i=2;i<1000000;++i){
        if(!sieve[i]){
            for(LL j=i*i;j<1000000;j+=i)sieve[j]=1;
            ptt.PB(i);
        }
    }
    LL N;
    while(~RI(N) && N){
        bool flag=0;
        if(N<0)flag=1,N=abs(N);
        ans.clear();
        for(LL p:ptt){
            int c=0;
            while(N%p==0)N/=p,++c;
            if(c)ans.PB(c);
        }
        LL AA=ans[0];
        if(N!=1)puts("1");
        else {
            REPP(i,1,SZ(ans))AA=__gcd(AA,ans[i]);
            if(flag)AA/=__gcd(AA,1ll<<32);
            printf("%lld\n",AA);
        }
    }
}
