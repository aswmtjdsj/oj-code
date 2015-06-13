/* base IO */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>
#include <cassert>

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

int main() {
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++) {
        int n, r;
        vector < vector <int> > g;
        vector <int> in, out;
        cin >> n >> r;
        g.resize(n);
        in.resize(n, 0);
        out.resize(n, 0);
        for(int i = 0; i < r; i++) {
            int u, v;
            cin >> u >> v;
            g[v].PB(u);
            in[u]++;
            out[v]++;
        }
        int ans = 0;
        while(true) {
            vector <int> cur;
            for(int i = 0; i < n; i++) {
                if(in[i] == 0 && out[i] != 0) {
                    cur.PB(i);
                }
            }

            if(cur.size() > 0) {
                for(auto i: cur) {
                    // printf("%d: %d\n", ans, i);
                    for(auto j: g[i]) {
                        out[i]--;
                        in[j]--;
                    }
                }
                ans++;
            } else {
                for(int i = 0; i < n; i++) {
                    if(in[i] != 0) {
                        ans = -1;
                        break;
                    }
                }
                break;
            }
        }

        if(ans != -1) {
            printf("Case %d: %d semester(s)\n", _+1, ans + 1);
        } else {
            printf("Case %d: Never Ends\n", _+1);
        }
    }
}
