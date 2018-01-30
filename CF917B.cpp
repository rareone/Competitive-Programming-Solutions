#include <bits/stdc++.h>
using namespace std;
int up = 0, down = 0, ans = 0;
typedef pair<int, int> PII;
vector<PII> g[100];
int dp[100][100][26];
int mex(set<int> &S) {
  int cur = 0;
  for (int v: S) if (v != cur) break; else ++cur;
  return cur;
}
int dfs(int i, int j, int c) {
  if (dp[i][j][c] != -1) return dp[i][j][c];
  set<int> tomex;
  for (PII P: g[i]) {
    int v = P.first, u = P.second;
    if (u < c) continue;
    tomex.insert(dfs(j, v, u));
  }
  return dp[i][j][c] = mex(tomex);
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n, m, u, v;
  char s[10];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) 
    scanf("%d%d%s", &u, &v, s), --u, --v, g[u].push_back({v, s[0] - 'a'});
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) printf("%c", dfs(i, j, 0)? 'A': 'B');
    puts("");
  }
}
