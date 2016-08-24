#include <iostream>
#include <vector>
#include <map>
#include "memory.h"
using namespace std;
vector<vector<bool>> adj;//[demand][CPU]
char charadj[26];
bool ok,vapp[26]={0};
int mcpu[10];
vector<int> mapp;
string s;
int greedy(){
    int a=0;
    for(int i=0;i<adj.size();i++){
        if(mapp[i]==-1)
        for(int j=0;j<10;j++){
            if(adj[i][j] && mcpu[j]==-1){mcpu[j]=i;mapp[i]=j;a++;break;}
        }
    }
    return a;
}

bool Aug(int i){
    if(!vapp[i]){
        vapp[i]=1;
    for(size_t j=0;j<10;j++){
        if(adj[i][j])
        if(mcpu[j]==-1||Aug(mcpu[j]))
        {mcpu[j]=i;mapp[i]=j;return true;}
    }
    }
    return false;
}
inline bool Input(){
    ok=true;
    adj.clear();
    memset(charadj,'\0', sizeof(charadj));
    memset(mcpu,-1,sizeof(mcpu));
    if(!getline(cin,s))return false;
    if(s=="") return false;
    while(s!=""){
        vector<bool> row(10,false);
        int i=3;
        while(s[i]!=';')row[s[i++]-'0']=true;
        for(int h=0;h<(s[1])-'0';h++){
            adj.push_back(row);
            charadj[adj.size()-1]=s[0];
        }
        if(adj.size()>10||s[1]-'0'>i-3) ok=false;
        getline(cin,s);
    }
    mapp.assign(adj.size(),-1);
    return true;
}

int main(){
    while(Input()){
        if(ok==false) {printf("!\n");continue;}
        int c=greedy();
        for(int i=0;i<adj.size();i++){
            memset(vapp, false, sizeof(vapp));
            if(mapp[i]==-1 && Aug(i)) c++;
        }
        if(c==adj.size()){
            for(size_t i=0;i<10;i++)
                printf("%c",mcpu[i]!=-1?charadj[mcpu[i]]:'_');printf("\n");
        }else{
            printf("!\n");
        }
    }
}

