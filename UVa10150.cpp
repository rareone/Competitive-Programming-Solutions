#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

inline bool link(string a,string b){
    size_t i=a.size(),n=0;
    if(a.size()!=b.size()) return false;
    while(i--){
        n=(a.at(i)!=b.at(i))?n+1:n;
    }
    return n==1?true:false;
}
int main() {
    vector<string> prob;
    string a;
    while(getline(cin,a)){
        queue<size_t> R;
        R.push(0);
        prob.clear();
        prob.push_back(a);
        size_t V=0;
        while(1){
            getline(cin,a);
            prob.push_back(a);
            V++;
            if(a=="") {prob.pop_back(); break;}
        }
        vector<size_t> vertex(V,INF); //previous vertex
        vertex[0]=0;
        while(!R.empty()){
            size_t breadth=R.back();
            for(size_t a=0;a<vertex.size();a++){
                if(link(prob.at(a), prob.at(breadth))){
                    if(vertex.at(a)==INF){
                        vertex[a]=breadth;
                        if(a==1) break;
                        R.push(a);
                    }
                }
            }
            R.pop();
            if(vertex.at(1)!=INF)break;
        }
        if(vertex.at(1)!=INF){
            size_t backtract=1;
            vector<int> count(V,0);
            while(backtract!=0){
                count[backtract]++;
                backtract=vertex[backtract];
            }
            count[0]=1;
            for(size_t s=0;s<V;s++){
                if(count[s]!=0){
                    printf("%s\n",prob.at(s).c_str());
                }
            }
        }else{printf("No solution.");}
        printf("\n");
    }
    
    
    return 0;
}
