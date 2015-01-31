#include <iostream>
using namespace std;

int dp[61];
int height(int n) {
    return dp[n];
}
int main() {
    int T;
    dp[0] = 1;
    for(int i = 1; i <= 60; i++) {
        if(i % 2 == 1) {
            dp[i] = dp[i-1] * 2;
        }
        else {
            dp[i] = dp[i-1] + 1;
        }
    }
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}
