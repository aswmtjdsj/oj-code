class PotentialGeometricSequence {
public:
	int numberOfSubsequences(vector <int> d) {
		int n = d.size();
		int ans = 0;
		ans += n;
		ans += n - 1;
		for(int i = 3; i<= n; i++) {
			for(int j = 0;j < n; j++) {
				if(j + i > n) break;
				bool flag = true;
				for(int k = j; k < j + i; k++) {
					if(k + 2 >= j + i) {
						break;
					}
					if(d[k+1] * 2 == d[k] + d[k+2]) {
					}
					else {
						flag = false;
						break;
					}
				}
				if(flag) {
					ans++;
				}
			}
		}
		return ans;
	}
};
