#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <complex>
#include <algorithm>
#include "limits.h"
#include <queue>
#include <sstream>
#include <bitset>
#define INF 1e18
#define MAXN 200000
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
typedef complex<int> pt;
ll n,m,k;
inline bool tryk(ll tr){
    ll pre=0;
    if(tr>k){
        pre+=(2*tr-k+1)*k/2;
    }else{
        pre+=tr*(tr+1)/2;
        pre+=k-tr;
    }
    if(n-k>tr-1){
        pre+=n-k-tr+1;
        pre+=(tr-1)*tr/2;
    }else{
        pre+=(n-k)*(2*tr-n+k-1)/2;
    }
    return m>=pre;
}

int main(){
    cin>>n>>m>>k;
    
    
    ll low = 1,high = 2*m;
    
    while (low < high-1)
    {
        ll mid = (low + high) / 2;
        if(tryk(mid)){
            low=mid;
        }else{
            high=mid;
        }
    }
    cout<<low;
}
