#include <iostream>
#include <queue>
#include <utility>
#define MAXN 105
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

using namespace std;
typedef pair<int,int> ii;

char s[100];
int R,C;
priority_queue<pair<int,ii>,vector<pair<int,ii>>,greater<pair<int,ii>>> pq;

int board_num[MAXN][MAXN];
int board_hig[MAXN][MAXN];

inline bool isable(int x,int y,int weight){
    if(x<0||y<0||x>=R||y>=C)return false;
    if(weight<=board_num[x][y]) return false;
    //要按照定義，我寫小於不等於會給我WA，哭哭誒
    return true;
}

inline void Input(){
    scanf("%s%d%d",s,&R,&C);
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j){
            scanf("%d",&board_num[i][j]);
            board_hig[i][j]=1;
            pq.push(pair<int,ii>(board_num[i][j],ii(i,j)));
        }
}

int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        Input();
        while(!pq.empty()){
            int weight=pq.top().first, x=pq.top().second.first,y=pq.top().second.second;
            pq.pop();
            for(short i=0;i<4;++i){
                if(isable(x+dx[i], y+dy[i],weight))
                    board_hig[x][y]=board_hig[x][y]>(board_hig[x+dx[i]][y+dy[i]]+1)?board_hig[x][y]:(board_hig[x+dx[i]][y+dy[i]]+1);
            }
        }
        int max=0;
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                max=max>board_hig[i][j]?max:board_hig[i][j];
        printf("%s: %d\n",s,max);
    }
}