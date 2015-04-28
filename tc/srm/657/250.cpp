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

class ProblemSets {
	public:
        long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
            long long low = min(E, min(M, H)), high = max(E + EM, max(M + EM + MH, H + MH));
            while(low < high) {
                long long mid = (low + high) / 2;
                long long e = mid - min(E, mid), m = mid - min(M, mid), h = mid - min(H, mid);
                long long em = EM - e, mh = MH - h;
                if(em < 0 || mh < 0 || em + mh < m) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            long long mid = (low + high) / 2;
            long long e = mid - min(E, mid), m = mid - min(M, mid), h = mid - min(H, mid);
            long long em = EM - e, mh = MH - h;
            if(em < 0 || mh < 0 || em + mh < m) {
                mid--;
            }
            return mid;
        }
};

int main() {
    ProblemSets a;
    cout << a.maxSets(100, 100, 100, 0, 0) << endl;
}
