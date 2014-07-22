#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define maxn 100005
long long dp[maxn];
int c[maxn];
int n;

int dfs(int x) {
    if(dp[x] != -1) {
        return dp[x];
    }
    int l = -1, r = -1;
    if(x > 0) {
        if(c[x] > c[x-1]) {
            l = dfs(x-1) + 1;
        }
        /*else if(c[x] == c[x-1]) {
            l = -1;
        }
        else {
            l = -1;
        }*/
    }
    if(x < n - 1) {
        if(c[x] > c[x+1]) {
            r = dfs(x+1) + 1;
        }
        /*
        */
    }
    int a = max(l, r);
    if(a == -1) {
        dp[x] = 1;
    }
    else {
        dp[x] = a;
    }
    return dp[x];
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] == -1) {
            dp[i] = dfs(i);
        }
        ans += dp[i];
    }
    cout << ans << endl;
}
