#include <bits/stdc++.h>

using namespace std;

int N[10] = {0};
long long ans = 0, a, b;

bool test() {
  long long T = ans;
  for (int i = 0; i < 10; ++i) 
    for (int j = 0; j < N[i]; ++j)
      T = T * 10 + i;
  return T <= b;
}


void dfs() {
  for (int i = 9; i >= 0; --i) {
    if (N[i]) {
      ans = ans * 10 + i;
      --N[i];
      if (test()) return dfs();
      ++N[i];
      ans /= 10;
    }
  }
}

int main() {
  cin >> a >> b;
  while (a) ++N[a%10], a/=10;
  dfs();
  cout << ans << endl;
}

