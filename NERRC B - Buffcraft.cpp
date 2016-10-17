#include <iostream>
#define MAXN 50000
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<ll, int> ii;
int d,k,cd,cp;
ii db[MAXN];//value,index
ii pb[MAXN];
inline ll sum(ii* b,int begin,int end){
    if(end==begin)return 0;
    if(begin==0) return b[end-1].first;
    return b[end-1].first-b[begin-1].first;
}
inline int cmp(ii &i,ii &b){return b<i;}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>d>>k>>cd>>cp;
    for(int i=0;i<cd;++i){
        int a;cin>>a;
        db[i]=ii(a,i+1);
    }
    for(int i=0;i<cp;++i){
        int a;cin>>a;
        pb[i]=ii(a,i+1);
    }
    
    sort(db,db+cd,cmp);
    sort(pb,pb+cp,cmp);
    for(int i=1;i<cd;++i)db[i].first+=db[i-1].first;
    for(int i=1;i<cp;++i)pb[i].first+=pb[i-1].first;
    ll maxvalue=0;int ch=0;
    if(k>=cd+cp)k=cd+cp,ch=cd;
    else
    {
        for(int i=0;i<k+1;++i){
            ll a=(d+sum(db,0,i))*(100+sum(pb,0,k-i));
            if(a>maxvalue){
                ch=i;
                maxvalue=a;
            }
        }
    }
    printf("%d %d\n", ch,k-ch);
    for(int i=0;i<ch;++i) printf("%d ",db[i].second);
    printf("\n");
    for(int i=0;i<k-ch;++i) printf("%d ",pb[i].second);
}