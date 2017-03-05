

#include <iostream>
#include <algorithm>
#include <cstring>
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
const int log=20;
typedef long long LL;
LL A[1<<log]={0,1,2,3,4,5,6,7},B[1<<log],w[1<<20]={1},tn;

const LL
pow2[9]= {      128,     1024,    16384,   131072,   262144,   524288,  1048576,  4194304},
prime[9]={      257,    12289,    65537,   786433,   786433,  5767169,  7340033,104857601},
a[9]=    {        2,       12,        4,        6,        3,       11,        7,       25},
gen[9]=  {        3,       11,        3,       10,       10,        3,        3,        3},
ks[9]=   {        7,       10,       14,       17,       18,       19,       20,       22};

size_t selec(LL n){return upper_bound(pow2,pow2+6,2*n+10)-pow2;}//N丟最大次項




LL stay[1<<log];
inline unsigned int bit_reverse(unsigned int a,LL len){
    a=((a&0x55555555U)<<1)|((a&0xAAAAAAAAU)>>1);
    a=((a&0x33333333U)<<2)|((a&0xCCCCCCCCU)>>2);
    a=((a&0x0F0F0F0FU)<<4)|((a&0xF0F0F0F0U)>>4);
    a=((a&0x00FF00FFU)<<8)|((a&0xFF00FF00U)>>8);
    a=((a&0x0000FFFFU)<<16)|((a&0xFFFF0000U)>>16);
    return a>>(32-len);
}
LL Power(LL b,LL p,LL mod){
    if(!p)return 1%mod;
    LL ans=1%mod;
    for (LL i=b; p; p>>=1,i=i*i%mod)if(p&1)ans=ans*i%mod;
    return ans;
}
void NTT(LL *P, LL k=ks[tn],bool inv=0){
    for (int i = 0; i < 1<<k; ++i)stay[i]=P[bit_reverse(i, k)];
    for (int i = 0; i < 1<<k; ++i)P[i]=stay[i];
    
    LL N=pow2[tn],p=prime[tn],g=Power(gen[tn],a[tn],p);
    for (int m = 2; m <= N; m<<=1){
        LL wm=Power(g, N/m, p),w=1;
        if(inv)wm=Power(wm, p-2, p);
        for(int j = 0; j < m/2; ++j){
            for(int k = j; k < N ; k+=m){
                LL t = w * P[ k + m/2 ] % p,u = P[ k ];
                P[k]=(u+t)%p,P[k+m/2]=(p+(u-t)%p)%p;
            }w=w*wm%p;
        }
    }
    if(inv){
        LL d=Power(N, p-2, p);
        for (int i = 0; i < 1<<k; ++i)P[i]=P[i]*d%p;
    }
}




int main(){
    //freopen("in.txt", "r", stdin);
    int n,m;
    while (~scanf("%d",&n)) {
        memset(A, 0, sizeof(A));A[0]=1;
        int mx=0;
        memset(B, 0, sizeof(B));
        int a;
        FL(i, 0, n){scanf("%d",&a);++A[a];mx=max(mx, a);}
        scanf("%d",&m);
        FL(i, 0, m){scanf("%d",&a);++B[a];}
        tn=selec(mx);
        NTT(A);
        FL(i, 0, pow2[tn])A[i]=A[i]*A[i]%prime[tn];
        NTT(A,ks[tn],true);
        int sum=0;
        FL(i, 0, pow2[tn])sum+=(A[i]!=0&&B[i]!=0);
        printf("%d\n",sum);
    }
    
}
