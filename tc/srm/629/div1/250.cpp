class RectangleCovering{
public:
	int size;
	vector<pair<int,int> > rec;
	int minimumNumber(int hh, int hw, vector <int> bh, vector <int> bw) {
		if(hh < hw) swap(hh, hw);
		int n = bh.size();
		int ans = -1;
		for(int i = 0; i < n; i++) {
			if(bh[i] < bw[i]) {
				swap(bh[i], bw[i]);
			}
		}
		vector <PII> forw;
		for(int i = 0; i < n; i++) {
			if(bw[i] > hw) {
				forw.PB(MP(bh[i], bw[i]));
			}
			else if(bh[i] > hw) {
				forw.PB(MP(bw[i], bh[i]));
			}
		}
		sort(forw.begin(), forw.end());
		int left = hh;
		int cnt = 0;
		for(int i = forw.size() - 1; i >= 0; i--) {
			left -= forw[i].first;
			cnt++;
			if(left <= 0) {
				if(ans == -1) {
					ans = cnt;
				}
			}
		}
		vector <PII> forh;
		for(int i = 0; i < n; i++) {
			if(bw[i] > hh) {
				forh.PB(MP(bh[i], bw[i]));
			}
			else if(bh[i] > hh) {
				forh.PB(MP(bw[i], bh[i]));
			}
		}
		sort(forh.begin(), forh.end());
		left = hw;
		cnt = 0;
		for(int i = forh.size() - 1; i >= 0; i--) {
			left -= forh[i].first;
			cnt++;
			if(left <= 0) {
				if(ans == -1 || ans > cnt) {
					ans = cnt;
				}
			}
		}
		return ans;
	}
};
