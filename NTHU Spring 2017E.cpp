// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
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
#define REP(I, N) for (int I = 0; I < N; ++I)
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
#define PLL pair<LL,LL>
#define VPLL vector<PLL >
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define F first
#define S second
typedef long long LL;
using namespace std;
const int _log=10;
LL ans[1025]={1},stay[1024]={1},mod=1000000007;

LL Power(LL b,LL p,LL mod){
    if(!p)return 1%mod;
    LL ans=1%mod;
    for (LL i=b; p; p>>=1,i=i*i%mod)if(p&1)ans=ans*i%mod;
    return ans;
}

PLL Exd(LL a,LL b){
    if(!(a%b))
        return PLL(0,1);
    PLL stay=Exd(b, a%b);
    return PLL(stay.S,stay.F-a/b*stay.S);
}

LL Inv(LL b,LL p){
    return (Exd(b,p).F+p)%p;
}


void XORtransform(LL *P, bool inverse=0,int k=_log) {
    for (int len = 1; 2 * len <= (1<<k); len <<= 1)
        for (int i = 0; i < (1<<k); i += 2 * len)
            for (int j = 0; j < len; ++j) {
                LL u = P[i + j] , v = P[i + len + j];
                P[i + j] = u + v % mod , P[i + len + j] = u - v % mod ;
            }
    if (inverse) for (int i = 0; i < (1<<k); ++i) P[i] = P[i] * Inv(1<<k,mod);
}

int main(){
    LL n,m;cin>>n>>m;
    fill(stay, stay+n+1, 1);
    XORtransform(ans);XORtransform(stay);
    for(;m;m>>=1){
        if(m&1)REP(i, 1024)ans[i]=ans[i]*stay[i]%mod;
        REP(i,1024)stay[i]=stay[i]*stay[i]%mod;
    }
    XORtransform(stay,1);
    XORtransform(ans,1);
    cout<<ans[0]%mod;
}
