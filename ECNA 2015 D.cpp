#include <iostream>
#include <cmath>
#include <cstring>
#define INT_MAX 2147483647
#define FL(i,j,n) for(int i=j;i<n;++i)
using namespace std;
typedef  pair<int, int> ii;

int dp[100][100]={0},n,m,
    sx[4]={1,-1,0,0},
    sy[4]={0,0,-1,1};
inline bool inside(int i,int j){
    return !(i<0||j<0||i>=n||j>=m);
}

int buttomup(){
    int ring=0;
    FL(ww, 1, 51){
        FL(i, 0, n){
            FL(j, 0, m){
                if(dp[i][j]<INT_MAX)continue;
                ring=ww;
                FL(k, 0, 4){
                    if(!inside(i+sx[k],j+sy[k])){
                        dp[i][j]=1;break;}
                    else if(dp[i+sx[k]][j+sy[k]]==ww-1){
                        dp[i][j]=ww;break;
                    }
                }
            }
        }
    }
    return ring;
}
int main(){
    while(~scanf("%d %d\n",&n,&m)){
        memset(dp, 0, sizeof(dp));
        string s;
        FL(i, 0, n){
            getline(cin, s);
            FL(j, 0, m) dp[i][j]=s[j]=='T'?INT_MAX:0;
        }
        int r=buttomup()>=10?3:2;
        FL(i, 0, n){
            FL(j, 0, m){
                int st[3]={0},a=dp[i][j];
                FL(i,0,3) st[i]=a%10,a/=10;
                bool ok=1;
                FL(i,0,r){
                    if(st[r-i-1]==0 && ok){
                        printf(".");
                        continue;
                    }
                    ok=0;
                    printf("%c",st[r-i-1]+'0');
                }
            }
            printf("\n");
        }
    }
};
    
