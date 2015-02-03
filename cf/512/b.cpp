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

const int maxn = 305;

int gcd(int a, int b) {
    return (b == 0)? a: gcd(b, a % b);
}

int main() {
    int n;
    while(cin >> n) {
        int l[maxn];
        int c[maxn];
        for(int i = 0; i < n; i++) {
            cin >> l[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }
        map <int, int> M;
        for(int i = 0; i < n; i++) {
            if(M.find(l[i]) == M.end()) {
                M[l[i]] = c[i];
            } else if(M[l[i]] > c[i]) {
                M[l[i]] = c[i];
            }
        }
        for(int i = 0; i < n; i++) {
            if(M.find(1) != M.end() && M[1] <= c[i]) continue;
            for(auto idx: M) {
                int miao = gcd(idx.first, l[i]); // with two numbers a and b, by addition and subtraction, they can get any multiples of their gcd
                // in this way, there are redundant calculations
                // suppose currently l_i, while there are already some numbers l_j (j < i), gcd of l_j and l_i can be pre-eliminated
                // the supposed complexity is O(2 ^ 9 * n ^ 2)
                // for there are at most 9 prime factors in the range of 10^9, using bit-set enumeration
                // but how n^2? didn't figure out
                if(M.find(miao) == M.end() || M[miao] > c[i] + M[idx.first]) {
                    M[miao] = c[i] + M[idx.first];
                }
            }
        }
        if(M.find(1) == M.end()) {
            cout << -1 << endl;
        } else {
            cout << M[1] << endl;
        }
    }
}
