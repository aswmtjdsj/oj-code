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
#include <deque>
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

class ABBADiv1 {
    public:
        string canObtain(string init, string tar) {
            string rev = init;
            reverse(rev.begin(), rev.end());
            bool flag = false;
            int n = tar.size(), m = init.size();
            for(int i = 0; i < n - m + 1; i++) {
                int preb = 0, sufb = 0;
                int prea = 0, sufa = 0;
                for(int j = 0; j < i; j++) {
                    if(tar[j] == 'B') preb++;
                    if(tar[j] == 'A') prea++;
                }
                for(int j = i + m; j < n; j++) {
                    if(tar[j] == 'B') sufb++;
                    if(tar[j] == 'A') sufa++;
                }
                if(tar[0] == 'A' && prea != 0) {
                    continue;
                }
                // cout << preb << ' ' << sufb << ' ' << init << ' ' << rev << ' ' << tar.substr(i,m) << endl;
                if(init == tar.substr(i, m)) {
                    if(preb == sufb) {
                        flag = true;
                        break;
                    }
                }
                if(rev == tar.substr(i, m)) {
                    if(preb == sufb + 1) {
                        flag = true;
                        break;
                    }
                }
            }

            return flag?"Possible":"Impossible";
        }
};

int main() {
    ABBADiv1 a;
    cout << a.canObtain("A", "BABA") << endl;
    cout << a.canObtain("A", "ABBA") << endl;
    cout << a.canObtain("BAAAAABAA", "BAABAAAAAB") << endl;
    cout << a.canObtain("AAABBAABB", "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB") << endl;
    cout << a.canObtain("AAABAAABB", "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB") << endl;
    cout << a.canObtain("ABB", "BAABBB") << endl;
    cout << a.canObtain("ABB", "BAABBAB") << endl;
    cout << a.canObtain("ABB", "AABBA") << endl;
    cout << a.canObtain("A", "BBAAABBBBAABABABBAAABABAABAAAABABBAABBBAAABB") << endl;
}
