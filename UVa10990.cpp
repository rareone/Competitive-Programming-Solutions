#include <iostream>
#include <vector>
#define MAXN 2000001
//Tons of DP
//Tons of DP
//Tons of DP
//Tons of DP
//Tons of DP
//Tons of DP
using namespace std;
int phif[MAXN]={0},sum[MAXN]={0},pd[MAXN]={0};
int phi(int n){
    if(phif[n])return phif[n];
    int ph=n;
    for(int i=2;i*i<=n;++i){
        bool ok=0;
        while(n%i==0){
            n/=i;
            ok=1;
        }
        ph=ok?ph/i*(i-1):ph;
    }
    if(n!=1) ph=ph/n*(n-1);
    phif[n]=ph;
    return ph;
}

int phidepth(int n){
    if(pd[n]) return pd[n];
    else pd[n]=phidepth(phi(n))+1;
    return  pd[n];
}
void sumbuttom_up(){
    for(int i=3;i<MAXN;++i){
        sum[i]=sum[i-1]+phidepth(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    pd[2]=1,sum[2]=1;
    sumbuttom_up();
    int cas;scanf("%d",&cas);
    while(cas--){
        int m,n;
        scanf("%d%d",&m,&n);
        printf("%d\n",sum[n]-sum[m-1]);
    }
}
