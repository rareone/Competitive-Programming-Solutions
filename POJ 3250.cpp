#include <iostream>

using namespace std;
int A[100000], st[100000], top = 0;
int main() {
  int n, a;
  long long ans = 0; 
  while (~scanf("%d", &n)) {
    for(int i = 0; i < n; ++i) {
      scanf("%d", A + i);
    } top = 0, ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      while (top && A[st[top - 1]] < A[i]) --top;
      ans += top? st[top - 1] - i - 1 : n - 1 - i;
      st[top++] = i;
    } 
    printf("%lld\n", ans);
  }
}
