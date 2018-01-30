#include <bits/stdc++.h>
struct seg {
  seg* ch[2] = {nullptr, nullptr};
  int lb, rb, num = 0;
  seg(int l, int r): lb(l), rb(r) {}
  void modify(int p, int x) {
    //printf("modify index = %d, num = %d at [%d, %d)\n", p, x, lb, rb); 
    if (lb == p and p + 1 == rb) {num = x; return;}
    int mid = lb + rb >> 1;
    if (p < mid) {
      if (ch[0] == nullptr) ch[0] = new seg(lb, mid);
      ch[0] -> modify(p, x);
      num = ch[1] == nullptr? ch[0] -> num : std::__gcd(ch[0] -> num, ch[1] -> num);
    }
    if (mid <= p) {
      if (ch[1] == nullptr) ch[1] = new seg(mid, rb);
      ch[1] -> modify(p, x);
      num = ch[0] == nullptr? ch[1] -> num :std::__gcd(ch[0] -> num, ch[1] -> num);
    }
  }
  int query(int ql, int qr, int x, int cont = 2) {
    //printf("query [%d, %d) at [%d, %d) x = %d to find %d error\n", ql, qr, lb, rb, x, cont);
    if (cont < 1) return 2;
    if (ql <= lb and rb <= qr) {
      if (num % x) { 
        seg* cur = this;
        while (cur -> rb - cur -> lb != 1) {
          if (cur -> ch[0] -> num % x and cur -> ch[1] -> num % x) return 2;
          else cur = cur -> ch[0] -> num % x? cur -> ch[0] : cur -> ch[1];
        }
        return 1;
      }
      else return 0;
    }
    int mid = lb + rb >> 1, sum = 0;
    if (ql < mid) sum += ch[0] -> query(ql, qr, x, cont);
    if (mid < qr) sum += ch[1] -> query(ql, qr, x, cont - sum);
    return std::min(sum, 2);
  }
};
int main() {
  int n, a; scanf("%d", &n);
  seg* root = new seg(0, n);
  for (int i = 0; i < n; ++i) scanf("%d", &a), root -> modify(i, a);
  int q, t, l, r, x; scanf("%d", &q);
  while (q--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d%d", &l, &r, &x);
      puts(root->query(l - 1, r, x) < 2? "YES":"NO");
    }
    else scanf("%d%d",&l, &x), root->modify(l - 1, x);
  }
}
