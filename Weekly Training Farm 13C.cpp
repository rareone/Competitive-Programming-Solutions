#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define FL(i,s,n) for(int i=s;i<n;++i)
#define M INT_MAX/2
#define N 0
using namespace std;
typedef pair<int, int> ii;
int B[1024][1024];
int s[4]={0,2,-1,-100000};
int b[4]={-100000,0,2,-1};
int small(){
    static int t=0;
    return --t;
}
int large(){
    static int t=0;
    return M+t++;
}
int main(){
    int n;scanf("%d",&n);printf("%d\n",n);
    FL(i,0, n)FL(j,0,n)B[j][i]=i%2?small():large();
    FL(i,0,n/4+2)B[4*i+3][0]=small();
    FL(i,0, n/4+2)B[4*i+1][n-1]=small();
    FL(i,0, n){FL(j,0,n)printf("%d ",B[i][j]);printf("\n");}
}
