#include <iostream>
#define MAXN  100000
int A[MAXN],B[MAXN],S[MAXN];



//小心溢位，之前因為這樣錯死
//用mergesort找出有幾個inversion
//解決溢位位問題之後AC

long long int countinversion(int *A,int begin,int end){//A[begin,end)
    if(begin+1==end)return 0;
    long long int a=countinversion(A,begin, (begin+end)/2);
    long long int b=countinversion(A,(begin+end)/2, end);
    int keyb=begin,keye=(begin+end)/2,hold=begin;
    long long int c=0;
    while(keyb!=(begin+end)/2 && keye!=end){
        if(A[keyb]>A[keye]){
            c+=(begin+end)/2-keyb;
            S[hold++]=A[keye++];
        }else S[hold++]=A[keyb++];
    }
    while(keyb!=(begin+end)/2) S[hold++]=A[keyb++];
    while(keye!=end) {
        S[hold++]=A[keye++];
    }
    for(int i=begin;i<end;++i) A[i]=S[i];
    return a+b+c;
}
int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;
    
    return inv_count;
}

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&A[i]);
    for(int i=0;i<n;++i) scanf("%d",&B[i]);
    printf("%s\n",(  countinversion(A, 0, n)%2   ==   countinversion(B, 0, n)%2  )?"Possible":"Impossible");
    
}
