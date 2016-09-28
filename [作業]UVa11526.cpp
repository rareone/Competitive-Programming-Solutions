#include <iostream>
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        long long int lli,res=0,d=1;
        scanf("%lld",&lli);
        if(lli<=0){printf("0\n");continue;}
        //Line 2 of orginal function will never be excuted
        while((d-1)!=lli){//剛剛算的是1
            d=lli/(lli/d);
            // lli=dq+r ; 0<=r<q 不代表 0<=r<d
            //讓d增加到臨界整數(i.e. d=d+1使上述的q改變）
            res+=d*(lli/d-lli/(d+1));
            //計算所有迴圈會加d的整數，從lli/d至lli/(d+1)+1
            ++d;
            //下一次d計算是直接過臨界整數
        }
        printf("%lld\n",res);
    }
}
