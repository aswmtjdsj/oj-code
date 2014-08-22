/* class SwitchingGame {
public:
	int timeToWin(vector <string> states) {
		int n = len(states);
		int m = len(states[0]);
		int ans = 0;
		string cur;
		for(int i = 0; i < m; i++) {
			cur += "-";
		}
		for(int i = 0; i < n; i++) {
			// - > +
			int temp1 = 0;
			for(int j = 0; j < m; j++) {
				if(states[i][j] == '+' && cur[j] == '-') {
					cur[j] = '+';
					temp1++;
				}
			}
			if(temp1 > 0) {
				ans++;
			}
			int temp2 = 0;
			// + > -
			for(int j = 0; j < m; j++) {
				if(states[i][j] == '-' && cur[j] == '+') {
					cur[j] = '-';
					temp2++;
				}
			}
			if(temp2 > 0) {
				ans++;
			}

			for(int j = 0; j < m; j++) {
				if(states[i][j] == '?') {
					for(int k = i + 1; k < n; k++) {
						if(states[k][j] == '+') {
							if(cur[j] == '-' && temp1 > 0) {
								cur[j] = '+';
							}
							break;
						}
						else if(states[k][j] == '-') {
							if(cur[j] == '+' && temp2 > 0) {
								cur[j] = '-';
							}
							break;
						}
					}
				}
			}

			//button pressed
			ans++;
			cout << states[i] << '\t';
			cout << cur << endl;
		}
		return ans;
	}
};*/
