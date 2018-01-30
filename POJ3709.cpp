#include <algorithm>
#include <iostream>

using namespace std;
long long dp[500000], A[500000], S[510000] = {0}, deq[510000];;

inline long long a(int j) {
  return dp[j] - S[j] + A[j + 1] * j;
}
inline long long f(int i, int j) {
  return S[i] + a(j) - A[j + 1] * i;
}

bool onto(int i, int j, int k) {
  if (A[i + 1] == A[j + 1]) return a(j) > a(i);
  double x = (a(j) - a(i)) / (A[i + 1] - A[j + 1]);
  return x * A[k + 1] + a(k) <= x *  A[j + 1] + a(j);
}
int main() {
  int T; scanf("%d", &T);
  while (T--) {
    int N, K; scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; ++i) {
      scanf("%lld", A + i);
      S[i] = A[i] + S[i - 1];
    }
    fill(dp, dp + K , 1e12);
    dp[0] = 0;
    dp[K] = S[K] - A[1] * K;
    int l = 0, r = 0;
    deq[r++] = 0;
    for (int i = K + 1; i <= N; ++i) {
      while (r - l >= 2 and f(i, deq[l]) >= f(i, deq[l + 1])) ++l; 
      int j = deq[l], nj = i - K + 1;
      dp[i] = f(i, j);
      while (r - l >= 2 and onto(deq[r - 2], deq[r - 1], nj)) --r;
      deq[r++] = nj;
    }
    printf("%lld\n", dp[N]);
  }
}
