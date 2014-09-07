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
    int a[1005];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    bool listing = true;
    for(int j = 0; j < n; j++) {
        if(a[j] == 1 && listing) {
            a[j] = 0;
            ans++;
            listing = false;
        }
        else if(a[j] == 1 && !listing) {
            a[j] = 0;
            ans++;
        }
        else if(a[j] == 0 && !listing) {
            listing = true;
            ans++;
        }
        else {
            continue;
        }
    }
    if(listing && ans > 0) {
        ans--;
    }
    cout << ans << endl;
}
