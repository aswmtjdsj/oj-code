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

class FoxesOfTheRoundTable {
    public:
        vector <int> minimalDifference(vector <int> h) {
            vector <pair<int, int>> h2;
            for(int i = 0; i < h.size(); i++) {
                h2.PB(MP(h[i], i));
            }
            sort(h2.begin(), h2.end());
            bool order = false;
            deque <pair<int, int>> round;
            for(int i = h2.size() - 1; i >= 0; i--) {
                auto x = h2[i];
                if(!order) {
                    round.push_front(x);
                } else {
                    round.push_back(x);
                }
                order = !order;
            }
            vector <int> ans;
            while(!round.empty()) {
                auto x = round.front();
                round.pop_front();
                ans.push_back(x.second);
            }
            return ans;
        }
};

int main() {
    FoxesOfTheRoundTable a;
    auto x = a.minimalDifference({1,2,3,4,8,12,13,14 });
    for(auto i: x) {
        cout << i << ' ';
    } cout << endl;
}
