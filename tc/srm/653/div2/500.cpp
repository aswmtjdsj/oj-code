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

class RockPaperScissorsMagicEasy {
    public:
        long long mod = 1000000007ll;
        long long mod_power(long long a, int n) {
            long long ans = 1;
            while(n > 0) {
                if(n & 1) {
                    ans = (ans * a) % mod;
                }
                a = (a * a) % mod;
                n >>= 1;
            }
            return ans;
        }
        long long count(vector <int> card, int score) {
            //  c(n,m)=c(n-1,m-1)+c(n-1,m)
            long long c[2005][2005];
            for(int i = 1; i <= 2000; i++) {
                for(int j = 0; j <= i; j++) {
                    if(j == 0) {
                        c[i][j] = 1;
                    } else if(j > i/2) {
                        c[i][j] = c[i][i-j];
                    } else {
                        c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
                    }
                }
            }
            int n = card.size();
            long long part1;
            if(score > n) return 0;
            else part1 = c[n][score];
            long long part2 = mod_power(2, n - score);
            cout << part1 << ' ' << part2 << endl;
            return (part1 * part2) % mod;
        }
};