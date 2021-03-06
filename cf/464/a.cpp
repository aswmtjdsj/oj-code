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
    int ans = 0;
    char str[105];
    cin >> n;
    cin >> str;
    int l = strlen(str);
    int res = 1;
    for(int i = 0; i < l; i++) {
        if(res == 0) {
            break;
        }
        else {
            if(str[i] == '0') {
                ans++;
                res = 0;
            }
            else {
                ans++;
                res = 1;
            }
        }
    }
    cout << ans << endl;
}
