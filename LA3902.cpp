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

VI g[10010];
LL n,r,k,a,b;
LL h[10010],deal[10000],pa[10000];
void dfsfirst(int r,int p=-1){
    if(p==-1)h[r]=0;
    pa[r]=p==-1?r:p;
    for(int v:g[r]){
        if(p==v)continue;
        h[v]=h[r]+1;
        dfsfirst(v,r);
    }
}


int climbup(int v,int d=k){
    REP(i,d)v=pa[v];
    return v;
}

void filltree(int v,int k,int p=-1){
    if(SZ(g[v])==1)deal[v]=1;
    if(k==0)return;
    for(int u:g[v]){
        if(u!=p){
            filltree(u,k-1,v);
        }
    }
}
int main(){
    DRI(T);
    while(T--){
        RI(n);
        RII(r,k);--r;
        fill(deal,deal+n,0);
        for_each(g,g+n,[=](VI &a){a.clear();});
        REP(i,n-1){
            RII(a,b);
            --a,--b;g[a].PB(b),g[b].PB(a);
        }
        dfsfirst(r,-1);
        priority_queue<PII,vector<PII>,less<PII>> pq;
        REP(i,n){
            if(SZ(g[i])==1 && h[i]<=k)deal[i]=1;
            else if(SZ(g[i])==1 && i!=r)pq.push(PII(h[i],i));
        }
        int sum=0;
        while(SZ(pq)){
            int h=pq.top().F,x=pq.top().S;pq.pop();
            if(deal[x])continue;
            ++sum;
            int y=climbup(x);
            filltree(y,k);
        }
        printf("%d\n",sum);
    }
}
