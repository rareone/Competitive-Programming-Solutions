#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL MAXN = 100000, INF = 1e18, mod = 1e9 + 7;
vector<PLL> g[MAXN];
LL dp[2][MAXN], N, M, S, T, sp[2][MAXN];
void shortest(LL S, LL* dp, LL* sp) {
  priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
  fill(dp, dp + N, INF), fill(sp, sp + N, INF);
  dp[S] = 1;
  sp[S] = 0;
  pq.push({sp[S], S});
  while (pq.size()) {
    auto P = pq.top(); pq.pop();
    LL cur = P.first, v = P.second;
    if (cur != sp[v]) continue;
    for (PLL Q: g[v]) {
      LL d = Q.second, u = Q.first;
      if (d + cur == sp[u]) dp[u] = (dp[u] + dp[v]) % mod;
      else if (d + cur < sp[u]) sp[u] = d + cur, dp[u] = dp[v], pq.push({sp[u], u});
    }
  }
}

int main() {
  scanf("%lld%lld", &N, &M);
  scanf("%lld%lld", &S, &T), --S, --T;
  LL v, u, d;
  for (int i = 0; i < M; ++i)
    scanf("%lld%lld%lld", &v, &u, &d), --u, --v, 
    g[u].push_back({v, d}), g[v].push_back({u, d});
  shortest(S, dp[0], sp[0]), shortest(T, dp[1], sp[1]);
  LL D = sp[0][T], ans = dp[0][T] * dp[0][T] % mod;
  assert(dp[0][T] == dp[1][S]);
  auto sq = [=](LL x){x %= mod; return x * x % mod;};
  for (int i = 0; i < N; ++i) if (sp[0][i] * 2 == D and sp[1][i] * 2 == D) 
    ans = (ans - sq(dp[0][i] * dp[1][i])) % mod;
  for (int v = 0; v < N; ++v) for (PLL P: g[v]) {
    LL u = P.first, dis = P.second;
    if (sp[0][u] * 2 < D and sp[1][v] * 2 < D and sp[0][u] + sp[1][v] + dis == D)
      ans = (ans - sq(dp[0][u] * dp[1][v])) % mod;
  }
  printf("%lld\n", (ans + mod) % mod);
}
