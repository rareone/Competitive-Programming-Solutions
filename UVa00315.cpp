#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <cstdio>
#define unvisited -1

using namespace std;
typedef vector<int> vi;
typedef vector<vi> adj;
adj ADJ;
vi parent;
vi dfs_num;
vi dfs_low;
int isav=0;
int dfsnumber=0,rootchildren=0;
bool V[100]={0};
bool Input(){
    string s;
    stringstream ss;
    int ver,edge;
    
    getline(cin, s);
    ss<<s;
    ss>>ver;
    if(ver==0) return false;
    
    while(ss>>edge){
        ADJ[ver-1].push_back(edge-1);
        ADJ[edge-1].push_back(ver-1);
    }
    return true;
}

void favb(int i,int dfsroot){
    dfs_num[i]=dfs_low[i]=dfsnumber++;
    for(size_t h=0;h<ADJ[i].size();h++){
        int v=ADJ[i][h];
        if(dfs_num[v]==unvisited){
            parent[v]=i;
            if(i==dfsroot)rootchildren++;
            favb(v,dfsroot);
            if(dfs_low[v]>=dfs_num[i] && i!=dfsroot)V[i]=1;
            dfs_low[i]=dfs_low[i]<dfs_low[v]?dfs_low[i]:dfs_low[v];
        }else if(parent[i]!=v){
            dfs_low[i]=dfs_low[i]<dfs_num[v]?dfs_low[i]:dfs_num[v];
        }
    }
}

int main(){
    int a;
    while(1){
        scanf("%d",&a);
        if (a==0) break;
        scanf("\n");
        for(size_t k=0;k<100;k++) V[k]=0;
        dfsnumber=0;
        ADJ.clear();
        ADJ.resize(a);
        parent.resize(a);
        dfs_num.assign(a,unvisited);
        dfs_low.assign(a,unvisited);
        size_t i=0;
        isav=0;
        
        while(Input()) i++;
        for(size_t j=0;j<i;j++){
            if(dfs_num[j]==unvisited){
                rootchildren=0;favb(j,j);
                parent[j]=j;
                if(rootchildren>1) V[j]=1;
            }
        }
        for(size_t k=0;k<100;k++) isav+=V[k];
        printf("%d\n",isav);
    }
}