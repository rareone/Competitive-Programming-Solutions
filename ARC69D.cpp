#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define FL(i,j,k) for(int i=j;i<k;++i)
#define eat(a) int a;scanf("%d",&a)

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
bool A[100000],stay[100000];

int main(void)
{
    int n;cin>>n;
    string s;getline(cin, s);
    getline(cin, s);
    FL(i, 0, n)A[i]=s[i]=='o'?0:1;
    FL(i, 0, 8){
        FL(j, 0, 3)stay[j]=(i>>j)&1;
        FL(i, 3, n)stay[i]=A[i-1]^stay[i-1]^stay[i-2];
        if(stay[0]^stay[n-1]^stay[n-2]==A[n-1] &&
           stay[0]^stay[n-1]^stay[1]==A[0] &&
           stay[0]^stay[2]^stay[1]==A[1]){
            FL(i, 0, n)printf("%c",stay[i]?'W':'S');
            return 0;
        }
    }
    puts("-1");
}
