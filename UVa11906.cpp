#include <iostream>
#include <utility>
#include <vector>
#define VISITED -1
#define UNVISITED 1
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;
int odd=0,even=0;
vector<vi> square;
int casenum,R,C,M,N,W;
inline void iseven(int a){
    if(a%2==1)odd++;
    else if(a!=0) even++;
}

int dfs(int i, int j){
    if((((i>=0 && i<R) && (j>=0 && j<C) ) && square[i][j]==0)){
        square[i][j]=1;
        if(M==N) square[i][j]=dfs(i+M,j+M)+dfs(i+M,j-M)+dfs(i-M,j+M)+dfs(i-M,j-M);
        else if(N==0) square[i][j]=dfs(i,j+M)+dfs(i,j-M)+dfs(i-M,j)+dfs(i-M,j);
        else if(M==0)square[i][j]=dfs(i,j+N)+dfs(i,j-N)+dfs(i-N,j)+dfs(i+N,j);
        else{
            square[i][j]=dfs(i+M,j+N)+dfs(i+M,j-N)+dfs(i-M,j+N)+dfs(i-M,j-N)+
                   dfs(i+N,j+M)+dfs(i+N,j-M)+dfs(i-N,j+M)+dfs(i-N,j-M);
        }
        return 1;
    }
    else if((((i>=0 && i<R) && (j>=0 && j<C) ) && square[i][j]>0)) return 1;
    else return 0;
}

int main(){
    scanf("%d",&casenum);
    for(size_t h=0;h<casenum;h++){
        square.clear();
        odd=0;even=0;
        scanf("%d %d %d %d\n%d",&R,&C,&M,&N,&W);
        vii water(W);
        while(W--){scanf("%d %d",&water[W].first,&water[W].second);}
        for(size_t i=0;i<R;i++){
            vi row(C,0);
            square.push_back(row);
        }
        for(size_t i=0;i<water.size();i++){square[water[i].first][water[i].second]=-1;}
        dfs(0,0);
        for(size_t i=0;i<R;i++){
            for(size_t j=0;j<C;j++){
                if(square[i][j]>0){
                    if(square[i][j]%2==0) even++;
                    else odd++;
                }
            }
        }
        if(odd==0 and even==0) even=1;
        printf("Case %d: %d %d\n",(int)h+1,even,odd);
    }
}

