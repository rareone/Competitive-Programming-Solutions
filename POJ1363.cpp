#include <iostream>
int st[100000], top = 0, A[100000];
int main() {
  int N, first = 1;
  while (scanf("%d", &N) && N) {
    if (!first) puts("");
    first = 0, top = 0;
    while (~scanf("%d", A)) {
      if (!A[0]) break;
      for (int i = 1; i < N; ++i) scanf("%d", A + i);
      int cur = 0;
      for (int i = 1; i <= N; ++i) {
        st[top++] = i;
        while (top && st[top - 1] == A[cur]) ++cur, --top;
      }
      puts(cur ==  N ? "Yes" : "No");
    }
  }
}
