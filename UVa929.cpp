#include <bits/stdc++.h>
//#include "bits:stdc++.h"
#define MAXN 200
#define FL(i,j,k) for(int i=j;i<k;++i)
#define eat(a) int a;scanf("%d",&a);
using namespace std;

typedef pair<int, int> ii;//dis,place

int grid[1000][1000];
int d[1000][1000],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main(){
    eat(T)
    while (T--) {
        eat(R)eat(C)
        FL(i, 0, R)FL(j,0,C){scanf("%d",&grid[i][j]);d[i][j]=1e9;}
        d[0][0]=grid[0][0];priority_queue<ii,vector<ii>,greater<ii>> q;q.push(ii(grid[0][0],0));
        while(!q.empty()){
            int dis=q.top().first,p=q.top().second,x=p/1000,y=p%1000;
            q.pop();
            if(d[x][y]<dis)continue;
            FL(i, 0, 4){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0||nx>=R||ny<0||ny>=C)continue;
                if(d[x][y]+grid[nx][ny]<d[nx][ny]){
                    d[nx][ny]=d[x][y]+grid[nx][ny];
                    q.push(ii(d[nx][ny],nx*1000+ny));
                }
            }
        }
        printf("%d\n",d[R-1][C-1]);
    }
}
