#include <iostream>
#define INF 2147483647
using namespace std;
int a[5000],b[5000],c[5000],d[5000];

inline void buildbuttomup(int route){
    for(int i=1;i<route;++i){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
        c[i]+=c[i-1];
        d[i]+=d[i-1];
    }
}
inline double NashEquilibrium(int front,int back){//O(1)
    if(front==back)return 0;
    double sa=0,sb=0,sc=0,sd=0;
    if(front==0)sa=a[back-1],sb=b[back-1],sc=c[back-1],sd=d[back-1];
    else sa=a[back-1]-a[front-1],sb=b[back-1]-b[front-1],sc=c[back-1]-c[front-1],sd=d[back-1]-d[front-1];
    if(sa+sc==0)
        return sb<sd?sb:sd;
    double x=(sc+sd-sb)/(sa+sc);
    if(x<=0)return sc+sd;
    else if(x>=1) return sa+sb;
    else return sa*x+sb;
}

double min(int begin,int end){
    double a=NashEquilibrium(begin,end);
    for(int i=begin;i<end;++i){
        double left=NashEquilibrium(begin, i),right=NashEquilibrium(i, end);
        if(left+right<a){
            return min(begin,i)+min(i,end);
        }
    }
    return a;
}
double max(int begin,int end){
    double a=NashEquilibrium(begin,end);
    for(int i=begin;i<end;++i){
        double left=NashEquilibrium(begin, i),right=NashEquilibrium(i, end);
        if(left+right>a){
            return max(begin,i)+max(i,end);
        }
    }
    return a;
}

int main(){
    int route;scanf("%d",&route);
    
    
    for(int i=0;i<route;++i)
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    buildbuttomup(route);
    
    printf("%lf\n",NashEquilibrium(0,route));
    
    double sum=0;
    for(int i=0;i<route;++i)sum+=NashEquilibrium(i, i+1);
    printf("%lf\n",sum);
    
    printf("%lf\n",min(0,route));
    
    printf("%lf\n",max(0,route));
    
    return 0;
}
