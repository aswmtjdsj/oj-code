
class HappyLetterDiv2 {
public:
	char getHappyLetter(string letters) {
		map <char,int> M;
		int l = letters.size();
		for(int i = 0; i < l; i++) {
			M[letters[i]]++;
		}
		for(auto idx = M.begin(); idx != M.end(); idx++) {
			if(idx->second > l / 2) {
				return idx->first;
			}
		}
		return '.';
	}
};
