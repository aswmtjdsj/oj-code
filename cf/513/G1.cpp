/* base IO */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iomanip>

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
    int n, K;
    cin >> n >> K;
    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map < vector <int>, int> M;
    M[a]=1;
    for(int _ = 0; _ < K; _++) {
        map < vector <int>, int> _M;
        for(auto &biu: M) {
            for(int i = 1; i <= n; i++) {
                for(int j = 0; j < n; j++) {
                    vector <int> a = biu.first;
                    if(i + j > n) break;
                    reverse(a.begin() + j, a.begin() + j + i);
                    _M[a] += biu.second;
                }
            }
        }
        M = _M;
    }
    /*cout << "#" << endl;
    for(auto i : M) {
        for(auto j: i.first) {
            cout << j << ' ';
        } cout << endl;
        cout << i.second << endl;
    }*/
    double ans = 0;
    long long tot = 0;
    for(auto i : M) {
        tot += i.second;
    }
    for(auto i : M) {
        long long temp = 0;
        for(int j = 0; j < i.first.size(); j++) {
            for(int k = j + 1; k < i.first.size(); k++) {
                if(i.first[j] > i.first[k]) temp++;
            }
        }
        ans += temp * 1.0 / tot * i.second;
    }
    //printf("%.10Lf\n", ans);
    // printf("%.10lf\n", ans);
    cout << fixed;
    cout << setprecision(10) << ans << endl;
}
