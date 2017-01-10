#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int _ = 1; _ <= t; _++) {
        int ans = 1;
        int n;
        vector <int> a;
        vector <int> b;
        cin >> n;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        for (int j = n; j >= 1; j--) {
            b.resize(n, 0);
            for (int i = 0; i < j; i++) {
                b[i] = ceil(50. / a[i]);
            }
            int sum = 0;
            accumulate(b.begin(), b.begin() + j, sum);
            // cout << j << ": ";
            for (int i = 0; i < j; i++) {
                sum += b[i];
                // cout << b[i] << ' ';
            }
            // cout << "-> " << sum << endl;
            if (sum <= n) {
                ans = j;
                break;
            }
        }
        cout << "Case #" << _ << ": " << ans << endl;
    }
    return 0;
}
