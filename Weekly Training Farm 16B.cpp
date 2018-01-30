#include <iostream>
#define FL(i,j,k) for(int i=0;i<k;++i)
using namespace std;
const int log=20;
long long A[1<<log]={0},B[1<<log]={0};

void findpdt(long long *P, int k=log,bool inv=0){
    for (int len = 1; 2 * len <= (1<<k); len <<= 1)
        for (int i = 0; i < (1<<k); i += 2 * len)
            for (int j = 0; j < len; ++j) {
                long long u = P[i + j] , v = P[i + len + j];
                if (!inv) P[i + j] = u , P[i + len + j] = u + v;
                else {
                    P[i + j] = v , P[i + len + j] = v - u;
                }
            }
}
void findalong(long long *P, int k=log){
    for (int len = 1; 2 * len <= (1<<k); len <<= 1)
        for (int i = 0; i < (1<<k); i += 2 * len)
            for (int j = 0; j < len; ++j) {
                long long u = P[i + j] , v = P[i + len + j];
                P[i + j] = u + v , P[i + len + j] = v;
            }
}
long long int Ans[1<<20];
int main(){
    ios_base::sync_with_stdio(false);
    int n,m;cin>>n>>m;string c;
    FL(i, 0, n){
        int a=0;
        cin>>c;
        FL(i, 0, 20){
            if(c[i]-'0')a+=(1<<i);
        }
        ++A[a],++B[a];
    }
    findpdt(A),findalong(B);
    FL(i, 0, 1<<20)Ans[i]=A[i]*A[i];
    findpdt(Ans,20,true);
    FL(i, 0, m){
        int a=0;
        cin>>c;
        FL(j, 0, 20){
            if(c[j]-'0')a+=(1<<j);
        }
        cout<<(Ans[a]-B[a])/2<<'\n';
    }
}
//http://codeforces.com/group/gRkn7bDfsN/contest/210418/problem/B3
