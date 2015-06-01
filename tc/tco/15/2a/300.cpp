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

int cnt[10000005];
class ModModMod {
	public:
        long long findSum(vector <int> m, int R) {
            long long ans = 0;
            vector <int> down;
            for(auto i: m) {
                if(down.size() == 0) {
                    down.PB(i);
                } else if(i < *down.rbegin()) {
                    down.PB(i);
                }
            }
            for(auto i: down) {
                cout << i << ' ';
            } cout << endl;
            fill(cnt + 1, cnt + R + 1, 1);
            for(int k = 0; k < down.size(); k++) {
                if(k == 0) {
                    for(int i = R; i > down[k]; i--) {
                        cnt[i % down[k]] += cnt[i];
                        cnt[i]--;
                    }
                } else {
                    // cout << down[k-1] - 1 << ' ' << down[k] << endl;
                    for(int i = down[k-1] - 1; i > down[k]; i--) {
                        // cout << i << endl;
                        cnt[i % down[k]] += cnt[i];
                        cnt[i] -= cnt[i];
                        // cout << cnt[i % down[k]] << ' ' << cnt[i] << endl;
                    }
                }
                /*for(int i = 1; i <= R; i++) {
                    cout << cnt[i] << ' ';
                } cout << endl;*/
            }
            for(int i = 0; i < *down.rbegin(); i++) {
                ans += (long long)cnt[i] * (long long)i;
            }
            return ans;
        }
};

int main() {
    ModModMod a;
    // cout << a.findSum({33, 15, 7, 10, 100, 9, 5}, 64) << endl;
    // cout << a.findSum({995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131}, 9992363) << endl;
}
