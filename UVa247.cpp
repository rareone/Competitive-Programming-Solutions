#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <stack>
#include <map>
#include <cstdio>
#include <algorithm>
#include <fstream>
#define unvisited -1

using namespace std;
ifstream f;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> adj;
size_t compnum=0;
vi dfs_num;
vi dfs_low;
vector<bool> inpath;
stack<int> path;
map<string, int> m;
string inttostring[25];

inline bool Input(){
    stringstream ss;
    string s;
    int V,E;
    size_t i=0;
    string name1,name2;
    adj.clear();
    dfs_low.clear();
    dfs_num.clear();
    while(path.size())path.pop();
    m.clear();
    compnum=0;
    memset(inttostring,0, sizeof(inttostring));
    
    getline(f,s);
    ss<<s;
    ss>>V>>E;
    
    if (!V and !E) return false;
    dfs_low.assign(V, unvisited);
    dfs_num.assign(V, unvisited);
    adj.resize(V);
    inpath.assign(V,0);
    
    while(E--){
        getline(f,s);
        stringstream ss;
        ss<<s;
        ss>>name1>>name2;
        if(!m[name1]&& inttostring[0]!=name1){m[name1]=(int)i;inttostring[i++]=name1;}
        if(!m[name2]&& inttostring[0]!=name2){m[name2]=(int)i;inttostring[i++]=name2;}
        adj[m[name1]].push_back(m[name2]);
    }
    return true;
}
void tarjan(int u){
    dfs_num[u]=dfs_low[u]=(int)compnum++;
    path.push(u);
    inpath[u]=1;
    for(size_t i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(dfs_num[v]==unvisited){
            tarjan(v);
        }
        if(inpath[v])dfs_low[u]=dfs_low[u]<dfs_low[v]?dfs_low[u]:dfs_low[v];
    }
    if(dfs_num[u]==dfs_low[u]){
        int s;
        while(!path.empty()){
            s=path.top();path.pop();inpath[s]=0;
            printf("%s%s",inttostring[s].c_str(),s==u?"\n":", ");
            if(s==u) break;
        }
    }
}

int main(){
    f.open("/Users/DannelApple/Library/Developer/Xcode/DerivedData/UVa_Playground-dqeptcojwilitvbhtdkqnqwsqris/Build/Products/Debug/test.txt",ios::in);
    int casenum=1;
    while(Input()){
        printf("Calling circles for data set %d:\n",casenum++);
        int a=(int)adj.size();
        for(size_t i=0;(int)i<a;i++){
            if(dfs_num[i]==unvisited)
                tarjan((int)i);
        }
        printf("\n");
    }
    return 0;
}