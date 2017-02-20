#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
map<unsigned long long int,bool> m;
int A[5],target,n;

long long int gen(vector<int> &A){
    int sum=0,k=1;
    FL(i, 0, n){
        sum+=k*A[i];
        k*=51;
    }
    return sum;
}
bool exactly(vector<int> &A){
    return count(A.begin(), A.end()-1,target)==1;
}
int main(){
    cin>>n;
    queue<vector<int>> q;
    FL(i, 0, n)cin>>A[i];
    cin>>target;
    vector<int> v;FL(i, 0, n+1)v.push_back(0);
    q.push(v);m[gen(v)]=1;
    
    bool ok=0;
    FL(i, 0, n)FL(j, i+1, n)if(target%__gcd(A[i],A[j])==0)ok=1;
    if(!ok||count_if(A, A+n, [=](int a){return a<target;})==n){
        printf("-1");return 0;
    }
    while (!q.empty()) {
        vector<int> v=q.front();q.pop();
        if(exactly(v)){printf("%d",v[n]);return 0;}
        FL(i, 0, n){
            vector<int> p=v;
            if(p[i]!=A[i]){
                p[i]=A[i],++p[n];
                if(m.find(gen(p))==m.end())m[gen(p)]=1,q.push(p);
            }
        }
        FL(i, 0, n){
            vector<int> p=v;
            if(p[i]!=0){
                p[i]=0,++p[n];
                if(m.find(gen(p))==m.end())m[gen(p)]=1,q.push(p);
            }
        }
        FL(i, 0, n){
            FL(j, 0, n){
                vector<int> p=v;
                if(i==j)continue;
                if(p[i]!=0 && p[j]!=A[j]){
                    int small=min(p[i],A[j]-p[j]);
                    p[i]-=small;
                    p[j]+=small;
                    ++p[n];
                    if(m.find(gen(p))==m.end())m[gen(p)]=1,q.push(p);
                }
            }
        }
    }
}
