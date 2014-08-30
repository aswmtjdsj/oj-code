class TaroCoins {
public:
	long long dp[100][2][3];
	long long index[100];
	long long dfs(int pos, int cur, int res) {
		if(pos < 0) 
			return 0;
		if(cur != index[pos]) { // not in the number
			return dp[pos][cur][res] = 0;
		}
		if(dp[pos][cur][res] != -1) { // visited
			return dp[pos][cur][res];
		}
		if((cur == 0 && res == 0) || (cur == 0 && res == 2) || (cur == 1 && res == 1)) {
			return dp[pos][cur][res] = dfs(pos-1, 0, 2) + dfs(pos-1, 1, 1) + dfs(pos-1, 1, 2);
		}
		else {
			return dp[pos][cur][res] = dfs(pos-1, 0, 0) + dfs(pos-1, 0, 1) + dfs(pos-1, 1, 0);
		}
	}
	long long getNumber(long long n) {
		memset(dp, -1, sizeof(dp));
		memset(index, 0, sizeof(index));
		int cnt = 0;
		while(n > 0) {
			index[cnt++] = n % 2ll;
			n /= 2;
		}

		/*for(int i = cnt - 1; i >= 0; i--)
			cerr << index[i];
		cerr << endl;*/

		long long ans = 0;
		dp[0][0][0] = dp[0][0][2] = dp[0][1][1] = 1;
		dp[0][0][1] = dp[0][1][0] = dp[0][1][2] = 0;

		if(index[cnt-1] == 1) {
			ans += dfs(cnt-1, index[cnt-1], 1) + dfs(cnt-1, index[cnt-1], 2);
		}
		else {
			ans += dfs(cnt-1, index[cnt-1], 2);
		}

		/*for(int i = cnt - 1; i >= 0; i--) {
			for(int j = 0; j < 2; j++) {
				for(int k = 0; k < 3; k++) {
					cout << "dp[" << i << "][" << j << "][" << k << "]: " << dp[i][j][k] << endl;
				}
			}
		}*/

		return ans;
	}
};
