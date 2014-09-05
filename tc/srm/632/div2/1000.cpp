class GoodSubset {
public:
	int numberOfSubsets(int goodValue, vector <int> d) {
		const long long mod = 1000000007;
		map<long long, long long> biu;
		int n = d.size();
		long long gv = goodValue;
		biu[1] = 1;
		for(int i = 0; i < n; i++) {
			for(auto idx = biu.rbegin(); idx != biu.rend(); idx++) {
			// use reverse begin to avoid duplicate calculate the occurrence
				auto t = idx->first;
				t *= d[i];
				if(gv % t == 0) {
					biu[t] = (biu[t] + idx->second) % mod;
				}
			}
		}
		biu[1] = (biu[1] - 1 + mod) % mod;
		return biu[gv];
	}
};
