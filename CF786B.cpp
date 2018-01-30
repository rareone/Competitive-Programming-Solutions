#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
LL d[2][200000];
int n, q, s;
vector<PLL> g[2][200000];
void add_edge(int t, int v, int w, int l, int r = 0) {
  if (t == 1) return g[0][v + n].push_back({l + n << 1, w});
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) {
      if (t == 2) g[0][v + n].push_back({l << 1, w});
      else g[1][l].push_back({(v + n) << 1 | 1, w});
      ++l;
    }
    if (r&1) {
      --r;
      if (t == 2) g[0][v + n].push_back({r << 1, w});
      else g[1][r].push_back({(v + n) << 1 | 1, w});
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &q, &s);
  --s;
  int t, v, w, l, r;
  for (int i = n - 1; i; --i) 
    g[0][i].push_back({i << 2, 0}),
    g[0][i].push_back({(i << 1 | 1 ) << 1, 0}),
    g[1][i << 1].push_back({i << 1 | 1, 0}),
    g[1][i << 1 | 1].push_back({i << 1 | 1, 0});
  for (int i = n; i < 2 * n; ++i) 
    g[0][i].push_back({i << 1 | 1, 0}), g[1][i].push_back({i << 1, 0});
  for (int i = 0; i < 2; ++i) fill(d[i], d[i] + 2 * n, 1ll << 62);
  for (int i = 0; i < q; ++i) {
    scanf("%d", &t);
    if (t == 1) scanf("%d%d%d", &v, &l, &w), add_edge(t, v - 1, w, l - 1);
    else scanf("%d%d%d%d", &v, &l, &r, &w), add_edge(t, v - 1, w, l - 1, r);
  }
  priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
  d[0][s + n] = 0;
  pq.push({d[0][s + n], s + n << 1});
  while (pq.size()) {
    PLL P = pq.top(); pq.pop();
    LL dis = P.first, k = P.second&1, v = P.second >> 1;
    if (dis != d[k][v]) continue;
    for (PLL Q : g[k][v]) {
      LL w = Q.second, kk = Q.first&1, u = Q.first >> 1;
      if (dis + w < d[kk][u]) {
        d[kk][u] = dis + w;
        pq.push({d[kk][u], Q.first});
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (d[0][i + n] == 1ll << 62) d[0][i + n] = -1;
    printf("%lld%c", d[0][i + n], " \n"[i == n - 1]);
  }
}
