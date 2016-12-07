#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
#define FL(i,j,k) for(int i=j;i<k;++i)
const int N=1e9+7;
ll pow(ll b,ll p){
    if(p==0)return 1;
    ll t=pow(b, p/2);
    return ((t*t)%N)*(p%2?b:1)%N;
}
ii Exd_gcd(ll a,ll b){
    if(!(a%b))
        return ii(0,1);
    ii stay=Exd_gcd(b, a%b);
    return ii(stay.second,stay.first-a/b*stay.second);
}

inline ll Inverse(ll b){
    return (Exd_gcd(b,N).first+N)%N;
}

ll bio(ll a,ll b){
    if(b>a/2)b=a-b;
    ll s=1;
    FL(i, 0, b){
        s=s*(a-i)%N;
        s=s*Inverse(i+1)%N;
    }
    return s;
}
int main(){
    freopen("galactic.in", "r", stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll sum=0,T;cin>>T;
    FL(t, 0,T){
        ll G,C;cin>>G>>C;
        if(C>G){
            cout<<"0\n";
        }else{
            ll sum=0;
            FL(i, 0, C){
                sum=sum+(i%2?-1:1)*bio(C, i)*pow(C-i, G)%N;//排容原理，其實我沒有想得很清楚就AC惹＠＠
                sum%=N;
            }
            cout<<(sum+N)%N<<'\n';
        }
    }
}
