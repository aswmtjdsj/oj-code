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
    int n, p, q;
    int a[105];
    while(cin >> n) {
        memset(a, 0, sizeof(a));
        cin >> p;
        for(int i = 0; i < p; i++) {
            int o;
            cin >> o;
            a[o] = 1;
        }
        cin >> q;
        for(int i = 0; i < q; i++) {
            int o;
            cin >> o;
            a[o] = 1;
        }
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            if(a[i] == 0) {
                cout << "Oh, my keyboard!" << endl;
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "I become the guy." << endl;
        }
    }
}
