#include <iostream>
#define MAXN  100010
int A[MAXN],B[MAXN],S[MAXN];

//小心溢位，之前因為這樣錯死
//用mergesort找出有幾個inversion
//奇數偶數互不可交換
//前一題水所以沒放

long long int countinversion(int *A,int begin,int end){//A[begin,end)
    if(begin+1==end)return 0;
    long long int a=countinversion(A,begin, (begin+end)/2);
    long long int b=countinversion(A,(begin+end)/2, end);
    int keyb=begin,keye=(begin+end)/2;
    long long int c=0,hold=begin,it=begin;
    while(keyb!=(begin+end)/2 && keye!=end){
        if(A[keyb]>A[keye]){
            while(it!=(begin+end)/2 && A[it]>A[keye])++it;
            c+=it-begin;
            S[hold++]=A[keye++];
        }else S[hold++]=A[keyb++];
    }
    while(keyb!=(begin+end)/2) S[hold++]=A[keyb++];
    while(keye!=end) {
        while(it!=(begin+end)/2 && A[it]>A[keye])++it;
        c+=it-begin;
        S[hold++]=A[keye++];
    }
    for(int i=begin;i<end;++i) A[i]=S[i];
    return a+b+c;
}

int main(){
    
    int n;scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&A[i]);
    for(int i=0;i<n;++i) scanf("%d",&B[i]);
    printf("%s\n",(  countinversion(A, 0, n)%2   ==   countinversion(B, 0, n)%2  )?"Possible":"Impossible");
    
}
