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
    int w, h, n;
    cin >> w >> h >> n;
    set <int> vcut, hcut;
    multiset <int, greater <int>> vseg, hseg;
    map <PII, multiset <int, greater <int> > :: iterator> vmap, hmap;
    vcut.insert(0);
    vcut.insert(h);
    hcut.insert(0);
    hcut.insert(w);
    auto itv = vseg.insert(h);
    vmap[MP(0, h)] = itv;
    auto ith = hseg.insert(w);
    hmap[MP(0, w)] = ith;
    for(int i = 0; i < n; i++) {
        char opt;
        int pos;
        scanf(" %c %d", &opt, &pos);
        if(opt == 'V') {
            auto target = hcut.insert(pos);
            auto before = next(target.first, -1);
            auto after = next(target.first, 1);
            auto to_remove = hmap[MP(*before, *after)];
            // cout << (*to_remove) << endl;
            hseg.erase(to_remove);
            hmap.erase(MP(*before, *after));
            auto one = hseg.insert(pos - (*before));
            hmap[MP(*before, pos)] = one;
            auto two = hseg.insert((*after) - pos);
            hmap[MP(pos, *after)] = two;
        } else {
            auto target = vcut.insert(pos);
            auto before = next(target.first, -1);
            auto after = next(target.first, 1);
            auto to_remove = vmap[MP(*before, *after)];
            // cout << (*to_remove) << endl;
            vseg.erase(to_remove);
            vmap.erase(MP(*before, *after));
            auto one = vseg.insert(pos - (*before));
            vmap[MP(*before, pos)] = one;
            auto two = vseg.insert((*after) - pos);
            vmap[MP(pos, *after)] = two;
        }
        long long ans = *vseg.begin();
        ans = ans * (*hseg.begin());
        // cout << (*vseg.begin()) << ' ' << (*hseg.begin()) << endl;
        printf("%lld\n", ans);
    }
}
