#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long double c[2], r, a[3][2];
const long double eps = 1e-8;
int sgn(long double x) {
    return fabs(x) < eps ? 0: x < -eps? -1: 1;
}
bool in(long double x, long double y, int i, int j) {
    return sgn((x - a[i][0]) * (x - a[j][0])) <= 0 && sgn((y - a[i][1]) * (y - a[j][1])) <= 0;
}
bool gao(int i, int j) {
    long double x[2], y[2];
    x[0] = a[i][0];
    y[0] = a[i][1];
    x[1] = a[j][0];
    y[1] = a[j][1];
    if(sgn(x[0]-x[1]) != 0) {
        long double k = (y[0] - y[1]) / (x[0] - x[1]),
               b = y[0] - k * x[0];
        long double A = 1 + k * k,
               B = 2. * k * (b - c[1]) - 2. * c[0],
               C = c[0] * c[0] + (b - c[1]) * (b - c[1]) - r * r;
        long double det = B * B - 4 * A * C;
        /*cout << "k: " << k << endl;
        cout << "b: " << b << endl;
        cout << "A: " << A << endl;
        cout << "B: " << B << endl;
        cout << "C: " << C << endl;
        cout << "det: " << det << endl;*/
        if(sgn(det) < 0) {
            return false;
        }
        else if(sgn(det) == 0) {
            long double xans = - B / 2. / A;
            long double yans = k * xans + b;
            //cout << xans << ", " << yans << endl;
            if(in(xans, yans, i, j)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            long double xans = (-B + sqrt(det)) / 2. / A;
            long double yans = k * xans + b;
            //cout << xans << ", " << yans << endl;
            if(in(xans, yans, i, j)) {
                return true;
            }
            xans = (-B - sqrt(det)) / 2. / A;
            yans = k * xans + b;
            //cout << xans << ", " << yans << endl;
            if(in(xans, yans, i, j)) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    else {
        long double q = 0,// (x[0] - x[1]) / (y[0] - y[1]),
               d = x[0] - q * y[0];
        long double A = 1 + q * q,
               B = 2. * q * (d - c[0]) - 2. * c[1],
               C = c[1] * c[1] + (d - c[0]) * (d - c[0]) - r * r;
        long double det = B * B - 4 * A * C;
        /*cout << "q: " << q << endl;
        cout << "d: " << d << endl;
        cout << "A: " << A << endl;
        cout << "B: " << B << endl;
        cout << "C: " << C << endl;
        cout << "det: " << det << endl;*/
        if(sgn(det) < 0) {
            return false;
        }
        else if(sgn(det) == 0) {
            long double yans = - B / 2. / A;
            long double xans = q * yans + d;
            //cout << xans << ", " << yans << endl;
            if(in(xans, yans, i, j)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            long double yans = (-B + sqrt(det)) / 2. / A;
            long double xans = q * yans + d;
            //cout << xans << ", " << yans << endl;
            if(in(xans, yans, i, j)) {
                return true;
            }
            yans = (-B - sqrt(det)) / 2. / A;
            xans = q * yans + d;
            //cout << xans << ", " << yans << endl;
            if(in(xans, yans, i, j)) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--) {

        cin >> c[0] >> c[1] >> r;
        for(int i = 0; i < 3; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        bool flag = false;
        for(int i = 0; i < 3; i++) {
            int j = (i + 1) % 3;
            if(gao(i, j)) {
                cout << "YES" << endl;
                flag = true;
                break;
            }
        }
        if(!flag) cout << "NO" << endl;
    }
    return 0;
}
