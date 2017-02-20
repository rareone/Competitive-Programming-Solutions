#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define FL(i,j,k) for(int i=j;i<k;++i)
#define eat(a) ll a;cin>>a

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

ll A[100000];
int main(void)
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    eat(ts);eat(tf);eat(t);eat(n);
    FL(i, 0, n)cin>>A[i];
    if(n==0||A[0]>ts){
        cout<<ts;return 0;
    }
    ll at=A[0]-1,wt=ts,m=max(0ll,wt-A[0]+1);
    wt=max(ts+t,A[0]+t);
    FL(i, 1, n){
        if(A[i]==A[i-1]+1){wt=max(wt+t,A[i]+t);continue;}
        if(wt>=tf)break;
        if(m>wt-A[i]+1){
            m=max(0ll,wt-A[i]+1);
            at=A[i]-1;
        }
        wt=max(wt+t,A[i]+t);
    }
    if(tf-t>=wt)cout<<tf-t;
    else cout<<at;
    
}
