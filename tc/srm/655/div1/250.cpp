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

int n,m,k;
const int M = 20 * 20 + 5;
int a[M][M], b[M];
bool l[M];

long long gauss() {
    int res = 0, r = 0;
    memset(l,0,sizeof(bool) * n);
    for(int i = 0; i < n; ++i){
        for(int j = r; j < n; ++j){
            if(a[j][i] == 1){
                for(int k = i; k <= n; ++k)
                    swap(a[j][k],a[r][k]);
                break;
            }
        }
        if(a[r][i] == 0){
            if(a[r][n] != 0) return -1;//no solution
            else{// free varbiable
                ++res;continue;
            }
        }
        for(int j = 0; j < n; ++j){
            if(j != r && a[j][i] == 1){;
                for(int k = i; k <= n; ++k)
                    a[j][k] ^= a[r][k];
            }
        }
        l[i] = true,++r;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        } cout << "| " << a[i][m] << endl;
    }
    return res;
    /*int i,j,row=1,col;
    for (col=1;col<=m;++col) {   
        for (i=row;i<=n;++i) {
            if (a[i][col])
                break ;
        }
        if (i>n)
            continue ;
        if (i!=row) {    
            for (j=col;j<=m;++j) {
                swap(a[row][j],a[i][j]);
            }
            swap(b[i],b[row]);
        }
        for (i=row+1;i<=n;++i) {
            if (a[i][col]) {    
                for (j=col;j<=m;++j) {
                    a[i][j]^=a[row][j];
                }

                b[i]^=b[row];
            }
        }
        ++row;
    }
    for (i=row;i<=n;++i)
        if (b[i])
            return -1;
    return 1ll<<(long long)(m-row+1);*/
}

class BichromePainting {
    public:
        string isThatPossible(vector <string> board, int k) {
            /*for(auto i: board) {
              cout << i << endl;
              }*/
            int _n = board.size();
            n = _n * _n;
            m = _n * _n;
            // cout << n << ' ' << m << endl;
            for(int i = 0; i < _n; i++) {
                for(int j = 0; j < _n; j++) {
                    if(board[i][j] == 'B') {
                        a[i * _n + j][m] = 1;
                    } else {
                        a[i * _n + j][m] = 0;
                    }
                    for(int p = 0; p < _n; p++) {
                        for(int q = 0; q < _n; q++) {
                            if(abs(p - i) < k && abs(q - j) < k) {
                                a[i * _n + j][p * _n + q] = 1;
                            } else {
                                a[i * _n + j][p * _n + q] = 0;
                            }
                        }
                    }
                }
            }
            /*for(int i = 1; i <= n; i++) {
              for(int j = 1; j <= m; j++) {
              cout << a[i][j] << ' ';
              } cout << "| " << b[i] << endl;
              }*/
            auto ans = gauss();
            cout << ans << endl;
            if(ans != -1) {
                return "Possible";
            } else {
                return "Impossible";
            }
        }
};

int main() {
    BichromePainting a;
    /*cout << a.isThatPossible({"BWBWBB",
            "WBWBWB",
            "BWBWBB",
            "WBWBWB",
            "BWBWBB",
            "BBBBBB"}, 2) << endl;*/
    cout << a.isThatPossible({"BWBWBB",
            "WBWBBB",
            "BWBWBB",
            "WBWBBB",
            "BBBBBB",
            "BBBBBB"}, 2) << endl;
}
