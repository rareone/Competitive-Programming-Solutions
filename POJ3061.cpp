#include <iostream>
using namespace std;
int A[100000];
int main() {
  int T; scanf("%d", &T);
  while (T--) {
    int N, M, l = 0 , r = 0, sum = 0;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    while ( r < N and sum < M) sum += A[r++];
    if (r == N and sum < M) {
      puts("0");
      continue;
    }
    while ( sum - A[l] >= M) sum -= A[l++];
    int ans = r - l;
    for (; r < N; ) {
      sum += A[r++];
      while ( sum - A[l] >= M) sum -= A[l++];
      ans = min(ans, r - l);
    }
    printf("%d\n", ans);
  }
}
