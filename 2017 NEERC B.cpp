#include <iostream>
#include <vector>
#define fout fflush(stdout)
using namespace std;

vector<int > maxv;
vector<int > minv;


inline char get(){
    char c;c=getchar();
    while (c!='<'&&c!='>'&&c!='=') {
        c=getchar();
    }
    return c;
}
int main(){
    int T;scanf("%d",&T);
    while (T--) {
        maxv.clear();
        minv.clear();
        char c;
        int size;scanf("%d",&size);
        for(int i=0;i<size/2;++i){
            printf("? %d %d\n",2*i+1,2*i+2);fout;
            c=get();
            if(c=='<'){
                minv.push_back(2*i+1);
                maxv.push_back(2*i+2);
            }
            else{
                minv.push_back(2*i+2);
                maxv.push_back(2*i+1);
            }
        }
        if(size%2==1)minv.push_back(size),maxv.push_back(size);
        int min=minv[0],max=maxv[0],stay;
        for(int i=2;i<=minv.size();++i){
            printf("? %d %d\n",min,minv[i-1]);fout;
            c=get();
            if(c=='>')min=minv[i-1];
        }
        for(int i=2;i<=maxv.size();++i){
            printf("? %d %d\n",max,maxv[i-1]);fout;
            c=get();
            if(c=='<')max=maxv[i-1];
        }
        printf("! %d %d\n",min,max);fout;
    }
}