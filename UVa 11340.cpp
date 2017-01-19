#include <iostream>
#include <vector>
using namespace std;
#define FL(i,j,k) for(int i=j;i<k;++i)
#include <vector>
#include <sstream>
#include <utility>
#include <cmath>
#include <map>
#define eat(ss) ss.clear();getline(cin,s);ss<<s;
typedef long long ll;
typedef pair<int, int > ii;
int m[1000]={0};
string s;

int main(){
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);
    int T,money,ch;double total;char c;
    stringstream ss; string s;ss.clear();getline(cin,s);ss<<s;
    while(ss>>T){
        while (T--) {
            fill(m, m+1000, 0);
            total=0;
            ss.clear();getline(cin,s);ss<<s;ss>>ch;
            while (ch--){
                ss.clear();getline(cin,s);ss<<s;ss>>c>>money;
                m[c]=money;
            }
            ss.clear();getline(cin,s);ss<<s;ss>>ch;
            while (ch--) {
                getline(cin,s);
                for(char c: s){
                    total+=m[c]*0.01;
                }
            }
            printf("%.2lf$\n",total);
        }
    }
}
