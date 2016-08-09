#include <queue>
#include <vector>
#include <iostream>
#include <utility>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> ii;
typedef int i;
vector<vector<int>> mtdis;
vector<vector<int>> mt;
void Dikstra(int i, int j,bool o=0){//o:isdownward
    if(i==0 and j==0);
    else if(o){
        mt[i][j].first=mt[i][j].first>(mt[i-1][j].first+mt[i][j].second)?mt[i-1][j].first+mt[i][j].second:mt[i][j].first;
    }else{
        mt[i][j].first=mt[i][j].first>(mt[i][j-1].first+mt[i][j].second)?mt[i][j-1].first+mt[i][j].second:mt[i][j].first;
    }
    if(i<mt.size()-1)Dikstra(i+1, j,1);
    if(j<mt[i].size()-1) Dikstra(i, j+1,0);
}
int main(){
    i casenum;
    i row,column;
    scanf("%d",&casenum);
    while(casenum--){
        mt.clear();
        scanf("%d\n%d\n",&row,&column);
        priority_queue<ii> R;//
        mt.resize(row);
        for(size_t i=0;i<row;i++){
            for(size_t j=0;j<column;j++){
                int mtd;
                scanf("%d",&mtd);
                mt[i].push_back(INF);//(distance,matrix_number)
                mtdis[i].push_back(mtd);
            }
        }
        mt[0][0].first=mt[0][0].second;
        Dikstra(0,0);
        printf("%d\n",mt[mt.size()-1][mt[0].size()-1].first);
    }
    return 0;
}


