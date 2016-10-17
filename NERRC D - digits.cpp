#define FILEIO(name) \
freopen(name".in", "r", stdin); \
freopen(name".out", "w", stdout);
#include <iostream>
#include <vector>
#define MAXN 1e5
int havesum[100];
using namespace std;
vector<int> g[54];

inline int sum(int a){
    int s=0;
    while(a!=0){
        s+=a%10;
        a/=10;
    }
    return s;
}

int main(){
    FILEIO("digit")
    
    //暴力解，想好久@@
    for(int i=1;i<MAXN;++i){
        g[sum(i)-1].push_back(i);
    }
    //int n;scanf("%d",&n);
    for(int n=1;n<=5000;++n){
        int k=0;
        long long int min=9223372036854775807;
        for(int i=0;i<25;++i){
            if(g[i].size()>=n){
                long long int sum=0;
                for(int j=0;j<n;++j){
                    sum+=g[i][j];
                }
                if(min>sum){
                    min=sum;
                    k=i;
                }
            }
        }
        printf("%lld %d\n",min,k);
    }

}