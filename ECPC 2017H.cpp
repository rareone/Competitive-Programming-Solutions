#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
#define FL(i,j,k) for(int i=j;i<k;++i)
int dp[10][10][10]={0};
int ta[10][10][10]={0};
int Hos(int x,int y,int z){
    if(x<0||y>9||z>9)return 0;
    if(dp[x][y][z]!=-1)return dp[x][y][z];
    else return dp[x][y][z]=ta[x][y][z]+max(Hos(x-1, y, z), max(Hos(x, y+1, z), Hos(x, y, z+1)));
}
int main(){
    freopen("commandos.in", "r", stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);
    int T;cin>>T;
    FL(i, 0, T){
        memset(dp, -1, sizeof(dp));
        memset(ta, 0, sizeof(ta));
        int F,Y,X,H,N;cin>>N;
        FL(i, 0, N){
            cin>>F>>Y>>X>>H;--F,--Y,--X;ta[F][Y][X]=H;
        }
        cout<<Hos(9, 0, 0)<<'\n';
    }
}
