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

LL A[100][100],row[100][100],col[100][100],block[100][100],n;

VPLL tofill;
bool sudoku(int i){
    if(i==SZ(tofill))return true;
    LL x=tofill[i].F,y=tofill[i].S;
    for(int c=0;c<n*n;++c){
        if(!row[x][c] && !col[y][c] && !block[x/n+(y/n)*n][c]){
            row[x][c]=col[y][c]=block[x/n+(y/n)*n][c]=1;
            A[x][y]=c;
            if(sudoku(i+1))return true;
            row[x][c]=col[y][c]=block[x/n+(y/n)*n][c]=0;
            A[x][y]=-1;
        }
    }
    return false;
}
int main(){
    //freopen("in.txt","r",stdin);
    bool first=0;
    while(~RI(n) && n){
        if(first)puts("");
        first = 1;
        tofill.clear();
        REP(i,n*n)REP(j,n*n)A[i][j]=row[i][j]=col[i][j]=block[i][j]=0;
        REP(i,n*n)REP(j,n*n){
            RI(A[i][j]);--A[i][j];
            if(-1==A[i][j])tofill.PB(PLL(i,j));
            else row[i][A[i][j]]=1,col[j][A[i][j]]=1,block[i/n+(j/n)*n][A[i][j]]=1;
        }
        bool ok=sudoku(0);
        if(ok){
            REP(i,n*n){
                REP(j,n*n)printf("%s%lld",j?" ":"",A[i][j]+1);
                puts("");
            }
        }else{
            puts("NO SOLUTION");
        }
    }
}
