#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define FL(i,j,k) for(int i=j;i<k;++i)
#define eat(a) int a;scanf("%d",&a)
#define shift 50010
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
set<int> has[2];
int size[2],A[100];
int main(void)
{
    int T;scanf("%d",&T);
    while(T--){
        eat(n);
        size[0]=size[1]=1;
        has[1].clear();has[1].insert(0);
        FL(i,0,n)scanf("%d",A+i);
        FL(i, 0, n){
            bool r=i%2;
            size[r]=0;
            has[r].clear();
            for(int q: has[!r]){
                has[r].insert(q+A[i]);
                has[r].insert(q-A[i]);
            }
        }
        printf("%d\n",abs(*min_element(has[!(n%2)].begin(), has[!(n%2)].end() ,[=](int a,int b){return abs(a)<abs(b);})));
               
    }
}
