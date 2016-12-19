#include <iostream>
#include <cstdio>
#include <string.h>
#include <sstream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#define MAXN 100010
#define FL(i,j,k) for(int i=j;i<k;++i)
typedef long long int ll;
using namespace std;
struct node{
    vector<int> ch;
    string s;
    int d=0,num;
};
stack<int> st;
string str;
int i;
pair<string, int> eat(){
    int chi=0,bi=1;
    while (str[i]>='0' && str[i]<='9') {
        chi+=(str[i]-'0')*bi;
        bi*=10;
        --i;
    }
    int stay=i;
    --i;
    while (str[i]!=','&&i>=0)--i;
    string f;
    FL(j,i+1, stay)f.push_back(str[j]);
    return pair<string, int>(f,chi);
}
vector<vector<pair<string,int>>> vvs;
node nd[500000];
int main(){
    getline(cin, str);
    i=str.size();
    int ndnum=0;
    while (i>=0) {
        --i;
        if(i<0)break;
        pair<string, int> Q=eat();
        nd[ndnum].s=Q.first;
        nd[ndnum].num=i;
        while (Q.second>0) {
            nd[ndnum].ch.push_back(st.top());
            st.pop();
            Q.second--;
        }
        st.push(ndnum++);
    }
    vvs.resize(500000);
    while (!st.empty()) {
        int p=st.top();st.pop();
        queue<int> q;q.push(p);
        while (!q.empty()) {
            node p=nd[q.front()];
            vvs[p.d].push_back(pair<string,int>(p.s,p.num));
            q.pop();
            for(int i=0;i<p.ch.size();++i){
                nd[p.ch[i]].d=p.d+1;
                q.push(p.ch[i]);
            }
        }
    }
    int k=0;
    while (0!=vvs[k].size()) {
        sort(vvs[k].begin(), vvs[k].end(), [=](pair<string,int> A,pair<string,int> B){return A.second<B.second;});
        ++k;
    }
    printf("%d\n",k);
    k=0;
    
    while (0!=vvs[k].size()) {
        for(pair<string,int> s : vvs[k]){
            printf("%s ",s.first.c_str());
        }
        printf("\n");
        ++k;
    }
}
