#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <climits>
#define f first
#define s second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
ll mul(ll a,ll b,ll m){
    if((a<2147483647 && b<2147483647)||a<10||b<10)return a*b%m;
    ll sa=a/10,r=a%10,sb=b/10,k=b%10;
    return (100*mul(sa,sb,m)+10*k*sa+10*r*sb+r*k)%m;
    
}
ii gcd(ll a,ll b){
    if(!(a%b))return ii(0,1);
    ii d=gcd(b, a%b);
    return ii(d.s,d.f-a/b*d.s);
}

inline ll inverse(ll b,ll p){return (gcd(b,p).f+p)%p;}

//Input: two integer a,b
//Output: x,y in the font of pair<int,int> s.t. ax+by=gcd(a,b)

ll pmod(ll b,ll p,ll m){
    if(!p) return 1;
    ll a=pmod(b, p/2, m);
    return mul(mul(a, a, m),(p%2?b:1),m);
}

//Input: three long long int base, power, mod
//Output: (base^power)%mod#include <vector>

ll table[]={2,3,5,7,11,13,17,19,23,29,31,37};
ll ab(ll p){
    if (p>0)return p;
    else return -p;
}
ll rho(ll C){//就有些要求來說，rho太慢了，O(n^1/4)
    const ll r=rand()%(C-1);
    ll d=1,p1=2,p2=2;
    while (d!=C) {
        p1=(mul(p1, p1,9223372036854775807)+r)%C,p2=(mul(p2, p2,9223372036854775807)+r)%C,p2=(mul(p2, p2, 9223372036854775807)+r)%C;
        ii g=gcd(ab((p1-p2)),C);
        d=g.f*(ab((p1-p2)))+g.s*C;
        if(d>1 && d<C) return d;
    }
    return rho(C);
}

ll isprime(ll k){//1 then true, other than factorial
    for(ll i=0,p=table[i];i<12;++i){
        if(k==p)return 1;
        else if (!(k%p)) return p;
    }
    ll d=k-1,q=0;while(!(d%2)) d/=2,++q;
    for(ll i=0,p=table[i];i<12;++i){
        ll t=pmod(p, d, k),r=0;
        if(t==1)continue;
        for(;r<q;++r,t=mul(t, t, k))if(t==k-1)break;
        if(t==k-1)continue;
        return rho(k);
    }
    return 1;
}
ll mi(ll b){
    ll k;
    if((k=isprime(b))==1)return b;
    else return min(k,mi(b/k));
}
int main(){
    int a;cin>>a;
    while(a--){
        ll b,a;cin>>a;
        b=isprime(a);
        if(b==1)cout<<"Prime\n";
        else cout<<min(mi(a/b),mi(b))<<"\n";
    }
}
