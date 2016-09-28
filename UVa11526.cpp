#include <iostream>
//Proposition: n/(n/i)=i
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        long long int lli,res=0,d=1;
        scanf("%lld",&lli);
        if(lli<=0){printf("0\n");continue;}
        //Line 2 of orginal function will never be excuted
        while((d-1)!=lli){
            d=lli/(lli/d);
            res+=d*(lli/d-lli/(d+1));
            ++d;
        }
        printf("%lld\n",res);
    }
}