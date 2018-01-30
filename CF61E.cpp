#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
int BIT[MAXN] = {0}, A[MAXN];
map<int, int> re;
set<int> S;
int n, idx;
void bit_reset(int n) {
  for (int i = 0; i <= n; ++i) BIT[i] = 0;
}
int query(int id) {
  int ans = 0;
  for (;id; id -= id&-id) ans += BIT[id];
  return ans;
}
void add(int id) {
  for (++id; id < MAXN; id += id&-id) ++BIT[id];
}
int interval_sum(int a, int b = 0) {
  return query(b) - query(a);
}

int front[MAXN] = {0}, back[MAXN] = {0};
int main() {
  idx = 0; scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", A + i), S.insert(A[i]);
  for (auto it = S.begin(); it != S.end(); ++it) re[*it] = idx++;
  for (int i = 0; i < n; ++i) A[i] = re[A[i]];
  bit_reset(n);
  for (int i = 0; i < n; ++i) add(A[i]), front[i] = interval_sum(A[i] + 1, MAXN - 1);
  bit_reset(n);
  for (int i = n - 1; i >= 0; --i) add(A[i]), back[i] = interval_sum(0, A[i]);
  long long ans = 0;
  for (int i = 0; i < n; ++i) ans += (long long) back[i] * front[i];
  printf("%lld\n", ans);
}
