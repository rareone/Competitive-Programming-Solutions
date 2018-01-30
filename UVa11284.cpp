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

double dp[100][100],store[20][20],storesave[20],TSP[20][1<<20];
//TSP[i][S]:目前在i已結帳,將S走完再回原點所需要能省的錢

LL storeidx[20];

int main(){
    CASET{
        double b;
        LL v,u;
        DRII(N,M);++N;
        REP(i,N)REP(j,N)dp[i][j]=i==j?0:1e18;
        REP(i,M){
            RII(u,v);scanf("%lf",&b);
            dp[u][v]=dp[v][u]=min(b,dp[u][v]);
        }
        REP(k,N)REP(i,N)REP(j,N)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        DRI(P);
        int rP=1;
        map<LL,LL> storetoidx;
        REP(i,P){
            RI(v);scanf("%lf",&b);
            if(storetoidx.count(v)){
                storesave[storetoidx[v]]+=b;
            }else{
                storetoidx[v]=rP++;
                storeidx[rP-1]=v;
                storesave[rP-1]=b;
            }
        }
        storeidx[0]=storesave[0]=0;P=rP;
        REP(i,P)REP(j,P){
            store[i][j]=dp[storeidx[i]][storeidx[j]];
        }
        
        
        
        
        
        REP(Se,1<<P){
            REP(i,P){
                if(Se&(1<<i))continue;
                TSP[i][Se]=Se==0?-store[i][0]:-1e18;
                REP(j,P){
                    if(Se&(1<<j)){
                        TSP[i][Se]=max(TSP[j][Se^(1<<j)]-store[i][j]+storesave[j],TSP[i][Se]);
                    }
                }
            }
        }double m=-1e18;
        REP(i,1<<P){
            m=max(TSP[0][i],m);
        }
        if(m>1e-6)printf("Daniel can save $%.2f\n",m);
        else puts("Don't leave the house");
        
        
    }
}
