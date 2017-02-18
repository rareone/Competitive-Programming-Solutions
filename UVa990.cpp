#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define FL(i,j,k) for(int i=j;i<k;++i)
#define eat(a) int a;scanf("%d",&a)

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vector<int> ansi;
ll dp[32][1010],cost[30],value[30];
int main(void)
{
    int V,m,t;bool flag=0;
    while(~scanf("%d %d",&V,&m)){
        if(flag)puts("");
        flag=1;
        scanf("%d",&t);
        FL(i, 0, t){
            scanf("%lld %lld",cost+i,value+i);cost[i]*=3*m;
        }
        memset(dp, 0, sizeof(dp));
        FL(i, 1, t+1)FL(j, 0, V+1)dp[i][j]=max(dp[i-1][j],j-cost[i-1]>=0?dp[i-1][j-cost[i-1]]+value[i-1]:0);
        printf("%lld\n",dp[t][V]);
        ansi.clear();
        int curV=V,curt=t;
        for(int t=curt;t>0;--t){
            if(dp[t][curV]==dp[t-1][curV])continue;
            else {
                ansi.push_back(t);
                curV-=cost[t-1];
            }
        }
        printf("%d\n",ansi.size());FL(i, 0, ansi.size()/2)swap(ansi[i],ansi[ansi.size()-i-1]);
        for(int i:ansi)printf("%d %d\n",cost[i-1]/3/m , value[i-1]);
    }
}
