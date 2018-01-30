#include <bits/stdc++.h>
using namespace std;
const int MAXM = 1000;
bitset<MAXM> B[50], all(0);
char s[MAXM + 10];
int cnt[MAXM + 1] = {0};
typedef long long LL;
LL St[1001][1001];
const LL mod = 1e9 + 7;
int main() {
  int M, N;scanf("%d%d", &M, &N);
  all.flip();
  all <<= MAXM - M;
  all >>= MAXM - M;
  for (int i = 0; i < N; ++i) scanf("%s", s), B[i] = bitset<MAXM>(s);
  for (int i = 0; i < M; ++i) {
    auto cur = all;
    for (int j = 0; j < N; ++j) cur &= B[j][i] ? B[j] : ~B[j];
    ++cnt[cur.count()];
  }
  LL ans = 1;
  for (int n = 0; n <= M; ++n) for (int k = 0; k <= n; ++k) {
    if (k == n or k == 1) St[n][k] = 1;
    else (St[n][k] = St[n - 1][k] * k % mod + St[n - 1][k - 1]) %= mod;
  }
  for (int n = 1; n <= M; ++n) {
    LL bell = 0;
    for (int k = 0; k <= n; ++k) (bell += St[n][k]) %= mod;
    for (;cnt[n]; cnt[n] -= n) (ans *= bell) %= mod;
  }
  printf("%lld\n", ans);
}
