#include <iostream>
#include <vector>
#include <sstream>
#include <utility>
#include <cmath>
#include <map>
using namespace std;
#define FL(i,j,k) for(int i=j;i<k;++i)
#define eat(ss) ss.clear();getline(cin,s);ss<<s;
typedef long long ll;
typedef pair<int, int > ii;
int board[1000][1000];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
string s;
int a=0,b=0,ten=1;
inline bool inside(int i,int j){
    if(board[i][j]==-1)return false;
    if(i<0||j<0||j>=b||i>=a)return false;
    return true;
}
int main(){
    //freopen("in.txt", "r", stdin);
    while (1) {
        getline(cin,s);
        a=0,b=0,ten=1;bool swi=1;
        for(char c:s){
            if(c<'0'||c>'9'){
                if(swi){swi=0,ten=1;continue;}
                else break;
            }
            if(swi)a+=(c-'0')*ten,ten*=10;
            else b+=(c-'0')*ten,ten*=10;
        }
        FL(i, 0, a){
            getline(cin, s);
            FL(j, 0, b)board[i][j]=(s[j]=='0'?0:-1);
        }
        int x=a-1,y=0,k=0;
        while (board[a-1][0]==0||x!=a-1||y!=0) {
            if(inside(x+dx[(k+1)%4],y+dy[(k+1)%4]))k=(k+1)%4;
            while(!inside(x+dx[k], y+dy[k]))k=(k+1)%4;
            ++board[x][y],x+=dx[k],y+=dy[k];
            FL(i, 0, a){
                FL(j, 0, b){
                    printf("%5d ",board[i][j]);
                }puts("");
            }puts("");


        }
        int have[5]={0};
        FL(i, 0, a)FL(j, 0, b)if(board[i][j]!=-1&&board[i][j]<5)++have[board[i][j]];
        FL(i, 0, 5)printf("%3d",have[i]);
        puts("");
    }
}
