#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, bool> ii;//weight,right
queue<ii> ans;
int A[510],k,n,keystay,T[510];
void seive(){
    int key=0;
    for(int i=0;i<n;++i){
        if(A[i]){
            swap(A[i], A[key]);
            ++key;
        }
    }
    --n,--keystay;
}

bool ok(){
    int keyt=0;
    int sum=0;for(int i=0;i<n;++i)sum+=A[i];
    int sam=0;for(int j=0;j<k;++j)sam+=T[j];
    if(sum!=sam)return false;
    while (keyt<k ) {
        if(A[keyt]==T[keyt]){keyt++;continue;}
        int sum=0,max=0,min=INT_MAX,keya=keyt;
        while(sum<T[keyt] && keya<n ){sum+=A[keya],max=A[keya]>max?A[keya]:max,min=A[keya]<min?A[keya]:min;++keya;}
        if(sum!=T[keyt])return false;
        if(max==min)return false;
        keystay=keya;
        for(int i=keyt;i<keystay;++i){
            if(A[i]==max){
                if(i>keyt && A[i]>A[i-1]){
                    keya=i;break;
                }else if (i<keystay-1 && A[i]>A[i+1]){
                    keya=i;break;
                }
            }
        }
        while(A[keyt]<T[keyt]){
            if(keya>keyt and A[keya]>A[keya-1]){
                A[keya]+=A[keya-1];
                A[keya-1]=0;
                seive();
                ans.push(ii(keya+1,0));
                --keya;
            }else if(keya<keystay-1 and A[keya]>A[keya+1]){
                A[keya]+=A[keya+1];
                A[keya+1]=0;
                seive();
                ans.push(ii(keya+1,1));
            }
        }
        ++keyt;
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&A[i]);
    scanf("%d",&k);
    for(int i=0;i<k;++i)scanf("%d",&T[i]);
    if(ok()){
        printf("YES\n");
        while(!ans.empty()){
            printf("%d %c\n",ans.front().first,ans.front().second?'R':'L');
            ans.pop();
        }
    }else{
        printf("NO");
    }
}