#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>

#include <string>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <list>
#include <vector>

#include <algorithm>
#include <complex>
using namespace std;

#define len(x) (x).size()
#define VI vector<int> 

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

template <class T>
inline T sqr(T x) { return x * x; }

const int inf = ~0u >> 1;
const double eps = 1e-8;
const double pi = acos(-1.0);

int sgn(double x) {
	return fabs(x) < eps ? 0:x < -eps?-1:1;
}

int main() {
    int64 l, r;
    int k;
    while(cin >> l >> r >> k) {
        if(k >= 4) {
            if(r - l >= 4) { // card([l, r]) >= 5
                if(l % 2 == 0) { // l even
                    cout << "0\n4\n";
                    for(int i = 0; i < 4; i++) {
                        cout << l + i << (i==3?'\n':' ');
                    }
                }
                else {
                    cout << "0\n4\n";
                    for(int i = 0; i < 4; i++) {
                        cout << l + i + 1 << (i==3?'\n':' ');
                    }
                }
            }
            else { // card([l, r]) == 4
                if(l % 2 == 0) { // l even
                    cout << "0\n4\n";
                    for(int i = 0; i < 4; i++) {
                        cout << l + i << (i==3?'\n':' ');
                    }
                }
                else { // l odd
                    goto gao;
                }
            }
        }
        else if(k == 3) { // k == 3
gao:
            bool flag = false;
            int64 a = 3ll, b = 5ll, c = 6ll;
            if(r - l <= 10000ll) {
                for(int64 i = l; i < r; i++) {
                    int64 t = i ^ (i+1);
                    if(l <= t && t <= r) {
                        a = i;
                        b = i + 1;
                        c = t;
                        flag = true;
                        break;
                    }
                }
            }
            else {
                while(c <= r) {
                    if(l <= a && a <= r && l <= b && b <= r && l <= c && c <= r) {
                        flag = true;
                        break;
                    }
                    a = (a << 1) + 1;
                    b = (b << 1) + 1;
                    c = (c << 1);
                }
            }
            if(flag) {
                cout << "0\n3\n";
                cout << a << ' ' << b << ' ' << c << '\n';
            }
            else {
                cout << "1\n2\n";
                if(l % 2 == 0) {
                    cout << l << ' ' << l + 1 << '\n';
                }
                else {
                    cout << l + 1<< ' ' << l + 2 << '\n';
                }
            }
        }
        else if(k == 2) { // k == 2
            if(l % 2 == 0) {
                cout << "1\n2\n";
                cout << l << ' ' << l + 1 << '\n';
            }
            else {
                if(r - l >= 2) { // card([l, r]) >= 3
                    cout << "1\n2\n";
                    cout << l + 1 << ' ' << l + 2 << '\n';
                }
                else { // card([l, r]) == 2
                    if((l ^ r) > r) {
                        cout << l << '\n' << 1 << '\n' << l << '\n';
                    }
                    else {
                        cout << (l ^ r) << '\n' << 2 << '\n' << l << ' ' << r << '\n';
                    }
                }
            }
        }
        else { // k == 1
            cout << l << '\n' << "1\n" << l << '\n';
        }
    }
}
