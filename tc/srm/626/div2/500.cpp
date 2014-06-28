class FixedDiceGameDiv2 {
public:
	double getExpectation(int a, int b) {
		double ans = 0.0;
		vector<PII> biu;
		for(int i = 1; i <= a; i++) {
			for(int j = 1; j <= min(a,b); j++) {
				if(i > j) {
					biu.PB(MP(i,j));
				}
			}
		}
		int cnt = biu.size();
		for(int i = 0; i < biu.size(); i++) {
			ans += biu[i].first * 1.0 / cnt;
		}
		return ans;
	}
};
