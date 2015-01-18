#include <iostream>
using namespace std;

int main() {
    long long dp[20][11];
    int n, k;
    for(int k = 2; k <= 10; k++) {
        dp[0][k] = 1; // for default
        dp[1][k] = k - 1;
        for(int n = 2; n <= 18 - k; n++) {
            dp[n][k] = (dp[n-1][k] + dp[n-2][k]) * (k - 1);
            // AB + A0C
            // B=dp[n-1][k]
            // C=dp[n-2][k]
            // A=[1...K-1]
        }
    }
    while(cin >> n >> k) {
        cout << dp[n][k] << endl;
    }
}