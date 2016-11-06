#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define FL(i,s,n) for(int i=s;i<n;++i)
using namespace std;
typedef pair<int, int> ii;
int board[1000][1000],d[2][1000][1000]={0};
bool v[2][1000][1000]={0};
//palce increasing
int N;
int increasing(){
    queue<pair<ii,bool>> q;
    q.push(make_pair(ii(0,0),1));
    v[0][0][0]=1;
    while (!q.empty()) {
        int x=q.front().first.first,y=q.front().first.second;
        if(x==y && x==N-1) return d[0][x][y];
        bool incr=!q.front().second; q.pop();
        if(x>0){
            if(!v[0][x-1][y] && (incr ^ (board[x][y]<board[x-1][y]))){
                v[0][x-1][y]=1;d[0][x-1][y]=d[0][x][y]+1;
                q.push(make_pair(ii(x-1,y),incr));
            }
        }
        if(x<N-1){
            if(!v[0][x+1][y] && (incr ^ (board[x][y]<board[x+1][y]))){
                v[0][x+1][y]=1;d[0][x+1][y]=d[0][x][y]+1;
                q.push(make_pair(ii(x+1,y),incr));
            }
        }
        if(y>0){
            if(!v[0][x][y-1] && (incr ^ (board[x][y]<board[x][y-1]))){
                v[0][x][y-1]=1;d[0][x][y-1]=d[0][x][y]+1;
                q.push(make_pair(ii(x,y-1),incr));
            }
        }
        if(y<N-1){
            if(!v[0][x][y+1] && (incr ^ (board[x][y]<board[x][y+1]))){
                v[0][x][y+1]=1;d[0][x][y+1]=d[0][x][y]+1;
                q.push(make_pair(ii(x,y+1),incr));
            }
        }
    }
    return INT_MAX;
}


int decreasing(){
    queue<pair<ii,bool>> q;
    q.push(make_pair(ii(0,0),0));
    v[1][0][0]=1;
    while (!q.empty()) {
        int x=q.front().first.first,y=q.front().first.second;
        if(x==y && x==N-1) return d[1][x][y];
        bool incr=!q.front().second; q.pop();
        if(x>0){
            if(!v[1][x-1][y] && (incr ^ (board[x][y]<board[x-1][y]))){
                v[1][x-1][y]=1;d[1][x-1][y]=d[1][x][y]+1;
                q.push(make_pair(ii(x-1,y),incr));
            }
        }
        if(x<N-1){
            if(!v[1][x+1][y] && (incr ^ (board[x][y]<board[x+1][y]))){
                v[1][x+1][y]=1;d[1][x+1][y]=d[1][x][y]+1;
                q.push(make_pair(ii(x+1,y),incr));
            }
        }
        if(y>0){
            if(!v[1][x][y-1] && (incr ^ (board[x][y]<board[x][y-1]))){
                v[1][x][y-1]=1;d[1][x][y-1]=d[1][x][y]+1;
                q.push(make_pair(ii(x,y-1),incr));
            }
        }
        if(y<N-1){
            if(!v[1][x][y+1] && (incr ^ (board[x][y]<board[x][y+1]))){
                v[1][x][y+1]=1;d[1][x][y+1]=d[1][x][y]+1;
                q.push(make_pair(ii(x,y+1),incr));
            }
        }
    }
    return INT_MAX;
}
int main(){
    scanf("%d",&N);
    FL(i, 0, N)FL(j, 0, N){int a;scanf("%d",&a);board[i][j]=a;d[0][i][j]=d[1][i][j]=INT_MAX;}
    d[0][0][0]=d[1][0][0]=0;
    int m=min(increasing(),decreasing());
    if(m==INT_MAX)printf("-1");
    else{
        printf("%d",m+1);
    }
}
