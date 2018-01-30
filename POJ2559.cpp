#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL L[100000], R[100000], A[100000], st[100000];

int main() {
  LL N;
  while(~scanf("%lld", &N) && N) {
    LL top = 0;
    for (size_t i = 0; i < N; ++i) scanf("%lld", A + i);
    L[0] = 0, st[top++] = 0;
    for (size_t i = 1; i < N; ++i) {
      while (top && A[st[top - 1]] >= A[i]) --top;
      L[i] = top? st[top - 1] + 1 : 0;
      st[top++] = i;
    }
    top = 0;
    R[N - 1] = N - 1, st[top++] = N - 1;
    for (LL i = N - 2; i >= 0; --i) {
      while (top && A[st[top - 1]] >= A[i]) --top;
      R[i] = top? st[top - 1] - 1 : N - 1;
      st[top++] = i;
    }
    LL ans = 0;
    for (size_t i = 0; i < N; ++i) 
      ans = max(ans, A[i] * (R[i] - L[i] + 1));
    printf("%lld\n", ans);
  }

}
