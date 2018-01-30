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
#define MAXN 100

typedef complex<LL> pt;
pt A[110];

LL tt=1,a,b,N,on[110],r,on2[110],L[110];
int main(){
    while(~RI(N) && N){
        REP(i,N){
            RII(a,b);
            A[i]=pt(a,b);
        }
        
        sort(A,A+N,[=](pt a,pt b){return a.real()<b.real();});
        LL ans=1;
        REP(i,N){
            REP(j,i){
                fill(L,L+N,0),fill(on,on+N,0),fill(on2,on2+N,0);
                r=0;L[r]=0;
                pt up=A[i],down=A[j];
                if(A[i].S<A[j].S)swap(up,down);
                REP(k,N){
                    if(A[k].S>up.S || A[k].S<down.S)continue;
                    int nextk=0,inln=0;
                    for(nextk=k;nextk<N && A[nextk].F==A[k].F ;++nextk){
                        if(A[nextk].S>up.S || A[nextk].S<down.S)continue;
                        if(A[nextk].S!=up.S && A[nextk].S!=down.S)++on[r],++on2[r];
                        else ++on2[r],++inln;
                    }
                    ++r;
                    L[r]=L[r-1]+inln;
                    k=nextk-1;
                }
                LL bigp=0,pre=0;
                REP(i,r){
                    pre=on2[i]+L[i];
                    ans=max(ans,bigp+pre);
                    bigp=max(bigp,on[i]-L[i]);
                }
            }
        }
        printf("Case %lld: %lld\n",tt++,ans);
        
    }
}
