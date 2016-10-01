#include <iostream>
#include "memory.h"
using namespace std;
int arr[10],synb=0,t=0,n,hashss[10], alp[26]={0};
char s[10][10];

inline bool trynumber(){
    int sum=0,target=0;
    for(int i=0;i<n;++i){
        if(arr[alp[s[i][0]-'A']]==0)
            return false;
    }
    for(int i=0;i<n-1;++i){
        int thesum=0;
        for(int j=0;s[i][j];++j){
            thesum=thesum*10+arr[alp[s[i][j]-'A']];
        }
        sum+=thesum;
    }
    for(int j=0;j<s[n-1][j];++j){
        target=target*10+arr[alp[s[n-1][j]-'A']];
    }
    return sum==target;
}

int isvisited[10]={0};
void ans(int n=0){
    if(n==synb){
        if(trynumber()) ++t;
        return;
    }
    for(int i=0;i<10;++i){
        if(!isvisited[i]){
            arr[n]=i;
            isvisited[i]=1;
            ans(n+1);
            arr[n]=-1;
            isvisited[i]=0;
        }
    }
}
int main(){
    scanf("%d\n",&n);
    for(int i=0;i<n;++i){
        scanf("%s",s[i]);
    }
    memset(arr,-1,sizeof(arr));
    memset(alp,-1,sizeof(alp));
    for(int i=0;i<n;++i){
        for(int j=0;s[i][j];++j){
            if(alp[s[i][j]-'A']==-1) alp[s[i][j]-'A']=synb,hashss[synb++]=s[i][j]-'A';
        }
    }
    ans();
    printf("%d",t);
    
}