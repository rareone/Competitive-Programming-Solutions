#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
int A[1000000], coun[1000000], size = 0;
int main() {
  int P; 
  while(~scanf("%d", &P)) {
    map<int, int> rem;
    int num = 0;
    for (int i = 0; i < P; ++i) {
      scanf("%d", A + i);
      if (rem.count(A[i]) == 0) rem[A[i]] = num++;
      A[i] = rem[A[i]];
    }
    fill(coun, coun + num, 0), size = 0;
    int l = 0, r = 0;
    while (size < num) {
      if (coun[A[r]] == 0) ++size;  
      ++coun[A[r++]];
    }
    while (coun[A[l]] != 1) --coun[A[l++]];
    int ans = r - l;
    for (;r < P;) {
      if (coun[A[r]] == 0) ++size;  
      ++coun[A[r++]];
      while (coun[A[l]] != 1) --coun[A[l++]];
      ans = min(ans, r - l);
    }
    printf("%d\n",ans);
  }
}

