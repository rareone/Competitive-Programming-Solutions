#include<iostream>
#include<cstring>
#define MAXN 100000
using namespace std;
long long int Sum[MAXN],P[MAXN],R[MAXN],N,A[MAXN],B[MAXN],Ans[MAXN]={0};
using namespace std;
int parent(int p){
    if(P[p]==p)return p;
    else return P[p]=parent(P[p]);
}
inline void UN(int a,int b){
    int A=parent(a),B=parent(b);
    if(A==B||Sum[b]==-1) return;
    if(R[A]<R[B]){P[A]=P[B];Sum[B]+=Sum[A];}
    else{
        R[A]+=R[A]==R[B];
        P[B]=P[A];Sum[A]+=Sum[B];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    memset(Sum, -1, sizeof(Sum));
    long long int max=0;
    for (int i=0; i<n; ++i) {cin>>A[i];P[i]=i;}
    for (int i=0; i<n; ++i) {cin>>B[i];R[i]=1;--B[i];}
    for (int i=n-1; i>0; --i){
        Ans[i]=max;
        Sum[B[i]]=A[B[i]];
        if(B[i]==0)UN(0, 1);
        else if(B[i]==n-1)UN(n-1, n-2);
        else UN(B[i],B[i]-1),UN(B[i], B[i]+1);
        max=Sum[parent(B[i])]>max?Sum[parent(B[i])]:max;
    }
    Ans[0]=max;
    for (int i=0; i<n; ++i){
        cout<<Ans[i]<<'\n';
    }
    
}