#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define unvisited -1;
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> ii;
int main(){
    FILE *f=fopen("/Users/DannelApple/Library/Developer/Xcode/DerivedData/UVa_Playground-dqeptcojwilitvbhtdkqnqwsqris/Build/Products/Debug/test.txt","r");
    int yp,M,N,x,y,len,maxx,maxy;
    float fuck,you;
    while(1){
        maxx=maxy=0;
        fscanf(f,"%d%d",&M,&N);
        if((M==-1)&&(N==-1)) break;
        bool ok=false;
        int xwallmtx[200][199]={0},ywallmtx[199][200]={0},vertice[199][199],ans=0;
        for(size_t i=0;i<199;i++)for(size_t j=0;j<199;j++) vertice[i][j]=INF;//show distance
        while(M--){
            fscanf(f,"%d %d %1d %d",&x,&y,&yp,&len);
            if(yp)for(size_t i=0;i<len;i++) {ywallmtx[x-1][y-1+i]=INF;maxy=((y+i)>maxy)?(y+i):maxy;maxx=(x>maxx)?x:maxx;}
            else  for(size_t i=0;i<len;i++) {xwallmtx[x-1+i][y-1]=INF;maxx=((x+i)>maxx)?(x+i):maxx;maxy=(y>maxy)?y:maxy;}
        }
        while(N--){
            fscanf(f,"%d%d%1d",&x,&y,&yp);
            if(yp) ywallmtx[x-1][y-1]=1;
            else xwallmtx[x-1][y-1]=1;
        }
        fscanf(f,"%f %f",&fuck,&you);
        priority_queue<pair<int,ii>,vector<pair<int, ii>>,greater<pair<int,ii>>> set; set.push(pair<int,ii>(0,ii((int)fuck-1,(int)you-1)));
        while(!set.empty()){
            ii v=set.top().second; len=set.top().first; set.pop();
            int i=v.first,j=v.second;
            if(i<0||j<0||i>maxx||j>maxy||j>=199||i>=199){ok=true; ans=len; break;}
            if(vertice[i][j]>len){
                vertice[i][j]=len;
                if(xwallmtx[i][j+1]!=INF)
                    set.push(make_pair(vertice[i][j]+xwallmtx[i][j+1],ii(i,j+1)));
                if(xwallmtx[i][j]!=INF)
                    set.push(make_pair(vertice[i][j]+xwallmtx[i][j],ii(i,j-1)));
                if(ywallmtx[i+1][j]!=INF)
                    set.push(make_pair(vertice[i][j]+ywallmtx[i+1][j],ii(i+1,j)));
                if(ywallmtx[i][j]!=INF)
                    set.push(make_pair(vertice[i][j]+ywallmtx[i][j],ii(i-1,j)));
            }
        }
        printf("%d\n",ok?ans:-1);
    }
}

