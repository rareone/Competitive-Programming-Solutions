#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> mt;
mt adjlist;
vector<char> prob;
vector<char> solution;
vi degminus;
map<char,size_t> m;
void dfs(){
    if(solution.size()==adjlist.size()){for(size_t j=0;j<adjlist.size();j++)printf("%c",solution[j]);printf("\n");}
    else{
        for(size_t j=0;j<adjlist.size();j++){
            if(degminus[j]==0){
                solution.push_back(prob[j]);
                degminus[j]--;
                for(size_t t=0;t<adjlist[j].size();t++) degminus[adjlist[j][t]]--;
                dfs();
                for(size_t t=0;t<adjlist[j].size();t++) degminus[adjlist[j][t]]++;
                degminus[j]++;
                solution.pop_back();
            }
        }
    }
}


int main(){
    string firstline,secondline;
    char c1,c2;
    while(getline(cin,firstline)){
        getline(cin,secondline);
        degminus.clear();
        adjlist.clear();
        solution.clear();
        prob.clear();
        m.clear();
        istringstream sin1(firstline),sin2(secondline);
        size_t i=0;
        while(sin1>>c1){prob.push_back(c1); i++;}
        sort(prob.begin(),prob.end());
        for(size_t j=0;j<i;j++)m[prob[j]]=j;
        degminus.resize(i);
        adjlist.resize(i);
        while(sin2>>c1>>c2){ adjlist[m[c1]].push_back(m[c2]); degminus[m[c2]]++; }
        for (size_t t=0; t<i;t++) sort(adjlist[t].begin(),adjlist[t].end());
        dfs();
        printf("\n");
    }
}