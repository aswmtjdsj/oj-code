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

int main() {
    string a;
    const string p = "CODEFORCES";

    cin >> a;

    int n = a.size();
    int l = p.size();

    if(n < l) {
        puts("NO");
    } else if(a.substr(0, l) == p) {
        puts("YES");
    } else if(a.substr(n - l, l) == p) {
        puts("YES");
    } else {
        bool mark = true;
        for(int i = 0; i < l; i++) {
            if(a[i] != p[i]) {
                mark = false;
                int q = l - 1;
                for(int j = n - 1; j > i && q >= i; j--, q--) {
                    if(a[j] != p[q]) {
                        break;
                    }
                }
                if(q == i - 1) {
                    mark = true;
                }
                break;
            }
        }
        if(mark) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}
