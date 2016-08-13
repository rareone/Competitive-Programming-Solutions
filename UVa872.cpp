//Proposition: A vertex v in a dag is a source iff it's deg-(v)=0
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <sstream>
#include <map>
#include <algorithm>
#define unvisited 0
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> al;

vi degminus;
vector<char> prob;
al adjlist;
map<char,int> m;
vector<char> solution;
size_t vertexsize=0;
bool dfs(int N,bool ok=0){
    if(N==vertexsize){
        for(size_t j=0;j<vertexsize;j++) printf("%c ",solution[j]);
        printf("\n");
        return true;
    }
    else{
        for(size_t j=0;j<vertexsize;j++){
            if(degminus[j]==0){
                solution.push_back(prob[j]);
                degminus[j]--;
                for(size_t i=0;i<adjlist[j].size();i++)degminus[adjlist[j][i]]--;
                ok=dfs(N+1,ok);
                for(size_t i=0;i<adjlist[j].size();i++)degminus[adjlist[j][i]]++;
                degminus[j]++;
                solution.pop_back();
            }
        }
        return ok;
    }
}

int main(){
    int numbercase;
    scanf("%d",&numbercase);
    string blank, vertex,order;
    getline(cin,blank);
    while(numbercase--){
        for(size_t t=0;t<adjlist.size();t++) adjlist[t].clear();
        adjlist.clear();
        m.clear();
        prob.clear();
        degminus.clear();

        getline(cin,blank);
        getline(cin,vertex);
        getline(cin,order);
        
        istringstream in(vertex),ord(order);
        
        char less,large,oper;
        vertexsize=0;
        
        while(in>>less) {if(less=='\0')break; prob.push_back(less);vertexsize++;}
        
        degminus.resize(vertexsize);
        //memset(&ver,unvisited,sizeof ver);
        sort(prob.begin(), prob.end());
        adjlist.resize(vertexsize);
        solution.clear();
        for(size_t h=0;h<vertexsize;h++) m[prob[h]]=h;
        while(ord>>less>>oper>>large){adjlist[m[less]].push_back(m[large]); degminus[m[large]]++;}
        for(size_t i=0; i<adjlist.size();i++){
            sort(adjlist[i].begin(),adjlist[i].end());
        }
        order.clear();
        if(!dfs(0))printf("NO\n");
        printf("\n");
        solution.clear();
    }
}
