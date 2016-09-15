#include <iostream>
#include <utility>
#include <vector>
typedef std::pair<int,int> ii;
std::vector<std::pair<bool,ii>> bii;
int sudoku[9][9];
int _,head=0;
bool INPUT(){
    bii.clear(),head=0;
    if(~scanf("%d",&_)){
        for(int j=0;j<_*_;++j)
            for(int i=0;i<_*_;++i){
                scanf("%d",&sudoku[j][i]);
                if(sudoku[j][i]==0)
                    bii.push_back(std::pair<bool,ii>(0,ii(j,i)));
            }
        return true;
    }
    return false;
}
inline bool isfill(int x,int y, int i){
    int blockx=x/_,blocky=y/_;
    for(int k=0;k<_*_;++k)if(sudoku[x][k]==i||sudoku[k][y]==i)return false;
    for(int k=0;k<_*_;++k)if(sudoku[_*blockx+k/_][_*blocky+k%_]==i)return false;
    return true;
}
bool dfs(int s){
    bool ok=0;
    if(s==bii.size()){
        for(int i=0;i<_*_;i++){
            for(int j=0;j<_*_;j++){
                printf("%d%*s",sudoku[i][j],j==_*_-1?0:1,"");
            }
            printf("\n");
        }
        printf("\n");
        return true;
    }
    else{
        int x=bii[head].second.first,y=bii[head].second.second;
        for(int i=1;i<=_*_;++i){//fill in order
            if(isfill(x,y,i)){//if ok fill else do nothing
                sudoku[x][y]=i;
                ++head;
                if(dfs(s+1)) ok=1;
                --head;
                sudoku[x][y]=0;
            }
        }
        
    }
    return ok;
}

int main(){
    while(INPUT()){
        if(!dfs(0)) printf("NO SOLUTION\n\n");
    }
}