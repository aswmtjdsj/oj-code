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

const int maxn = 25;

int main() {
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++) {
        int p, c, f;
        cin >> p >> c >> f;
        int n;
        cin >> n;
        int np[maxn], nc[maxn], nf[maxn];
        for(int i = 0; i < n; i++) {
            cin >> np[i] >> nc[i] >> nf[i];
        }
        bool flag = false;
        for(int j = 0; j < (1 << n); j++) {
            int tp = 0, tc = 0, tf = 0;
            for(int i = 0; i < n; i++) {
                if((1 << i) & j) {
                    tp += np[i];
                    tc += nc[i];
                    tf += nf[i];
                }
            }
            if(tp == p && tc == c && tf == f) {
                flag = true;
                break;
            }
        }
        cout << "Case #" << k << ": " << (flag?"yes":"no") << endl;
    }
}
