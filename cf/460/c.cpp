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

const int maxn = 100005;

int low_bit(int x) { 
    return x & (-x); 
}

int64 a[maxn], s[maxn];
int n, m, w;

void add(int i, int64 val) {
    while(i <= n) {
        s[i] += val;
        i += low_bit(i);
    }
}

int64 get(int i) {
    int64 ans = 0;
    while(i > 0) {
        ans += s[i];
        i -= low_bit(i);
    }
    return ans;
}

bool fuck(int64 x) {
    int64 need = 0;
    memset(s, 0, sizeof(s));
    for(int i = 1; i <= n; i++) {
        int64 biu = get(i);
        if(a[i] + biu < x) {
            need += x - biu - a[i];
            add(i, x - biu - a[i]);
            add(i + w, -(x - biu - a[i]));
        }
        /*for(int j = 1; j <= n; j++) {
            cout << s[j] << ' ' ;
        }
        cout << endl;*/
    }
    //cout << x << ' ' << need << endl;
    return need <= m; // can do, so can raise up
}

int main() {
    while(cin >> n >> m >> w) {
        int64 minn = 1000000000+1, maxx = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            minn = min(minn, a[i]);
            maxx = max(maxx, a[i]);
        }
        int64 l = minn, r = maxx + m, ans;
        while(l <= r) {
            int64 mid = (l + r) >> 1;
            if(fuck(mid)) {
                l = mid + 1;
                ans = mid;
            }
            else {
                r = mid-1;
            }
        }
        cout << ans << endl;
    }
}
