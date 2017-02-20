#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>
#define MAXN 2000000
#define F first
#define S second
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef pair<int, int> ii;

ii box[MAXN];
int size=0,i=0;
inline void insert(ii a){
    if(size==0){box[0]=a;size=1;return;}
    size=lower_bound(box, box+size, a, [=](ii a,ii b){return a.F>=b.F&&a.S>=b.S;})-box;
    box[size]=a;
    ++size;
}
inline int get(string s){
    int n=0;char c;c=s[i++];
    while(c<'0'||c>'9')c=s[i++];
    while(c>='0'&&c<='9'){
        n*=10;
        n+=c-'0';
        c=s[i++];
    }
    return n;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int w,l,h,q=1;string s;//empty string
    while(getline(cin, s)){
        if(s.size()<2)continue;
        if(s[0]=='E')break;
        if(s[3]=='c'){
            i=0;
            w=get(s);l=get(s);h=get(s);
            insert(ii(w,l));
        }else if(s[0]=='Q'){
            if(size==1){
                cout<<"Query "<<q++<<": "<<size<<" box."<<'\n';
            }else if (size==0){
                cout<<"Query "<<q++<<": None."<<'\n';
            }else cout<<"Query "<<q++<<": "<<size<<" boxes."<<'\n';
        }
    }
}
