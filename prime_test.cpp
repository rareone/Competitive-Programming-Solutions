#include <iostream>
int table[]={2	,3	,5	,7	,11	,13	,17	,19	,23
    ,29	,31	,37	};

using namespace std;
typedef long long int lli;
typedef unsigned int ui;

lli mul(lli a,lli b,lli mod){
    if((a<1000000 && b<10000000)||a==1||b==1)return a*b%mod;
    ui A[13];for(int i=0;i<13;++i){A[i]=a%10;a/=10;}
    ui B[13];for(int i=0;i<13;++i){B[i]=b%10;b/=10;}
    ui sol[30]={0};
    for(int i=0;i<13;++i)
        for(int j=0;j<13;++j)
            sol[i+j]+=A[i]*B[j];
    lli solution=0;
    lli k=1;
    for(int i=0;i<30;++i){
        solution=(solution+sol[i]*k)%mod;
        k=k*10%mod;
    }
    return solution;
}
lli power(lli a,lli pow,lli mod){
    if(pow==0)return 1;
    else{
        lli t=power(a,pow/2,mod)%mod;
        return mul(mul(t, t, mod),(pow%2==0?1:a),mod);
    }
}

lli gcd(lli a,lli p){
    if(a%p==0)return p;
    else return gcd(p,a%p);
}



bool isprime(lli p){
    for(int i=0;i<12;++i){
        if(table[i]==p)return true;
        else if (p%table[i]==0)return false;
    }
    
    for(int i=0;i<12;++i){
        if(gcd(table[i],p)==1){
            lli p1=power(table[i], p-1, p),p2=power(table[i], (p-1)/2, p);
            if(p1!=1 ||(p2!=1 && p2!=p-1))
                return false;
        }
    }
    return true;
}
int main(){
    int sum=0;
    for(lli i=2;i<=1e7;++i){
        if(isprime(i))
            ++sum;
    }
    printf("%d\n",sum);
}