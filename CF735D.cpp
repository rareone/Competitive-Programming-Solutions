#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include "limits.h"
#define f first
#define s second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;

ll Multiply(ll a,ll b,ll m){
    if(((a%=m)<INT_MAX && (b%=m)<INT_MAX)||a<100||b<100)
        return a*b%m;
    ll sa=a/10,r=a%10,sb=b/10,k=b%10;
    return (100*Multiply(sa,sb,m)+10*k*sa+10*r*sb+r*k)%m;
}

ll PowerUnderMod(ll base,ll power,ll mod){
    if(!power)
        return 1;
    ll stay=PowerUnderMod(base, power/2, mod);
    return Multiply(Multiply(stay, stay, mod),power%2?base:1,mod);
}

ii Exd_gcd(ll a,ll b){
    if(!(a%b))
        return ii(0,1);
    ii stay=Exd_gcd(b, a%b);
    return ii(stay.s,stay.f-a/b*stay.s);
}

inline ll GCDNum(ll a,ll b){
    ii gcdnumber = Exd_gcd(a, b);
    return gcdnumber.f*a+gcdnumber.s*b;
}

inline ll Inverse(ll b,ll prime){
    return (Exd_gcd(b,prime).f+prime)%prime;
}

//Input: two integer a,b
//Output: x,y in the font of pair<int,int> s.t. ax+by=gcd(a,b)

ll _12PrimeTable[]={2,3,5,7,11,13,17,19,23,29,31,37};
ll Miller_Rabin(ll testnumber){//1 then true, other than factorial
    for(ll prime: _12PrimeTable){
        if(testnumber==prime)return 1;
        else if (!(testnumber%prime)) return 0;
    }
    ll d=testnumber-1,q=0;while(!(d%2)) d/=2,++q;
    for(ll p: _12PrimeTable){
        ll t=PowerUnderMod(p, d, testnumber),r=0;
        if(t==1)continue;
        for(;r<q;++r,t=Multiply(t, t, testnumber))
            if(t==testnumber-1)
                break;
        if(t==testnumber-1)
            continue;
        return  0;
    }
    return 1;
}

int main(){
    int N;cin>>N;
    if(Miller_Rabin(N)==1){
        printf("1");return 0;
    }
    else if(N%2==0)printf("2");
    else{
        if(Miller_Rabin(N-2)==1){
            printf("2");
        }else{
            printf("3");
        }
    }
}
