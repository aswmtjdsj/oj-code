class Unique {
public:
	string removeDuplicates(string S) {
		map <char, int> M;
		string ans = "";
		for(int i = 0; i < S.size(); i++) {
			if(!M[S[i]]) {
				M[S[i]] = 1;
				ans += to_string(S[i]);
			}
		}
		return ans;
	}
};
