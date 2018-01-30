#include <cstdio>
const int MAXN = 50000 * 3;
int p[MAXN], r[MAXN];
int root(int x) {
  return p[x] == x? x: p[x] = root(p[x]);
}
bool merge(int x, int y) {
  x = root(x), y = root(y);
  if (x == y) return false;
  if (r[x] > r[y]) p[y] = x;
  else p[x] = y, r[y] += r[y] == r[x];
  return true;
}
int main() {
  int ans = 0, N, K, t, x, y;
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N * 3; ++i) p[i] = i, r[i] = 1;
  while (K--) {
    scanf("%d%d%d", &t, &x, &y);
    --x, --y, --t;
    if (x >= N or y >= N) {
      ++ans;
      continue;
    }
    int X[3] = {root(x)}, Y[3] = {(root(y) + t * N) % (N * 3)};
    for (int i = 1; i < 3; ++i) X[i] = root((X[i - 1] + N) % (N * 3));
    for (int i = 1; i < 3; ++i) Y[i] = root((Y[i - 1] + N) % (N * 3));
    bool ok = 1;
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) 
      if (i != j and X[i] == Y[j]) ok = 0;
    if (ok) for (int i = 0; i < 3; ++i) merge(X[i], Y[i]);
    else ++ans;
  }
  printf("%d\n",ans);
} 
