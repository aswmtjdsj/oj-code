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

class TaroFillingAStringDiv2 {
	public:
        int getNumber(string s) {
            int dp[55][2];
            int n = s.size();

            int max_num = 100;
            for(int i = 0; i < n; i++) {
                dp[i][0] = dp[i][1] = max_num;
            }

            for(int i = 0; i < n; i++) {
                if(i != 0) {
                    if(s[i] != '?') {
                        if(s[i] == 'A') {
                            dp[i][0] = min(dp[i-1][0] + 1, dp[i-1][1]);
                        } else {
                            dp[i][1] = min(dp[i-1][1] + 1, dp[i-1][0]);
                        }
                    } else {
                        dp[i][0] = min(dp[i-1][0] + 1, dp[i-1][1]);
                        dp[i][1] = min(dp[i-1][0], dp[i-1][1] + 1);
                    }
                } else {
                    if(s[i] == 'A') {
                        dp[i][0] = 0;
                    } else if(s[i] == 'B') {
                        dp[i][1] = 0;
                    } else {
                        dp[i][0] = 0;
                        dp[i][1] = 0;
                    }
                }
            }
            return min(dp[n-1][0], dp[n-1][1]);
        }
};

int main() {
    TaroFillingAStringDiv2 a;
    cout << a.getNumber("?BB?BAAB???BAB?B?AAAA?ABBA????A?AAB?BBA?A?") << endl;
}
