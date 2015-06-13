#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    const int maxn = 2005;
    const double eps = 1e-6;
    double x[maxn], y[maxn];
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    if(fabs(y[0] - y[n-2]) > 1) {
        cout << "square-wave" << endl;
        for(int i = 1; i < n; i++) {
            if(fabs(y[i] - y[0]) > 1) {
                double t = x[i] * 2;
                int ans = 5;
                double min = 50;

                for(int f = 5; f <= 50; f += 5) {
                    //cout << f << ' ' << 1. / t << endl;
                    if(min > fabs(f - 1. / t)) {
                        ans = f;
                        min = fabs(f - 1. / t);
                    }
                }
                cout << ans << endl;
                break;
            }
        }
    } else {
        cout << "sine-wave" << endl;
        for(int i = 1; i < n; i++) {
            if(y[i] > 0.97) {
                double t = x[i] * 4;
                int ans = 5;
                double min = 50;

                for(int f = 5; f <= 50; f += 5) {
                    //cout << f << ' ' << 1. / t << endl;
                    if(min > fabs(f - 1. / t)) {
                        ans = f;
                        min = fabs(f - 1. / t);
                    }
                }
                cout << ans << endl;
                break;
            }
        }
    }

    return 0;
}
