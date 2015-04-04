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
    int n;
    cin >> n;
    string a;
    cin >> a;
    for(int i = 0; i < n; i++) {
        if(a[i] == '*') {
            for(int j = i + 1; j < n; j++) {
                if(a[j] == '*') {
                    int step = j - i;
                    int cnt = 2;
                    for(int k = j + step; k < n; k += step) {
                        if(a[k] == '*') {
                            cnt++;
                        } else {
                            break;
                        }
                        if(cnt == 5) {
                            // cout << i << ' ' << j << ' ' << k << endl;
                            cout << "yes" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "no" << endl;
    return 0;
}
