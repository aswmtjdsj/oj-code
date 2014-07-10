class ManySquares {
public:
	int howManySquares(vector <int> sticks) {
		map<int,int> M;
		int ans = 0;
		int n = sticks.size();
		for(int i = 0; i < n; i++) {
			M[sticks[i]]++;
		}
		for(auto idx = M.begin(); idx != M.end(); idx++) {
			ans += idx->second / 4;
		}
		return ans;
	}
};
