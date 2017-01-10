#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.141592653579

int main() {
    int t;
    cin >> t;
    for (int _ = 1; _ <= t; _++) {
        int p, x, y;
        cin >> p >> x >> y;
        x -= 50;
        y -= 50;
        bool flag = true;
        if (p == 0) {
            flag = false;
        } else if (p == 100) {
            if (x * x + y * y > 50 * 50) {
                flag = false;
            } else {
                flag = true;
            }
        } else if (x * x + y * y > 50 * 50) {
            flag = false;
        } else {
            double a = atan2(y, x);
            // cout << a << endl;
            if (a < 0.) {
                a = -a;
                a += PI / 2.;
            } else if (a < PI / 2. + 1e-6) {
                a = PI / 2. - a;
            } else {
                a -= PI / 2.;
                a = PI / 2. - a;
                a += 1.5 * PI;
            }
            a /= 2 * PI;
            // cout << a << endl;
            if (a < p / 100. + 1e-6) {
                flag = true;
            } else {
                flag = false;
            }
            // TODO
        }
        cout << "Case #" << _ << ": " << (flag ? "black" : "white") << endl;
    }
    return 0;
}
