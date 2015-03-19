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
 *  * 0 1 2
 *   * 3   4
 *    * 5 6 7
 *     */
const int bfs_dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int bfs_dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
 *  *   3  
 *   * 2   0
 *    *   1  
 *     */
const int dfs_dy[] = {0, 1, 0, -1};
const int dfs_dx[] = {1, 0, -1, 0};

PII dir[] = {make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)};
/* TC HEADER END */

class SingingEasy {
    public:
        int dp[2005][2][2010], n, offset;
        vector <int> p;
        int dfs(int step, bool now, int other_last) { // in 'step' - 1, we chose option 'now', and the other one's last step is 'other_last'
            if(step >= n) {
                return 0;
            }
            if(dp[step][now][other_last+offset] != -1) {
                return dp[step][now][other_last+offset];
            }
            // the two options for current step
            int x = dfs(step+1, now, other_last) + abs(p[step] - p[step-1]), // this formula to ensure previous steps as well as afterwards steps
                y = dfs(step+1, now ^ 1, step-1) + ((other_last==-1)?0:abs(p[step] - p[other_last]));
            // cout << step << ' ' << now << ' ' << other_last << ' ' << x << ' ' << y << endl;
            return dp[step][now][other_last+offset] = min(x, y); 
        }
        int solve(vector <int> pitch) {
            p = pitch;
            n = p.size();
            offset = 10;
            memset(dp, -1, sizeof(dp));
            return dfs(1, 0, -1);
        }
};

int main() {
}
