#include <iostream>
#define MAXN 5000
#define var(a) int a;scanf("%d",&a);
#define FL(i,j,k) for(int i=j;i<k;++i)
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dp[MAXN]={0};
vector<int> adjin[MAXN];

int num(int v){
    if(dp[v]!=0)return dp[v];
    int max=0;
    for(int u: adjin[v]){
        max=num(u)>max?num(u):max;
    }
    return dp[v]=max+1;
}

int main(){
    var(A)var(B)var(E)var(P)
    while(P--){
        var(u)var(v)
        adjin[v].push_back(u);
    }
    FL(i, 0, E) num(i);
    sort(dp, dp+E);
    int N=dp[A-1];
    if(dp[A]>dp[A-1]){
        printf("%ld\n",count_if(dp,dp+E,[=](int a){return a<=N;}));
    }else{
        printf("%ld\n",count_if(dp,dp+E,[=](int a){return a<N;}));
    }
    int M=dp[B-1];
    if(dp[B]>dp[B-1]){
        printf("%ld\n",count_if(dp,dp+E,[=](int a){return a<=M;}));
    }else{
        printf("%ld\n",count_if(dp,dp+E,[=](int a){return a<M;}));
    }
    printf("%ld\n",count_if(dp,dp+E,[=](int a){return a>M;}));
}
