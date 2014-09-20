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
    int n;
    cin >> n;
    if(n >= 9) {
        cout << "YES" << endl;
        cout << "3 - 1 = 2" << endl;
        cout << "2 - 2 = 0" << endl;
        for(int i = 4; i <= n; i++) {
            if(i == 7 || i == 8 || i == 9) {
                continue;
            }
            else {
                printf("0 * %d = 0\n", i);
            }
        }
        cout << "7 + 8 = 15" << endl;
        cout << "15 + 9 = 24" << endl;
        cout << "24 + 0 = 24" << endl;
    }
    else {
        if(n <= 3) cout << "NO" << endl;
        else {
            if(n == 4) {
                cout << "YES" << endl;
                cout << "1 * 2 = 2" << endl;
                cout << "3 * 2 = 6" << endl;
                cout << "6 * 4 = 24" << endl;
            }
            else if(n == 5) {
                cout << "YES" << endl;
                cout << "3 - 1 = 2" << endl;
                cout << "2 + 2 = 4" << endl;
                cout << "4 * 5 = 20" << endl;
                cout << "4 + 20 = 24" << endl;
            }
            else if(n == 6) {
                cout << "YES" << endl;
                cout << "6 - 1 = 5" << endl;
                cout << "5 - 5 = 0" << endl;
                cout << "3 * 2 = 6" << endl;
                cout << "6 * 4 = 24" << endl;
                cout << "24 + 0 = 24" << endl;
            }
            else if(n == 7) {
                cout << "YES" << endl;
                cout << "7 - 1 = 6" << endl;
                cout << "6 - 6 = 0" << endl;
                cout << "5 * 0 = 0" << endl;
                cout << "3 * 2 = 6" << endl;
                cout << "6 * 4 = 24" << endl;
                cout << "24 + 0 = 24" << endl;
            }
            else if(n == 8) {
                cout << "YES" << endl;
                cout << "8 * 7 = 56" << endl;
                cout << "6 * 5 = 30" << endl;
                cout << "3 - 4 = -1" << endl;
                cout << "1 - 2 = -1" << endl;
                cout << "30 - -1 = 31" << endl;
                cout << "56 - 31 = 25" << endl;
                cout << "25 + -1 = 24" << endl;
            }
        }
    }
}
