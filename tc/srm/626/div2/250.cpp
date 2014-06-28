class SumOfPower {
public:
	int findSum(vector <int> array) {
		int n = array.size();
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < (n - i + 1); j++) {
				int temp = 0;
				for(int k = j; k < j + i; k++) {
					if(k >= n) break;
					temp += array[k];
				}
				ans += temp;
				cout << i << ' ' << j << ' ' << temp << endl;
			}
		}
		return ans;
	}
};
