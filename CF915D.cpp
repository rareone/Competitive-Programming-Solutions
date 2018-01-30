#include <bits/stdc++.h>

using namespace std;
vector<int> g[500], tpsort;
int nth[500];
int n, m, u, v;

bool testcyclicshift(bool i) {
  int ans = 0;
  for (int v = 0; v < n; ++v) {
    for (int u : g[v]) {
      int k = (nth[v] + i) % n, j = (nth[u] + i) % n;
      ans += k > j;
    }
  }
  return ans <= 1;
}
bool vis[500] = {0};
void dfs(int v) {
  vis[v] = 1;
  for (int u : g[v]) 
    if (!vis[u]) dfs(u);
  tpsort.push_back(v);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v), --u, --v;
    g[u].push_back(v);
  }
  for (int i = 0; i < n; ++i) if (!vis[i]) dfs(i);
  reverse(tpsort.begin(), tpsort.end());
  for (int i = 0; i < n; ++i) nth[tpsort[i]] = i;
  for (int i = 0; i < n; ++i) if (testcyclicshift(i)) return 0 * puts("YES");
  puts("NO");
}


