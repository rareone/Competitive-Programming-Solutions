#include <iostream>
#include <vector>
#include <queue>
#define MAXN 100000
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
#define FL(i,j,k) for(int i=j;i<k;++i)
vi g[MAXN];
ll T,N,c;
bool v[MAXN];
ll d[MAXN];
int main(){
    freopen("jumping.in", "r", stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    FL(t, 0, T){
        cin>>N;
        FL(i, 0, N)g[i].clear();
        FL(i, 0, N){
            cin>>c;
            v[i]=0,d[i]=-1;
            if(i-c>=0)g[i-c].push_back(i);
            if(i+c<N)g[i+c].push_back(i);
        }
        queue<ll> q;q.push(N-1);v[N-1]=1,d[N-1]=0;
        while (!q.empty()) {
            ll w=q.front();q.pop();
            for(ll u:g[w]){
                if(!v[u]){
                    q.push(u);
                    v[u]=1,d[u]=d[w]+1;
                }
            }
        }
        FL(i, 0, N){
            cout<<d[i]<<'\n';
        }
    }
}
