#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int maxn = 1905;
int nh[maxn][maxn];
int dp[maxn][maxn];
int max_v[maxn];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, h, I;
    int opt;
    cin >> n >> h >> I;
    memset(max_v, 0, sizeof(max_v));
    for(int i = 0; i < n; i++) {
        fill(nh[i], nh[i] + h + 2, 0);
        int u;
        scanf(" %d", &u);
        for(int j = 0; j < u; j++) {
            scanf(" %d", &opt);
            nh[i][opt]++;
        }
    }
    /*for(int j = h; j >= 1; j--) {
        cout << j << ": ";
        for(int i = 0; i < n; i++) {
            cout << nh[i][j] << ' ';
        } cout << endl;
    }*/
    for(int j = h; j >= 1; j--) {
        int temp = 0;
        for(int i = 0; i < n; i++) {
            if(j > h - I) {
                dp[j][i] = dp[j+1][i] + nh[i][j];
            } else {
                dp[j][i] = max(max_v[j+I], dp[j+1][i]) + nh[i][j];
            }
            temp = max(temp, dp[j][i]);
        }
        max_v[j] = temp;
    }
    /*cout << endl;
    for(int j = h; j >= 1; j--) {
        cout << j << ": <" << max_v[j] << "> ";
        for(int i = 0; i < n; i++) {
            cout << dp[j][i] << ' ';
        } cout << endl;
    }*/
    cout << max_v[1] << endl;
    return 0;
}