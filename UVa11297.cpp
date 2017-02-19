#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <algorithm>
#define INF 2e9
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef pair<int, int> ii;

ii T[5000000];
int n,A[500][500];

void build(int lx=0,int rx=n,int ly=0,int ry=n,int v=1){
    if(lx==rx||ly==ry){T[v]=ii(-INF,INF);return;}
    if(rx-lx==1&&ry-ly==1) {
        T[v].second=T[v].first=A[lx][ly];
        return;}
    int midx=(lx+rx)/2,midy=(ly+ry)/2;
    build(lx, midx, ly, midy,v*4);
    build(lx, midx, midy, ry,v*4+2);
    build(midx, rx, ly, midy,v*4+1);
    build(midx, rx, midy, ry,v*4+3);
    T[v]=ii(-INF,INF);
    FL(i, 0, 4)T[v].first=max(T[4*v+i].first,T[v].first),T[v].second=min(T[4*v+i].second,T[v].second);
}

void fix(int x,int X,int Y,int lx=0,int rx=n,int ly=0,int ry=n,int v=1){
    if(X>=rx || lx>X || Y>=ry || ly>Y){T[v]=ii(-INF,INF);return;}
    if(rx-lx==1&&ry-ly==1) {T[v].second=T[v].first=x;return;}
    int midx=(lx+rx)/2,midy=(ly+ry)/2;
    if(X<midx){
        if(Y<midy)
            fix(x,X,Y,lx, midx, ly, midy,v*4);
        else
            fix(x,X,Y,lx, midx, midy, ry,v*4+2);
    }else{
        if(Y<midy)
            fix(x,X,Y,midx, rx, ly, midy,v*4+1);
        else
            fix(x,X,Y,midx, rx, midy, ry,v*4+3);
    }
    T[v]=ii(-INF,INF);
    FL(i, 0, 4)T[v].first=max(T[4*v+i].first,T[v].first),T[v].second=min(T[4*v+i].second,T[v].second);
}

ii ask(int LX,int RX,int LY,int RY,int lx=0,int rx=n,int ly=0,int ry=n,int v=1){
    if(LX>=rx || lx>=RX || LY>=ry || ly>=RY)return ii(-INF,INF);
    if(LX<=lx && rx<=RX && LY<=ly && ry<=RY)
        return ii(T[v].first,T[v].second);
    int midx=(lx+rx)/2,midy=(ly+ry)/2;
    ii
    a=ask(LX,RX,LY,RY,lx, midx, ly, midy,v*4),
    b=ask(LX,RX,LY,RY,lx, midx, midy, ry,v*4+2),
    c=ask(LX,RX,LY,RY,midx, rx, ly, midy,v*4+1),
    d=ask(LX,RX,LY,RY,midx, rx, midy, ry,v*4+3);
    return ii(max(max(a.first,b.first),max(c.first,d.first)),min(min(a.second,b.second),min(c.second,d.second)));
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    scanf("%d",&n);
    FL(i, 0, n)FL(j, 0, n)scanf("%d",&A[i][j]);
    build();
    char c;string emp;
    int x1,x2,y1,y2,key,q;getline(cin, emp);
    cin>>q;
    while (q--) {
        cin>>c;
        if(c=='q'){
            cin>>x1>>y1>>x2>>y2;
            ii k=ask(x1-1, x2, y1-1, y2);
            printf("%d %d\n",k.first,k.second);
        }else{
            cin>>x1>>x2>>key;
            fix(key, x1-1,x2-1);
        }
    }

}
