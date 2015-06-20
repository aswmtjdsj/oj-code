/* base IO */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>

/* data structure */
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>

/* alrotihm and math */
#include <algorithm>
#include <random>
#include <cmath>

/* run-time */
#include <cstdlib>
#include <ctime>
#include <climits>

/* system dependent */
#include <sys/time.h>

using namespace std;

#define VI vector<int>
#define VD vector<double>
#define PII pair<int, int>
#define PDD pair<double, double>
#define PB push_back
#define MP make_pair
#define len(x) ((x).size())

const int inf = INT_MAX;
const long long inf_ll = 0x7f7f7f7f;
const double eps = 1e-8;

/*
 * 0 1 2
 * 3   4
 * 5 6 7
 */
const int bfs_dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int bfs_dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
 *   3  
 * 2   0
 *   1  
 */
const int dfs_dy[] = {0, 1, 0, -1};
const int dfs_dx[] = {1, 0, -1, 0};

PII dir[] = {make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)};
/* TC HEADER END */

const int mod = 1000000007;

vector <int> fa[2], _rank[2];
int query(int m, int x) {
    if(fa[m][x] != x) {
        fa[m][x] = query(m, fa[m][x]);
    } else {
        return x;
    }
}
int main() {
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++) {
        int n, q;
        cin >> n >> q;
        int ans = 0;
        int f, a, b, last_c = 0;
        for(int m = 0; m < 2; m++) {
            fa[m].resize(n+1);
            _rank[m].resize(n+1);
            for(int i = 1; i <= n; i++) {
                _rank[m][i] = 1;
                fa[m][i] = i;
            }
        }
        for(int p = 1; p <= q; p++) {
            if(last_c == n * (n + 1) / 2) {
                ans += (p * last_c) % mod;
                ans %= mod;
                continue;
            }
            cin >> f >> a >> b;
            f--;
            int faa = query(f, a), fab = query(f, b);
            if(faa != fab) {
                if(_rank[f][faa] > _rank[f][fab]) {
                    fa[f][fab] = faa;
                    _rank[f][faa] += _rank[f][fab];
                } else {
                    fa[f][faa] = fab;
                    _rank[f][fab] += _rank[f][faa];
                }
            }
            int c = 0;
            for(int i = 1; i <= n; i++) {
                for(int j = i + 1; j <= n; j++) {
                    int faa = query(0, i), fab = query(0, j);
                    int faa2 = query(1, i), fab2 = query(1, j);
                    if(faa == fab && faa2 == fab2) {
                        c++;
                    }
                }
            }
            ans += (p * c) % mod;
            ans %= mod;
            last_c = c;
        }
        cout << ans << endl;
    }
}
