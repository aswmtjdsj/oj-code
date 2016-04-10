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

set <int> decomp(int x) {
    set <int> res;
    while(x > 0) {
        res.insert(x % 10);
        x /= 10;
    }
    return res;
}

void comb(set <int> & o, set <int> n) {
    for (auto x : n) {
        o.insert(x);
    }
}
int calc(int x) {
    set <int> res;
    int c = 0;
    while(res.size() < 10) {
        c += x;
        /*cout << c << endl;
        for(auto b : res) {
            cout << b;
        } cout << endl;*/
        comb(res, decomp(c));
    }
    return c;
}

int main() {
    /*for(int i = 1; i <= 1000000; i++) {
        int a = calc(i);
        if (i % 10000 == 0) {
            cout << i << ' ' << a << endl;
        }
    }*/
    int T;
    cin >> T;
    for(int _ = 1; _ <= T; _++) {
        int x;
        cin >> x;
        int ans = - 1;
        if (x != 0) {
            ans = calc(x);
        }
        if (ans != -1) {
            printf("Case #%d: %d\n", _, ans);
        } else {
            printf("Case #%d: INSOMNIA\n", _);
        }
    }
}
