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
typedef unsigned long long LL;
using namespace std;

#define MAXN
LL D=26;
LL A[3]={8,26};
LL ft[10000000],gt[10000000];
const LL local[]={8,1216051011115013,10120030221151555,12242404381292882,25410412253578667,80102223030780566,101123090462613643,110101206216822686,112108357595459879,123691153290934804,174411222766360935,211007312114007485,300082096160111322,400122462126655620,521112010020395498,842019016319707337,1001811226094531891,1010282110232310028,1013926012005808433,1031105003819644521,1100016940799990412,1101750241901938611,1110313031186547801,1114101034044122487,1132000227025530879,1200143064701448415,1215100617364831285,1310304922929790272,1420820771741779888,1631501154459395374,2001320323749237687,2021402236020918977,2106157441430659702,2142111121236976671,2310300325690423244,3001022221621543630,3101130210825517027,3211808034200411344,4011050524396026847,4171104411932874032,5014100104231659503,5513122213376683912,6301501679430694219,7481401986572311122,9101089114380947766,10001514094511637959,10010211051524786835,10013202211814651378,10031001128421037306,10100011017103361315,10101502914354855364,10110222423070760797,10113530128085757262,10131181103111162107,10200110103073261494,10213410555361851540,10310111110031105623,10417090242787313385,10621260930591830778,11001010010021141065,11007010510369971893,11011218332063217774,11021201200077523196,11060315126178955239,11101011501118628154,11108011195675901606,11111707301118521500,11122010144141553455,11161212120918024208,11210151950518247712,11260023161020175616,11340456214236810728,11510471234475059982,11802110298479813195,12010091122963410705,12051430321032391554,12112001065043523700,12201315193445365586,12410306233067171773,13009101051207957132,13111001400319078923,13304815631960953182,14015104230866634663,14206111220744411080,15064132581175365643,16001112151202557087,16570104242205967213,18002116778736972192}
;
inline LL h(LL x){
    return ft[x/10000000/10000000]+ft[x%10000000]+ft[(x/10000000)%10000000]+gt[x/10000000/10000000]*gt[x%10000000]*gt[(x/10000000)%10000000]+10;
}
int main(){
    REP(i,10000000){
        LL x=i;
        ft[i]=0,gt[i]=1;
        for(;x;x/=10){
            ft[i]+=x%10;
            if(x%10)gt[i]*=x%10;
        }
    }
    DRI(a);--a;
    if(a<2){
        return 0*printf("%llu\n",A[a]);
    }int i=0;
    if(a<10000000){
        for(D=A[1];i<a-1;++i){
            D=D+h(D);
        }
    }else{
        for(D=local[a/10000000];i<(a)%10000000;++i){
            D=D+h(D);
        }
    }
    
    printf("%llu\n",D);
    /*
    REPP(i,2, a){
        D=D+h(D);
        if(i%10000000==0)printf(",%llu",D);
    }*/
}
