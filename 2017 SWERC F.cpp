#include <bits/stdc++.h>
using namespace std;
typedef complex<float> pt;
float eps() {
  static float kn = 10;
  static int s = 0;
  return kn = 10 / (1. + kn * s++);
}

pt A[100];
int d[100], N;

float f(pt x) {
  float ans = 0;
  for (int i = 0; i < N; ++i) 
    ans += - pow(max(abs(x - A[i]) - d[i], (float) 0), 2);
  if (ans < 1e-8) ans += pow(abs(x), 2) * 0.1;
  return ans;
}

const auto dx = pt(1e-6, 0), dy = pt(0, 1e-6);
int main() {
  for (int i = 0; i < 100; ++i) cout << eps() << endl;
  scanf("%d", &N);
  
  int x, y;
  for (int i = 0; i < N; ++i) {
    scanf("%d%d%d", &x, &y, d + i);
    A[i] = pt(x, y);
  }
  pt cur = pt(1000,1000);
  for (int i = 0; i < 10; ++i) {
    auto ys = f(cur), Dx = (f(cur + dx) - ys)/(float)1e-6, Dy = (f(cur + dy) - ys) / (float)1e-6;
    pt gd = pt(Dx, Dy);
    cur = cur + gd * eps();
    cout << gd << cur << endl;
  }
  cout << eps() << cur << endl;
}
