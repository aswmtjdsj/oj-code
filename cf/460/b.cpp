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

long long powi(int x, int n) {
    long long a = 1;
    for(int i = 1; i <= n; i++) {
        a *= x;
    }
    return a;
}

int main() {
    int a, b, c;
    while(cin >> a >> b >> c) {
        vector <int> ans;
        for(int i = 1; i <= 81; i++) {
            long long t = powi(i, a) * b + c;
            int q = 0;
            long long x = t;
            while(x > 0) {
                q += (x % 10);
                x /= 10;
            }
            if(q == i && t < 1000000000) {
                ans.PB(t);
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ((i == ans.size() - 1)?'\n':' ');
        }
    }
}
