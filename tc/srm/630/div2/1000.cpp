
class SuffixArrayDiv2 {
public:
	bool visit[100];
	bool small(string a, string b) {
		if(!(b < a)) {
			return false;
		}
		typedef pair<string, int> sa;
		int l = a.size();
		vector <sa> origin;
		for(int i = l - 1; i >= 0; i--) {
			origin.PB(MP(a.substr(i), i));
		}
		sort(origin.begin(), origin.end());

		int s = b.size();
		vector <sa> comp;
		for(int i = s - 1; i >= 0; i--) {
			comp.PB(MP(b.substr(i), i));
		}
		sort(comp.begin(), comp.end());

		/*for(int i = 0; i < origin.size(); i++) {
			cout << origin[i].first << ' ' << origin[i].second << endl;
		}
		for(int i = 0; i < comp.size(); i++) {
			cout << comp[i].first << ' ' << comp[i].second << endl;
		}*/

		bool flag = true;
		for(int i = 0; i < comp.size(); i++) {
			if(comp[i].second != origin[i].second) {
				flag = false;
			}
		}
		return flag;
	}
	string s;
	string smallerOne(string _s) {
		s = _s;
		int n = s.size();
		for(int i = 0; i < n; i++) {
			string t = s;
			t[i]--;
			if(t[i] < 'a') continue;
			if(small(s, t)) {
				return "Exists";
			}
		}
		return "Does not exist";
	}
};
