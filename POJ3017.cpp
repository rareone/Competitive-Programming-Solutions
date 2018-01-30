#include <iostream>
using namespace std;

long long A[100010] = {0}, S[100010] = {0}, dp[100010] = {0};
int deq[100010], l = 0, r = 0, j = 0;
int main() {
  int N, M;
  while (~scanf("%d%d", &N, &M)) {
    for (int i = 1; i <= N; ++i) scanf("%lld", A + i), S[i] = A[i] + S[i - 1];
    dp[0] = 0, deq[r++] = 0, j = 0;
    for (int i = 1; i <= N; ++i) {
      while (S[i] - S[j] > M) ++j;
      while (deq[l] <= j) ++l;
      dp[i] = dp[j]
    }
  }
}
