#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>
#define MINF INT_MIN
using namespace std;
typedef pair<int,int> ii;
ii a[100];//(bottle, soda)
int dp[101][101][10001];
int sum=0,k=0,sums=0,bottle;
bool is[101];
inline int DP(int k,int begin=0){
    if(k==0)return sum>=sums?0:MINF;
    if(bottle-begin<k) return MINF;
    if(dp[k][begin][sum]!=MINF) return dp[k][begin][sum];
    int ma=MINF;
    for(int i=begin;i<bottle;++i){
        sum+=a[i].first;
        int m=DP(k-1,i+1)+a[i].second;
        sum-=a[i].first;
        ma=max(ma, m);
    }
    return dp[k][begin][sum]=ma;
}

int main(){
    cin>>bottle;
    for (int i=0; i<bottle; ++i){cin>>a[i].second;sums+=a[i].second;}
    for (int i=0; i<bottle; ++i)cin>>a[i].first;
    sort(a,a+bottle,[&](ii x,ii b){return b<x;});
    while (sum<sums) sum+=a[k++].first;
    sum=0;
    for(int i=0;i<101;++i)for(int j=0;j<101;++j)for(int k=0;k<10001;++k)dp[i][j][k]=MINF;
    printf("%d %d",k,sums-DP(k));
}