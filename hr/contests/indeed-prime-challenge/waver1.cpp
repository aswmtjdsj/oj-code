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

const int maxn = 10005;
const int maxe = 1005;
int d[maxn][maxe];
int main() {
    int n, e, k;
    cin >> n >> e >> k;
    vector < vector <PII> > normal, shortcut;
    vector <int> deg;
    vector <bool> vis;
    normal.resize(n);
    shortcut.resize(n);
    vis.resize(n, false);
    deg.resize(n, 0);
    for(int i = 0; i < n; i++) {
        fill(d[i], d[i] + k + 1, inf);
    }
    for(int i = 0; i < n - 1; i++) {
        int a, b, w;
        scanf(" %d %d %d", &a, &b, &w);
        a--;
        b--;
        normal[a].PB(MP(b, w));
        normal[b].PB(MP(a, w));
        deg[a]++;
        deg[b]++;
    }
    for(int i = 0; i < e; i++) {
        int a, b, w;
        scanf(" %d %d %d", &a, &b, &w);
        a--;
        b--;
        shortcut[a].PB(MP(b, w));
        shortcut[b].PB(MP(a, w));
    }
    queue <int> Q;
    for(int i = 0; i < n; i++) {
        if(deg[i] <= 1) {
            d[i][0] = 0;
            // cout << i << endl;
            Q.push(i);
            vis[i] = true;
        }
    }
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        vis[cur] = false;
        for(auto p: normal[cur]) {
            int prev = inf;
            for(int i = 0; i <= k; i++) {
                if(d[cur][i] != inf && d[cur][i] + p.second >= prev) {
                    prev = min(d[p.first][i], prev);
                    continue;
                }
                if(d[cur][i] != inf && d[p.first][i] > d[cur][i] + p.second) {
                    d[p.first][i] = d[cur][i] + p.second;
                    if(!vis[p.first]) {
                        vis[p.first] = true;
                        Q.push(p.first);
                    }
                }
                prev = min(d[p.first][i], prev);
            }
        }
        for(auto p: shortcut[cur]) {
            int prev = inf;
            for(int i = 0; i < k; i++) {
                if(d[cur][i] != inf && d[cur][i] + p.second >= prev) {
                    prev = min(d[p.first][i+1], prev);
                    continue;
                }
                if(d[cur][i] != inf && d[p.first][i+1] > d[cur][i] + p.second) {
                    d[p.first][i+1] = d[cur][i] + p.second;
                    if(!vis[p.first]) {
                        vis[p.first] = true;
                        Q.push(p.first);
                    }
                }
                prev = min(d[p.first][i+1], prev);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        int ans = inf;
        for(int j = 0; j <= k; j++) {
            // printf("%d ", d[i][j]);
            ans = min(ans, d[i][j]);
        }
        printf("%d\n", ans);
    }
}
