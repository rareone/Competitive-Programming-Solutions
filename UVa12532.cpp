#include <iostream>
#include <vector>
using namespace std;
#define FL(i,j,k) for(int i=j;i<k;++i)
#include <vector>
#include <utility>
typedef pair<int, int > ii;
const int MAXN=(100010*4);
int data[MAXN];
int sgn(int a){return a==0?0:a/abs(a);}

void build(int L,int R,int v=1){
    if(R-L==1){
        scanf("%d",&data[v]);
        data[v]=sgn(data[v]);
        return;
    }
    int mid=(L+R)/2;
    build(L, mid,v<<1),build(mid, R,v<<1^1);
    data[v]=data[v<<1^1]*data[v<<1];
}

void update(int L,int R,int l,int r,int x,int v=1){//[L,R)是目標區間,[l,r)是目前區間,v是index,x是值
    if(R<=l||r<=L)return;
    if(L<=l && r<=R){
        data[v]=x;return;
    }
    int mid=(l+r)/2;
    update(L, R, l, mid, x,v<<1);
    update(L, R, mid, r, x,v<<1|1);
    data[v]=data[v<<1|1]*data[v<<1];
}

int ask(int L,int R,int l,int r,int v=1){
    if(R<=l||r<=L)return 1;
    if(L<=l && r<=R)return data[v];
    int mid=(l+r)/2;
    return  ask(L,R,l,mid, v<<1)*ask(L,R,mid,r, v<<1|1);
}

inline void action(int a){
    printf("%c",a==0?'0':a>0?'+':'-');
}

int main(){
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);
    int N,Q,f,x;char c;
    while (cin>>N>>Q) {
        build(0,N);
        while (Q--) {
            cin>>c>>f>>x;
            if(c=='C')update(f-1, f, 0, N, sgn(x));
            else action(ask(f-1, x, 0, N));
        }
        puts("");
    }
}
