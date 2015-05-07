#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int n, k, p, x, y;
  cin >> n >> k >> p >> x >> y;
  const int maxn = 1000;
  int a[maxn], b[maxn];
  for(int i = 0; i < k; i++) {
    cin >> a[i];
  }
  int need = 0;
  bool ok = false;
  while(need <= n - k) {
    int temp = need;
    for(int i = 0; i < k; i++) { b[i] = a[i]; }
    for(int i = k; i < n; i++) {
      if(temp > 0) {
        b[i] = y;
        temp--;
      } else {
        b[i] = 1;
      }
    }
    sort(b, b + n);
    int sum = accumulate(b, b + n, 0);
    /*for(int i = 0; i < n; i++) cout << b[i] << ' ';
    cout << endl;*/
    if(sum > x || b[n/2] < y) {
      need++;
    } else {
      ok = true;
      break;
    }
  }
  if(ok) {
    for(int i = 0; i < need; i++) cout << y << ' ';
    for(int i = need; i < n - k; i++) cout << 1 << ' ';
    cout << endl;
  } else {
    cout << -1 << endl;
  }
  
  return 0;
}
