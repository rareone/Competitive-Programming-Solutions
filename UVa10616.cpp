#include <iostream>
#include <cstring>
#include <algorithm>
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;


int A[200],has[2][21][11];

int main(){
    //freopen("in.txt", "r", stdin);
    int Q,N,D,M,setN=0;
    while (~scanf("%d %d",&N,&Q)) {
        if(!N && !Q)return 0;
        printf("SET %d:\n",++setN);
        FL(i, 0, N)scanf("%d",A+i);
        int QueN=0;M=max(M, N);
        while (Q--) {
            scanf("%d %d",&D,&M);
            memset(has, 0, sizeof(has));
            has[0][0][0]=1;
            FL(i, 1, N+1){
                int r=A[i-1]%D+D;r%=D;
                FL(j, 0, D)FL(k, 0, M+1)
                    has[i%2][(r+j)%D][k]=has[(i&1)^1][(r+j)%D][k]+(k==0?0:has[(i&1)^1][j][k-1]);
            }
            printf("QUERY %d: %d\n",++QueN,has[N%2][0][M]);
        }
    }
}
