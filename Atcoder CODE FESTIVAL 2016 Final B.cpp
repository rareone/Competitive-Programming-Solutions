#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#define MAXN 500
#define FL(i,j,k) for(ll i=j;i<k;++i)
using namespace std;
typedef long long int ll;
ll N;
int main(){
    cin>>N;
    ll n=(sqrt(1+8*N)-1)/2;
    ll k=N-n*(n+1)/2;
    if(k==0){
        FL(i, 0, n)cout<<i+1<<'\n';
    }
    else{
        FL(i, 0, n+1){
            if(i!=n-k){
                cout<<i+1<<'\n';
            }
        }
    }
}
