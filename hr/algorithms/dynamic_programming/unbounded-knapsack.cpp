#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    bool dp[2005];
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++) {
        int n, k;
        cin >> n >> k;
        memset(dp, false, sizeof(dp));
        
        int a[2005];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        dp[0] = true;
        for(int i = 0; i < k; i++) {
            if(!dp[i]) continue;
            for(int j = 0; j < n; j++) {
                if(i + a[j] <= k) {
                    dp[i+a[j]] = true;
                } else break;
            }
        }
        int ans;
        for(int i = k; i >= 0; i--) {
            if(dp[i]) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
