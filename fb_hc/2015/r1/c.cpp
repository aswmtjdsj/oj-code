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

const int mod = 1000000007;
const int maxn = 2000;
int first[maxn+5][maxn+5];
int second[maxn+5][maxn+5];
int pre[maxn+5][maxn+5];

int main() {

    memset(first, 0, sizeof(first));
    memset(second, 0, sizeof(second));
    memset(pre, 0, sizeof(pre));
    /*for(int i = 0; i <= 2000; i++) {
        for(int j = 0; j <= 2000; j++) {
            if(i * j == 0) pre[i][j] = i + j;
            else {
                pre[i][j] = (pre[i-1][j] + pre[i][j-1]) % mod;
            }
        }
    }
    for(int i = 0; i <= 20; i++) {
        for(int j = 0; j <= 20; j++) {
            cout << pre[i][j] << ' ';
        }
        cout << '\n';
    }*/
    for(int i = 0; i <= 2000; i++) {
        for(int j = i; j <= 2000; j++) {
            if(i * j == 0) {
                second[i][j] = 1;
            } else {
                second[i][j] = 0;
                if(i - 1 <= j) second[i][j] = (second[i][j] + second[i-1][j]) % mod;
                if(i <= j - 1) second[i][j] = (second[i][j] + second[i][j-1]) % mod;
            }
        }
    }
    for(int i = 0; i <= 2000; i++) {
        for(int j = 0; j < i; j++) {
            if(i * j == 0) {
                first[i][j] = 1;
            } else {
                first[i][j] = 0;
                if(i - 1 > j) first[i][j] = (first[i][j] + first[i-1][j]) % mod;
                if(i > j - 1) first[i][j] = (first[i][j] + first[i][j-1]) % mod;
            }
        }
    }

    int t;
    cin >> t;
    for(int c = 1; c <= t; c++) {
        int a, b;
        scanf("%d-%d", &a, &b);
        // cout << a << ' ' << b << endl;
        cout << "Case #" << c << ": " << first[a][b] << ' ' << second[b][b] << endl;
    }
}
