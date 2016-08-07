#include <iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
    int num, stay,sus;
    while(scanf("%d",&num)!=EOF){
        bool shut[3000]={0},ok=1;
        for(size_t i =0;i<num;i++){
            if(i>0){
                scanf("%d",&sus);
                unsigned int n=(sus-stay>0)?sus-stay:stay-sus;
                if(shut[n]==1 || (n==0||n>=num)){ok=0;}
                else{shut[n]=1;}
                stay=sus;
            }else{
                scanf("%d",&stay);
            }
        }
        if(ok) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}