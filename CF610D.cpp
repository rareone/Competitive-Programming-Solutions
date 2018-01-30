#include <bits/stdc++.h>
using namespace std;
struct Seg {
  int l, r, num = 0, covertime = 0;
  Seg* ch[2] = {nullptr, nullptr};
  Seg(int l, int r): l(l), r(r){}
  int count() {
    if (covertime) return r - l;
    int ans = 0;
    for (int i = 0; i < 2; ++i)
      if (ch[i] != nullptr) 
        ans += ch[i] -> num;
    return ans;
  }
  void modify(int ql, int qr, int add) {
    if (ql <= l and r <= qr) {
      covertime += add;
      num = count();
      return;
    }
    int mid = (l + r) / 2;
    if (ql < mid) {
      if (ch[0] == nullptr) 
        ch[0] = new Seg(l, mid);
      ch[0] -> modify(ql, qr, add);
    }
    if (mid < qr) {
      if (ch[1] == nullptr) 
        ch[1] = new Seg(mid, r);
      ch[1] -> modify(ql, qr, add);
    }
    num = count();
  }
} *root = new Seg( -(1 << 30), 1 << 30);
struct Event {
  int time, l, r, add;
} ops[200000];

int main() {
  int n, x1, y1, x2, y2; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (y1 > y2) swap(y1, y2); 
    if (x1 > x2) swap(x1, x2);
    ++x2;
    ++y2;
    ops[i] = {x1, y1, y2, 1};
    ops[i + n] = {x2, y1, y2, -1};
  }
  sort(ops, ops + 2 * n, [&](Event a, Event b) {return a.time < b.time;});
  int cur = -(1<<30);
  long long ans = 0;
  for (int i = 0; i < 2 * n; ++i) {
    ans += (long long) (ops[i].time - cur) * root->num;
    cur = ops[i].time;
    root->modify(ops[i].l, ops[i].r, ops[i].add);
  }
  assert(root->num == 0);
  printf("%lld\n", ans);
}
