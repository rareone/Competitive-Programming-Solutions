#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define FL(i,j,k) for(int i=j;i<k;++i)
#define eat(a) int a;scanf("%d",&a)

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

priority_queue<ll,vector<ll>,greater<ll>> pq;
int main(void)
{
    ll sum=0,num=0;
    eat(m);
    while (m--) {
        eat(n);
        sum+=n;
        pq.push(n);
        while (sum<0)sum-=pq.top(),pq.pop(),++num;
    }
    cout<<num;
}
