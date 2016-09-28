#define elp 1e-8
#define MAXN 1000
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
//Algorithm: produce the slope table 1000*1000 with less using std library can reduce the const
struct P{
    int d[2];
    inline bool operator<(P p2){//plane sorting
        if(d[0]==p2.d[0])
            return d[1]<p2.d[1];
        return d[0]<p2.d[0];
    }
};
int n;
P prob[MAXN];
double slopetable[MAXN][MAXN];
inline double slope(P p1,P p2){
    if(p2.d[0]==p1.d[0]) return INF;
    return (double)(p2.d[1]-p1.d[1])/(p2.d[0]-p1.d[0]);
}
int main(){
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i)scanf("%d%d",&prob[i].d[0],&prob[i].d[1]);
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                slopetable[i][j]=slope(prob[i],prob[j]);
            }
        }
        int max=2;
        for(int i=0;i<n-1;++i){
            std::sort(slopetable[i]+i+1,slopetable[i]+n);
            int key=i+1,count=1;//including key
            for(int j=key+1;j<n;++j){
                if(slopetable[i][j]-slopetable[i][key]>elp ||slopetable[i][j]-slopetable[i][key]<-elp)
                    //這裡我本來打==結果不小心對了 = ='''
                    max=max>count+1?max:count+1,key=j,count=1;
                else ++count;
                
            }
            max=max>count+1?max:count+1;
        }
        printf("%d\n",max);
    }
}