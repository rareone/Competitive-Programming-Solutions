#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, pos, l, r;
  cin >> n >> pos >> l >> r;
  int ans = 1000000;
  if (l == 1 and r == n) return 0 * puts("0");
  else if (l == 1) return 0 * printf("%d\n", r - pos + 1);
  else if (r == n) return 0 * printf("%d\n", pos - l + 1);
  ans = min(ans, pos - l + r - l);
  ans = min(ans, r - pos + r - l);
  printf("%d\n", ans + 2);
}

