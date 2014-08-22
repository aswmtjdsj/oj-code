class DoubleLetter {
public:
	string ableToSolve(string S) {
		vector<char> v;
		int l = S.length();
		for(int i = 0; i < l; i++) {
			v.PB(S[i]);
		}
		while(1) {
			int flag = -1;
			int size = v.size();
			for(int i = 0; i < size - 1; i++) {
				if(v[i] == v[i+1]) {
					flag = i;
					break;
				}
			}
			if(flag == -1) {
				break;
			}
			vector<char> vv;
			for(int i = 0; i < size; i++) {
				if(i != flag && i != flag + 1) {
					vv.PB(v[i]);
				}
			}
			v = vv;
			for(int i = 0; i < v.size(); i++) {
				cout << v[i];
			}
			cout << endl;
		}
		return (v.size() == 0)?"Possible":"Impossible";
	}
};
