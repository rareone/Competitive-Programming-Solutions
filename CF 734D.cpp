#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#define MAXN 500000
using namespace std;
typedef pair<int,int> ii;
typedef long long int ll;
#define FL(i,j,k) for(int i=j;i<k;++i)

struct chess {
    char c;
    ll  x,y;
};


int gcd(int a,int b){
    if(a==0||b==0)return a==0?b:a;
    if(!(a%b))return b;
    else return gcd(b,a%b);
}
ll sc[8]={1,1,1,0,0,-1,-1,-1};
ll sd[8]={1,0,-1,1,-1,1,0,-1};

int main(){
    int n,sx,sy;scanf("%d\n%d %d\n",&n,&sx,&sy);
    chess prob[MAXN];
    FL(i, 0, n){
        int aa,bb;
        scanf("%c %d %d\n",&prob[i].c,&aa,&bb);
        prob[i].x=aa-sx,prob[i].y=bb-sy;
    }
    sort(prob,prob+n, [=](chess a,chess b){return max(abs(a.x), abs(a.y))<max(abs(b.x),abs(b.y));});
    bool ok[8]={1,1,1,1,1,1,1,1};
    FL(i, 0, n){
        chess che=prob[i];
        ll G=gcd(abs(che.x),abs(che.y));
        FL(j, 0, 8){
            if(ok[j] && che.x/G==sc[j] && che.y/G==sd[j]){
                ok[j]=0;
                if(sc[j]==0||sd[j]==0){
                    if(che.c=='Q'||che.c=='R'){
                        printf("YES");return 0;
                    }
                }else{
                    if(che.c=='Q'||che.c=='B'){
                        printf("YES");return 0;
                    }
                }
            }
        }
    }
    printf("NO");
    
}
