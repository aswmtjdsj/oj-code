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

class Bitwisdom {
    public:
        double expectedActions(vector <int> p) {
            /*
               n = 2
               ans = z[0] * p[1] * 1
               + p[0] * z[1] * 1
               + z[0] * z[1] * 0
               + p[0] * p[1] * 1

               n = 3
               ans = z[0] * p[1] * z[2] * 2 + z[0] * p[1] * p[2] * 1
               + p[0] * z[1] * z[2] * 1 + p[0] * z[1] * p[2] * 2
               + p[0] * p[1] * z[2] * 1 + z[0] * z[1] * p[2] * 1
               + z[0] * z[1] * z[2] * 0 + p[0] * p[1] * p[2] * 1

               = z[0] * p[1] + p[0] * z[1]
               + z[0] * p[1] * z[2] + p[0] * z[1] * p[2]
               + p[0] * p[1] * z[2] + z[0] * z[1] * z[2]
               + p[0] * p[1] * p[2]

               = z[0] * p[1] + p[0] * z[1]
               + (z[0] + p[0]) * (p[1] * z[2] + z[1] * p[2])
               + p[0] * p[1] * p[2]

               = z[0] * p[1] + p[0] * z[1]
               + p[1] * z[2] + z[1] * p[2] <= increasing part
               + p[0] * p[1] * p[2] <= single part
             */
            const int maxn = 305;
            double one[maxn], zero[maxn];
            int n = p.size();
            for(int i = 0; i < n; i++) {
                one[i] = p[i] * 1. / 100.;
                zero[i] = 1. - one[i];
            }
            double ans = 0., ones = 1.;
            for(int i = 0; i < n - 1; i++) {
                ans += one[i] * zero[i+1];
                ans += zero[i] * one[i+1];
            }
            for(int i = 0; i < n; i++) {
                ones *= one[i];
            }
            return ans + ones;
        }
};

int main() {
    Bitwisdom a;
    cout << a.expectedActions({50, 50}) << endl;
    cout << a.expectedActions({0, 40, 50, 60}) << endl;
    cout << a.expectedActions({37, 63, 23, 94, 12}) << endl;
}
