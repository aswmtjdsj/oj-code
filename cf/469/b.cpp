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

const int N = 55;
int a[N], b[N], c[N], d[N];
int slot[1005];

int main() {
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    memset(slot, 0, sizeof(slot));
    for(int i = 0; i < p; i++) {
        cin >> a[i] >> b[i];
        for(int j = a[i]; j <= b[i]; j++) {
            slot[j] = 1;
        }
    }
    for(int i = 0; i < q; i++) {
        cin >> c[i] >> d[i];
    }

    int cnt = r - l + 1;
    for(int i = l; i <= r; i++) {
        bool flag = false;
        for(int j = 0; j < q && !flag; j++) {
            for(int k = c[j]; k <= d[j] && !flag; k++) {
                if(k + i <= 1000 && slot[k+i] == 1) {
                    flag = true;
                }
            }
        }
        if(!flag) cnt--;
    }

    cout << cnt << endl;
}
