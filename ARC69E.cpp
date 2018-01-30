#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <queue>
#define FL(i,j,k) for(int i=j;i<k;++i)
#define eat(a) int a;scanf("%d",&a)

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll > ii;
priority_queue<int,vector<int>,greater<int>> pq;

ll A[100010]={0};
ii B[100010];
int main(void)
{
    eat(a);
    FL(i, 1, a+1){
        eat(b);
        B[i-1]=ii(b,i-1);
    }
    sort(B, B+a, [=](ii a,ii b){return b<a;});
    //int f=B[0].second;pq.push(B[0].second);
    //A[f]+=B[0].first-B[1].first;
    FL(i, 0, a){
        pq.push(B[i].second);
        if(B[i].first>B[i+1].first){
            A[pq.top()]+=(B[i].first-B[i+1].first)*(i+1);
        }
    }
    FL(i, 0, a)printf("%lld\n",A[i]);
}
