#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ans;
int biu[12][22];
int n, k;
bool can[12];

void dfs(int temp, int idx, int num) {
    if(temp >= ans) {
        return ;
    }
    if(idx == n) {
        ans = min(ans, temp);
    } else {
        for(int i = 0; i < k; i++) {
            if(can[i] == true) {
                can[i] = false;
                int bie = 0;
                if(num == 1) {
                    for(int j = idx; j < n; j++) {
                        bie += biu[i][j];
                    }
                    dfs(temp + bie, n, 0);
                } else {
                    for(int j = idx; j < n; j++) {
                        bie += biu[i][j];
                        dfs(temp + bie, j+1, num-1);
                    }
                }
                can[i] = true;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            cin >> biu[i][j];
        }
    }
    ans = 200000;
    for(int i = 0; i < (1 << k); i++) {
        int t = 0;
        for(int j = 0; j < k; j++) {
            if(i & (1 << j)) {
                t++;
                can[j] = true;
            } else {
                can[j] = false;
            }
        }
        dfs(0, 0, t);
        // cout << i << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
