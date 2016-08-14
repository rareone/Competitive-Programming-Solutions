#include <iostream>
#include <vector>
#include<list>
#include<sstream>
#include <utility>
#include <algorithm>
#define unvisited 0
#define visited 1
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
int maxc=1;
using namespace std;
typedef vector<char> vc;
typedef vector<vc> matrix;
typedef pair<int,int> ii;
matrix same;
vector<vector<bool>> ifvisited;
size_t componentnumber=0;
int component=0;

vector<vector<ii>> vl;
bool dfs(int i, int j,char c){
    if(i<0||i>=15||j<0||j>=10) return false;
    else if(ifvisited[i][j]==unvisited && same[i][j]==c && c!='O'){
        ifvisited[i][j]=visited;
        vl[componentnumber].push_back(make_pair(i, j));
        for(size_t d=0;d<4;d++)dfs(i+dc[d],j+dr[d],c);
        return true;
    }
    return false;
}
int maxcomponent(vector<vector<ii>> vl){
    maxc=1;
    component=-1;
    for(size_t i=0;i<componentnumber;i++){
        if(vl[i].size()>maxc){
            maxc=vl[i].size();
            component=i;
        }
    }
    return component;
}
void shift(){
    int stay=-1;
    for(size_t r=0;r<15;r++){
        if(same[r][0]=='O'&& stay==-1){stay=r;}
        else if(same[r][0]!='O' && stay!=-1){
            swap(same[r],same[stay]);
            stay++;
        }
    }
}
void deletecomponent(int a){
    for(size_t i=0;i<vl[a].size();i++){
        same[vl[a][i].first][vl[a][i].second]='O';
    }
    for(size_t i=0;i<same.size();i++){
        int stay=-1;
        for(size_t j=0;j<same[i].size();j++){
            if(same[i][j]=='O'&& stay==-1) {stay=j;}
            else if(same[i][j]!='O'&& stay!=-1){
                swap(same[i][j], same[i][stay]);
                stay++;
            }
        }
    }
}

int main(){
    int Case;
    cin>>Case;
    
    char a;
    string empty;
    stringstream ss;
    
    for(size_t game=0;game<Case;game++){
        printf("Game %d:\n\n",game+1);
        component=0;
        int move=0,score=0;
        same.clear();
        same.resize(15);
        getline(cin,empty);
        for(size_t i=0;i<15;i++){ same[i].resize(10);}
        for(size_t i=0;i<10;i++){
            getline(cin,empty);
            for(size_t j=0;j<15;j++){
                scanf("%c",&a);
                same[j][9-i]=a;
            }
        }
        while(component!=-1){
            componentnumber=0;
            vl.clear();
            vl.resize(1);
            ifvisited.clear();
            ifvisited.resize(15);for(size_t i=0;i<15;i++){ifvisited[i].resize(10,unvisited);}
            
            for(size_t i=0;i<150;i++)if(dfs(i%15,i/15,same[i%15][i/15])){componentnumber++;vl.push_back(vector<ii>(0));}
            
            int a=maxcomponent(vl);
            if(a>=0){
                score+=(maxc-2)*(maxc-2);
                ii min=vl[a][0];
                for(size_t i=0;i<vl[a].size();i++)min=min>vl[a][i]?vl[a][i]:min;
                printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",++move,1+min.second,1+min.first,maxc,same[vl[a].front().first][vl[a].front().second],(maxc-2)*(maxc-2));
                deletecomponent(a);
                shift();
            }
        }printf("Final score: %d, with %d balls remaining.\n",componentnumber==0?score+1000:score,componentnumber);
        if(game!=Case-1)printf("\n");
    }
}