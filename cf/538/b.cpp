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

const int maxn = 1000005;
int dp[maxn];
int from[maxn] ;
int main() {
    vector <int> to;
    for(int i = 1; i <= (1 << 6); i++) {
        int sum = 0;
        int base = 1;
        for(int j = 0; j < 7; j++) {
            if((i >> j) & 1) {
                sum += base;
            }
            base *= 10;
        }
        to.PB(sum);
    }
    sort(to.begin(), to.end());
    to.resize(distance(to.begin(), unique(to.begin(), to.end())));
    /*for(auto i: to) {
        cout << i << endl;
    }*/
    int n;
    cin >> n;
    fill(dp, dp + n + 1, -1);
    fill(from, from + n + 1, -1);
    dp[0] = 0;
    from[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < to.size(); j++) {
            if(i - to[j] >= 0 && dp[i-to[j]] != -1 && (dp[i] == -1 || dp[i-to[j]] + 1 < dp[i])) {
                dp[i] = dp[i-to[j]] + 1;
                from[i] = i-to[j];
            } else if(i - to[j] < 0) {
                break;
            }
        }
    }
    cout << dp[n] << endl;
    vector <int> show;
    while(n != 0) {
        show.PB(n - from[n]);
        n = from[n];
    }
    sort(show.begin(), show.end());
    for(auto i: show) cout << i << ' ';
    cout << endl;
}
