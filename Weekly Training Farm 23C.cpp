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
typedef long long LL;
using namespace std;


LL Multiply(LL a,LL b,LL m){
    if(((a%=m)<INT_MAX && (b%=m)<INT_MAX)||a<100||b<100)
        return a*b%m;
    LL sa=a/10,r=a%10,sb=b/10,k=b%10;
    return (100*Multiply(sa,sb,m)+10*k*sa+10*r*sb+r*k)%m;
}

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

LL GCD(LL a,LL b){
    PLL gcd = Exd(a, b);
    return gcd.F*a+gcd.S*b;
}

LL Inv(LL b,LL p){
    return (Exd(b,p).F+p)%p;
}
LL bionomial(LL a,LL b,LL mod){
    LL ans=1;
    for(LL p=a,q=b;q||p;p/=mod,q/=mod){
        LL r=p%mod,t=q%mod;
        if(r<t)return 0;
        if(t>r/2)t=r-t;
        REP(i,t)ans=ans*(r-i)%mod,ans=ans*Inv(i+1,mod)%mod;
    }
    return ans%mod;
}
//Input: two integer a,b
//Output: x,y in the font of pair<int,int> s.t. ax+by=gcd(a,b)

LL mod=1e9+7;
string s;
LL multip(LL q,LL inc){
    if(inc==0)return 1;
    return bionomial(q+inc, inc, mod);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cin>>s;
    int curmax=0;
    for(char c:s){
        if(c=='?')continue;
        if(c-'0'<curmax)return 0*puts("0");
        else if (c-'0'>curmax)curmax=c-'0';
    }
    LL ans=1,premax=0,qsize=0;
    for(char c:s){
        if(c!='?'){
            if(qsize!=0)ans=ans*multip(qsize,c-'0'-premax)%mod;
            qsize=0,premax=c-'0';
        }else{
            qsize+=1;
        }
    }
    if(qsize)ans=ans*multip(qsize,9-premax)%mod;
    cout<<ans;
}
