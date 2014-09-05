class RunningAroundPark {
public:

	int numberOfLap(int N, vector <int> d) {
		int n = d.size();
		int ans = 0;
		for(int i = 0; i < n - 1; i++) {
			if(d[i+1] <= d[i]) {
				ans++;
			}
		}
		return ans;
	}
};
