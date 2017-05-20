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

LL X[10],C,Se,XX,Xk,k[10];
VL con[10],sol;
PLL exd(LL a,LL b){
    if(!(a%b))return PLL(0,1);
    PLL T=exd(b,a%b);
    return PLL(T.S,T.F-a/b*T.S);
}

bool is(LL n){
    REP(i,C){
        bool ok=0;
        for(LL l:con[i]){
            if(n%X[i]==l){ok=1;break;}
        }if(!ok)return 0;
    }return 1;
}
LL Chinese(VPLL &v){
    LL ans=0;
    
    REP(i,SZ(v)){
        ans=ans+v[i].F*XX/v[i].S*exd(XX/v[i].S,v[i].S).F;
        ans%=XX;
    }
    //printf("  %lld\n",ans);
    return (ans+XX)%XX;
}
void BF(){
    VPLL chinese;
    REP(Se,Xk){
        chinese.clear();
        LL SS=Se;
        REP(i,C){
            chinese.PB(PLL(con[i][SS%k[i]],X[i]));
            SS/=k[i];
        }
        sol.PB(Chinese(chinese));
    }
}
int main(){
    while(~RII(C,Se) && C ){
        XX=1;Xk=1,sol.clear();
        LL toc=0;
        REP(i,C){
            LL a;
            RII(X[i],k[i]);
            XX*=X[i];
            Xk*=k[i];
            if(X[toc]*k[i]<X[i]*k[toc])toc=i;
            con[i].clear();
            REP(j,k[i]){
                RI(a);
                con[i].PB(a);
            }sort(con[i].begin(),con[i].end());
        }
        if(Xk<10000){
            BF();
            sort(sol.begin(),sol.end());
            for(int i=0;i<Se;++i){
                if(i==0 && sol[i]==0)++Se;
                else printf("%lld\n",sol[i%SZ(sol)]+XX*(i/SZ(sol)));
            }
        }
        else{
            REP(i,XX/X[toc] && SZ(sol)<Se+10){
                for(auto y:con[toc]){
                    LL to=i*X[toc]+y;
                    if(is(to))sol.PB(to);
                }
            }
            for(int i=0;i<Se;++i){
                if(i==0 && sol[i]==0)++Se;
                else printf("%lld\n",sol[i%SZ(sol)]+XX*(i/SZ(sol)));
            }
        }
        puts("");
    }
}
