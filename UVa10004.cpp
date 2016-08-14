#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdio>
#include <queue>
#define unvisited -1
using namespace std;
typedef vector<int> vi;
typedef vector<vi> mtx;
mtx adjlist;
bool checkbi(int u,vi & deg){
    vi color(deg.size(),unvisited);
    queue<int> R;
    
    R.push(u);
    color[u]=0;
    
    bool ok=1;
    while(ok && !R.empty()){
        u=R.front();R.pop();
        for(size_t i=0;i<adjlist[u].size();i++){
            if(color[adjlist[u][i]]==unvisited){
                color[adjlist[u][i]]=1-color[u];
                R.push(adjlist[u][i]);
            }else if(color[adjlist[u][i]]!=unvisited & color[adjlist[u][i]]==color[u]){
                ok=false;break;
            }
        }
        
    }
    return ok;
}
int main(){
    
    int vertices;
    int edges;
    string s;
    
    while(scanf("%d\n",&vertices)){
        if(vertices==0)break;
        
        bool ok=true;
        
        scanf("%d\n",&edges);
        
        adjlist.clear();
        adjlist.resize(vertices);
        vi degminus(vertices,0);
        
        while(edges--){
            getline(cin,s);
            int a,b;
            stringstream ss;
            ss<<s;
            ss>>a>>b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
            degminus[b]++;
        }
        
        for(size_t i=0;i<vertices&&ok;i++){
            if(degminus[i]==0)
                ok=checkbi(i,degminus);}
        printf("%sBICOLORABLE.\n",ok?"":"NOT ");
    }
    return 0;
}