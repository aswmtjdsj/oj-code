class FizzBuzzTurbo {
public:
	vector<lint> counts(lint A, lint B) {
		vector<lint> ans;
		lint a3, b3, a5, b5, a15, b15;
		a3 = (A-1) / 3;
		b3 = B / 3;
		ans.PB(b3 - a3);

		a5 = (A-1) / 5;
		b5 = B / 5;
		ans.PB(b5 - a5);

		a15 = (A-1) / 15;
		b15 = B / 15;
		ans.PB(b15 - a15);
		return ans;
	}
};
