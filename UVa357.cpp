#include <bits/stdc++.h>
//#include "bits:stdc++.h"
#define MAXN 200
#define FL(i,j,k) for(int i=j;i<k;++i)
#define eat(a) int a;scanf("%d",&a);
using namespace std;
typedef long long int ll;
ll dp[30001]={0},c[5]={1,5,10,25,50},a;
int main(){
    dp[0]=1;
    FL(j, 0, 5)FL(C, 1, 30001){
        if(C-c[j]>=0)dp[C]+=dp[C-c[j]];
    }
    while (~scanf("%d",&a)){
        if(dp[a]==1){
            printf("There is only 1 way to produce %lld cents change.\n",a);
        }else{
            printf("There are %lld ways to produce %lld cents change.\n",dp[a],a);
        }
    }
}
