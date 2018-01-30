#include <bits/stdc++.h>

using namespace std;
int a;
int main() {
  int n, k, ans;
  scanf("%d%d", &n, &k);
  ans = k;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (k % a == 0) ans = min(ans, k / a);
  }
  printf("%d\n", ans);
}
