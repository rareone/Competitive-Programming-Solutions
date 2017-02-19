#include <iostream>
#include <stack>
#include <utility>
#include "memory.h"
#define MAXN 20010

using namespace std;


int P[MAXN],R[MAXN],N,K,pa[MAXN],stay[MAXN],cas,q,p;
bool visited[MAXN];
int parent(int p){
    if(P[p]==p)return p;
    else return P[p]=parent(P[p]);
}
inline void UN(int a,int b){
    int A=parent(a),B=parent(b);
    if(A==B) return;
    if(R[A]<R[B]){P[A]=P[B];}
    else R[A]+=R[A]==R[B],P[B]=P[A];
}


typedef pair<int, int > ii;

stack<ii> st;
stack<string> ans;

inline char get(){
    char c;c=getchar();
    while((c<'A'||c>'Z'))c=getchar(
        );
    return c;
}

inline int getN(){
    char c=getchar();
    while (c<'0'||c>'9') c=getchar();
    int x=c-'0';c=getchar();
    while(c>='0'&& c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false);std::cin.tie(0);
    cas=getN();
    char c;
    for(int i=0;i<cas;++i) {
        memset(visited, false, sizeof(visited));
        cout<<"Case #"<<i+1<<":\n";
        N=getN(),K=getN();
        for(int i=0;i<N;++i)stay[i]=pa[i]=getN()-1;
        while (K--) {
            c=get(),q=getN()-1;
            if(c=='C') {
                if(!visited[q]){
                    st.push(ii(q,-5));pa[q]=-1;
                    visited[q]=1;
                }else{
                    st.push(ii(-5,-5));
                }
            }
            else p=getN()-1,st.push(ii(p,q));
        }
        //之前假設每個cut都只會有一次而撰code -> WA
        //利用visited使得cut只會有一次 -> AC
        for(int i=0;i<N;++i) P[i]=i,R[i]=0;
        for(int i=0;i<N;++i) if(pa[i]!=-1) UN(pa[i],i);
        while(!st.empty()){
            ii y=st.top();st.pop();
            if(y.second==-5){
                if(y.first==-5)continue;
                if(stay[y.first]==-1)continue;
                UN(y.first,stay[y.first]);
            }else{
                ans.push(string(parent(y.first)==parent(y.second)?"YES\n":"NO\n"));
            }
        }
        while(!ans.empty()){cout<<ans.top(); ans.pop();}
    }
}
