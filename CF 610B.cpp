#include <bits/stdc++.h>
using namespace std;
int A[100000], st[100000], top = 0;
long long dp[100000];
int main() {
  int l, r, n, q; scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) scanf("%d", A + i);
  for (int i = 0; i < n - 1; ++i) A[i] = abs(A[i + 1] - A[i]);
  --n;
  while (q--) {
    scanf("%d%d", &l, &r);
    top = 0, --l, --r;
    long long ans = 0;
    for (int i = l; i < r; ++i) {
      while (top && A[st[top - 1]] < A[i]) --top;
      dp[i] = 0;
      dp[i] += top? dp[st[top - 1]]: 0;
      dp[i] += top? (long long) (i - st[top - 1]) * A[i]  :(long long) (i - l + 1) * A[i];
      ans += dp[i];
      st[top++] = i;
    }
    printf("%lld\n",ans);
  }

}
