#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <cmath>
#include <map>
using namespace std;
#define FL(i,j,k) for(int i=j;i<k;++i)
#define eat(ss) ss.clear();getline(cin,s);ss<<s;
typedef long long ll;
typedef pair<int, int > ii;
int b,d[2],r[5],c[5];
ii match[76];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int T;scanf("%d",&T);
    while (T--) {
        d[0]=d[1]=1;
        fill(match, match+76, ii(-1,-1));
        FL(i, 0, 5)FL(j, 0, 5){
            if(i==2&&j==2)continue;
            scanf("%d",&b);
            match[b]=ii(i,j);
        }
        FL(i, 0, 5)r[i]=c[i]=(i==2);
        int ans=0,a;bool stop=1;
        FL(i, 0, 75){
            scanf("%d",&a);
            int x=match[a].first,y=match[a].second;
            if(x==-1&&y==-1)continue;
            if(stop){
                if(r[x]==4||c[y]==4)ans=i+1,stop=0;
                ++r[x],++c[y];
                if(x+y==4){
                    if(d[0]==4)ans=i+1,stop=0;
                    ++d[0];
                }
                if(x==y){
                    if(d[1]==4)ans=i+1,stop=0;
                    ++d[1];
                }
            }
        }
        printf("BINGO after %d numbers announced\n",ans);
    }
}
