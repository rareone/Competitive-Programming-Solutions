#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#define FL(i,j,k) for(ll i=j;i<k;++i)
using namespace std;
typedef long long int ll;
string s;
int A[50];
inline int cam(int a,int b){
    if(a>=b)return a+b;
    else return b-a;
}
inline set<int> pdt(set<int> s1, set<int> s2){
    set<int> s;
    for(auto i: s1)for(auto j: s2)s.insert(cam(i, j));
    return s;
}
set<int> dp[51][51];
set<int> num(int i,int j){
    if(i+1==j)return dp[i][j]=set<int>{A[i]};
    if(!dp[i][j].empty()) return dp[i][j];
    else{
        set<int> s;
        FL(r, i+1, j){
            set<int> k=pdt(num(i,r), num(r, j));
            s.insert(k.begin(),k.end());
        }
        return dp[i][j]=s;
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>s;
    int cas=0;
    while (s!="0") {
        FL(i, 0, 51)FL(j, 0, 51)dp[i][j].clear();
        memset(A, 0,sizeof(A));
        FL(i, 0, s.size()){
            if(s[i]=='I')A[i]=1;
            else if (s[i]=='V')A[i]=5;
            else if (s[i]=='X')A[i]=10;
            else if (s[i]=='L')A[i]=50;
            else if (s[i]=='C')A[i]=100;
        }
        set<int> v=num(0, s.size());
        cout<<"Case "<<++cas<<": ";for(auto s: v) cout<<s<<' ';cout<<'\n';
        cin>>s;
    }
}
