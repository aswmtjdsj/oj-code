#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define maxn 60005

int dp[maxn];

int main() {
    fill(dp, dp + maxn, maxn);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = floor(sqrt(60000)); i >= 1; i--) {
        for(int j = 0; j <= 60000 - i * i; j++) {
            dp[j+i*i] = min(dp[j+i*i], dp[j] + 1);
        }
    }
    int n;
    while(cin >> n) {
        cout << dp[n] << endl;
    }
}
