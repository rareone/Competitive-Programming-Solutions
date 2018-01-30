#include <bits/stdc++.h>
const int INF = 1e9 + 10;
using namespace std;
typedef long long LL;
struct Seg {
  int frog = -1, l, r;
  Seg* ch[2] = {nullptr, nullptr};
  Seg(int l, int r): l(l), r(r){}
  int at(int x) {
    if (!ch[0]) return frog;
    int mid = l + r >> 1;
    if (x < mid) return max(frog, ch[0] -> at(x));
    else return max(frog, ch[1] -> at(x));
  }
  void set(int ql, int qr, int thefrog) {
    if (ql <= l and r <= qr) {
      frog = max(thefrog, frog);
      return;
    }
    int mid = l + r >> 1;
    if (ch[0] == nullptr) ch[0] = new Seg(l, mid), ch[1] = new Seg(mid, r);
    if (ql < mid) ch[0] -> set(ql, qr, thefrog);
    if (mid < qr) ch[1] -> set(ql, qr, thefrog);
  }
} *root = new Seg(0, INF);
      
struct Frog {
  LL t;
  int x, mos_count = 0, idx;
} A[200000];
multiset<pair<int,int>> mos;
int main() {
  int n, m, p, b; scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%lld", &A[i].x, &A[i].t);
    ++A[i].t;
    A[i].idx = i;
  }
  sort(A, A + n, [&] (Frog A, Frog B) {return A.x > B.x;});
  for (int i = 0; i < n; ++i) root -> set(A[i].x, min(A[i].x + A[i].t, (LL)INF), i);
  while (m--) {
    scanf("%d%d", &p, &b);
    int frog = root -> at(p);
    if (frog == -1) mos.insert({p, b});
    else {
      A[frog].t += b;
      ++A[frog].mos_count;
      auto it = mos.lower_bound({A[frog].x, 0});
      while (it != mos.end() and it -> first < A[frog].x + A[frog].t) {
        A[frog].t += it-> second;
        ++A[frog].mos_count;
        mos.erase(it);
        it = mos.upper_bound({A[frog].x, 0});
      }
      root -> set(A[frog].x, min(A[frog].x + A[frog].t,(LL) INF), frog);
    }
  }
  sort(A, A + n, [&] (Frog A, Frog B) {return A.idx < B.idx;});
  for (int i = 0; i < n; ++i) printf("%d %lld\n", A[i].mos_count, A[i].t - 1);
}
