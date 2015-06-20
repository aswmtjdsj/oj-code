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
int main() {
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++) {
        int n, c, q;
        vector < vector <int> > g;
        vector <int> color;
        cin >> n >> c >> q;
        color.resize(n, 1);
        g.resize(n);
        for(int i = 0; i < n - 1; i++) {
            int a;
            cin >> a;
            a--;
            g[a].PB(i+1);
        }
        /*for(int i = 0; i < n; i++) {
            cout << i << ": ";
            for(auto v: g[i]) {
                cout << v << ' ';
            } cout << endl;
        }*/
        int ans = 0;
        for(int i = 0; i < q; i++) {
            int _a, _l, _c;
            cin >> _a >> _l >> _c;
            _a--;
            if(_c == 0) {
                ans = (ans + color[_a] * (i + 1)) % mod;
            } else {
                queue <int> Q;
                int l = 0;
                Q.push(_a);
                int prev = 1, next = 0;
                while(!Q.empty() && l <= _l) {
                    // cerr << "fuck" << endl;
                    int cur = Q.front();
                    Q.pop();
                    color[cur] = _c;
                    // cout << cur << ' ' << g[cur].size() << endl;
                    for(auto v: g[cur]) {
                        Q.push(v);
                        next++;
                    }
                    // cerr << "done" << endl;
                    prev--;
                    if(prev == 0) {
                        prev = next;
                        next = 0;
                        l++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
