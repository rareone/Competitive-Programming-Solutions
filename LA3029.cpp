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
#define F first
#define S second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long LL;
using namespace std;
#define MAXN 1000
LL up[MAXN][MAXN],lef[MAXN][MAXN],righ[MAXN][MAXN];
LL Table[MAXN][MAXN],lof,lor;
bool rock(){
    char c=getchar();
    while(c!='R'&& c!='F')c=getchar();
    return c=='R';
}

int main(){
    DRI(T);LL R,C;
    while(T--){
        RII(R,C);
        REP(i,R)REP(j,C)Table[i][j]=rock();
        LL ans=0;
        REP(j,C){
            up[0][j]=!Table[0][j];
            lef[0][j]=Table[0][j]?j+1:j>0?lef[0][j-1]:0;
            righ[0][C-j-1]=Table[0][C-j-1]?C-j-1:C-j<C?righ[0][C-j]:C;
        }
        REPP(i,1,R)REP(j,C){
            up[i][j]=Table[i][j]?0:up[i-1][j]+1;
        }
        REPP(i,1,R){
            lof=0,lor=C;
            REP(j,C){
                if(Table[i][j])lof=j+1;
                if(Table[i][C-j-1])lor=C-j-1;
                lef[i][j]=Table[i][j]?j+1:Table[i-1][j]?lof:max(lef[i-1][j],lof);
                righ[i][C-j-1]=Table[i][C-j-1]?C-j-1:Table[i-1][C-j-1]?lor:min(righ[i-1][C-j-1],lor);
            }
        }
        REP(i,R){
            
            REP(j,C){
                //printf("%lld ",righ[i][j]);
                ans = max(ans,Table[i][j]?0:up[i][j]*(righ[i][j]-lef[i][j]));
            }
            //puts("");
        }
        printf("%lld\n",3*ans);
    }
}
