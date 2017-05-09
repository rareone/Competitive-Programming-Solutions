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

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
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
#define F real()
#define S imag()
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long LL;
using namespace std;

char s[1000];
LL A[30];
int main(){
    //freopen("in.txt","r",stdin);
    LL N;
    while(~RI(N) && N){
        map<LL,LL> m;m[0]=0;
        REP(i,N){
            scanf("%s",s);
            A[i]=0;
            int l=strlen(s);
            REP(j,l){
                A[i]^=(1<<(s[j]-'A'));
            }
        }
        int n=N/2;
        REP(i,(1<<n)){
            LL the=0,popcount=0,set=i;
            for(int s=0;set;set>>=1,++s){
                if(set&1){
                    popcount+=set%2;
                    the^=A[s];
                }
            }
            if(__builtin_popcount(i)>__builtin_popcount(m[the]))m[the]=i;
        }
        LL anset=m[0];
        REP(i,(1<<(N-n))){
            LL the=0,popcount=0,set=i;
            for(int s=0;set;set>>=1,++s){
                popcount+=set%2;
                if(set&1)the^=A[s+n];
            }
            if(m.count(the)){
                if(__builtin_popcount(anset)<__builtin_popcount(m[the])+__builtin_popcount(i)){
                    anset=(i<<(n))^m[the];
                    //printf("%lld \n",the);
                }
            }
        }printf("%d\n",__builtin_popcount(anset));
        bool first=0;
        for(int s=0;anset;++s,anset>>=1){
            if(anset&1){
                printf("%s%d",first?" ":"",s+1);
                first=1;
            }
        }puts("");
    }
}

