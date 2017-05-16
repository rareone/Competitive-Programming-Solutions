#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
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
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#define SZ(X) ((X).size())
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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long LL;
using namespace std;

LL dp[20][100][100],A,B,K;

LL pow10[20]={1};
LL Ans(LL d,LL r=0,LL t=0){//r: **...** length is d,digit sum is r,t:**...** length is d, is divisible by t
    if(d==0)return r==0&&t==0;
    if(dp[d][r][t]!=-1)return dp[d][r][t];
    LL ans=0;
    for(int i=0;i<10;++i){
        ans+=Ans(d-1,(r+10*K-i)%K,((t-i*pow10[d-1])%K+K)%K);
    }
    //printf("%lld %lld %lld",d,r,t);
    //printf(" %lld\n",ans);
    return dp[d][r][t]=ans;
}
int digit[20],r=0;
LL Ask(LL a){
    r=0;
    LL ans=0,pre=0,predigit=0;
    MS1(dp);
    for(;a;a/=10)digit[r++]=a%10;
    for(int l=r-1;l>=0;--l){
        for(int i=0;i<digit[l];++i){
            ans+=Ans(l,((-predigit-i)%K+K)%K,((-pre-i*pow10[l])%K+K)%K);
            pre+=1*pow10[l];
        }
        predigit+=digit[l];
    }
    return ans;
}

int main(){
    for(int i=1;i<19;++i)pow10[i]=pow10[i-1]*10;
    CASET{
        RIII(A,B,K);
        printf("%lld\n",Ask(B+1)-Ask(A));
    }
    
}
