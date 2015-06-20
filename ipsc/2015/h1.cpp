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
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++) {
        int n, m;
        cin >> n >> m;
        vector < vector <bool> > matrix;
        matrix.resize(n);
        for(int i = 0; i < n; i++) {
            matrix[i].resize(n, false);
        }
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            matrix[a][b] = matrix[b][a] = true;
        }
        int big = 0, small = n * (n + 1);
        for(int i = 0; i < (1 << (n-2)); i++) {
            vector <int> a, b;
            a.PB(0);
            b.PB(1);
            for(int j = 0; j < n - 2; j++) {
                if(i & (1 << j)) {
                    a.PB(j+2);
                } else {
                    b.PB(j+2);
                }
            }
            int ta = 0;
            for(int j = 0; j < a.size(); j++) {
                for(int k = j + 1; k < a.size(); k++) {
                    if(matrix[a[j]][a[k]]) {
                        ta++;
                    }
                }
            }
            int tb = 0;
            for(int j = 0; j < b.size(); j++) {
                for(int k = j + 1; k < b.size(); k++) {
                    if(matrix[b[j]][b[k]]) {
                        tb++;
                    }
                }
            }
            /*cout << "----" << endl;
            for(auto ia: a) cout << ia << ' '; cout << endl;
            for(auto ib: b) cout << ib << ' '; cout << endl;
            cout << i << ' ' << ta << ' ' << tb << endl;*/
            big = max(big, ta + tb);
            small = min(small, abs(ta - tb));
        }
        cout << big << ' ' << small << endl;
    }
}
