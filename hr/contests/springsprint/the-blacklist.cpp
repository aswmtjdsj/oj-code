#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxk = 12;
const int maxn = 22;

int dp[1 << maxk][maxk][maxn];
int input[maxk][maxn];
int acc[maxk][maxn];
int n, k;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
            if(j == 0) {
                acc[i][j] = input[i][j];
            } else {
                acc[i][j] = acc[i][j-1] + input[i][j];
            }
        }
    }
    /*for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            cout << acc[i][j] << ' ';
        } cout << endl;
    }*/

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < k; i++) {
        dp[0][i][0] = 0;
    }

    for(int i = 0; i < k; i++) {
        for(int j = 0;j < n; j++) {
            dp[1 << i][i][j+1] = acc[i][j];
        }
    }

    int ans = 200000;
    for(int m = 0; m < (1 << k); m++) {
        for(int i = 0; i < k; i++) {
            if(m & (1 << i)) {
                for(int j = 1; j < n; j++) {
                    if(dp[m][i][j] != -1) {
                        for(int p = 0; p < k; p++) {
                            if(p != i && (m & (1 << p)) == 0) {
                                for(int q = j+1; q <= n; q++) {
                                    if(dp[m | (1 << p)][p][q] == -1 || 
                                            dp[m | (1 << p)][p][q] > dp[m][i][j] + acc[p][q-1] - acc[p][j-1]) {
                                        dp[m | (1 << p)][p][q] = dp[m][i][j] + acc[p][q-1] - acc[p][j-1];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    /*for(int m = 0; m < (1 << k); m++) {
        for(int i = 0; i < k; i++) {
            for(int j = 0; j <= n; j++) {
                printf("[%d, %d, %d]: %d\n", m, i, j, dp[m][i][j]);
            }
        }
    }*/
    for(int m = 0; m < (1 << k); m++) {
        for(int i = 0; i < k; i++) {
            if(dp[m][i][n] != -1) {
                ans = min(ans, dp[m][i][n]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

