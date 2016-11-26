#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
const int MAXN=2e5+10;
#define LLM 9223372036854775807LL
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
#define FL(i,j,k) for(int i=j;i<k;++i)

int main(){
    ll a[MAXN],b[MAXN],c[MAXN],d[MAXN],n,m,k,sec,mana;
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>k>>sec>>mana;
    FL(i, 0, m)cin>>a[i];
    FL(i, 0, m)cin>>b[i];
    FL(i, 0, k)cin>>c[i];
    FL(i, 0, k)cin>>d[i];
    
    ll ans=(n-c[upper_bound(d, d+k, mana)-d-1])*sec;
    FL(i, 0, m){
        if(b[i]<=mana)
            ans=min(ans, (n-c[upper_bound(d, d+k, mana-b[i])-d-1])*a[i]);
    }
    cout<<ans;
}
