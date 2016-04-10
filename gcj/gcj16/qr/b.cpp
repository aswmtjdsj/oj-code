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
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int ans = 0;
        string str;
        cin >> str;
        // cout << str << endl;
        while (1) {
            int i = 0;
            int found_neg = -1;
            int found_pos = -1;
            for (; i < str.size(); i++) {
                if (str[i] == '-') {
                    found_neg = i;
                }
                if (str[i] == '+') {
                    if (found_neg != -1) {
                        break;
                    } else {
                        found_pos = i;
                    }
                }
            }
            if (found_neg == -1) {
                break;
            } else {
                if (found_pos != -1 && found_pos < found_neg) {
                    for (int j = 0; j <= i; j++) {
                        str[j] = '+';
                    }
                    ans += 2;
                } else {
                    for (int j = 0; j <= i; j++) {
                        str[j] = '+';
                    }
                    ans += 1;
                }
            }
            // cout << str << endl;
        }
        printf("Case #%d: %d\n", _, ans);
    }
}
