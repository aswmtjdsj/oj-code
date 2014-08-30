class CatsOnTheLineDiv2 {
public:
	string getAnswer(vector <int> position, vector <int> count, int time) {
		map<int, int> pos_cat;
		int n = count.size();
		for(int i = 0; i < n; i++) {
			pos_cat[position[i]] = count[i];
		}
		bool flag = true;
		int cur = -10000;
		for(auto idx = pos_cat.begin(); idx != pos_cat.end(); idx++) {
			//cout << idx->first << ' ' << idx->second << endl;
			//cout << cur << endl;
			//cout << idx->first << endl;
			if(cur < -2000) {
				cur = idx->first - time;
			}
			if(idx->first - time > cur) {
				cur = idx->first - time;
			}
			cur += idx->second - 1;
			if(cur > idx->first + time) {
				flag = false;
				break;
			}
			else {
				cur += 1;
			}
		}

		return flag?"Possible":"Impossible";
	}
};
