#include <iostream>
#include "memory.h"
#define MAXN 3000
short num[MAXN]={0};
bool v[MAXN]={0};
int id[MAXN]={0};

int main(){
    int a,b,head=0;
    while(~scanf("%d%d",&a,&b)){
        head=0;
        memset(id, 0, sizeof(id));
        memset(v,0,sizeof(v));
        memset(num,0,sizeof(num));
        
        printf("%d/%d = %d.",a,b,a/b);
        int l=0;
        a%=b;
        while(1){//再一次做到a/b還是不能用
            if(v[a])break;//and take all number from id[a] to head?
            v[a]=1,id[a]=head;
            a*=10;
            num[head++]=(a/b);
            a%=b;
        }
        for(int j=0;j<id[a];++j)printf("%d",num[j]);
        int c=id[a];
        printf("(");
        l=head-id[a];
        while(id[a]<head && c<50)
            printf("%d",num[id[a]++]),c++;
        if(c==50&&id[a]<head) printf("...");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n",l);
    }
}