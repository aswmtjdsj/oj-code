
class LCMSet {
public:
	int gcd(int a, int b) {
		return b?gcd(b, a%b):a;
	}
	int lcm(int a, int b) {
		return a / gcd(a,b) * b;
	}
#define EQ "Equal"
#define NEQ "Not equal"
	string equal(vector <int> A, vector <int> B) {
		set<int> SA, SB;
		// leave only coprime numbers and numbers that are not any others' multiples
		int sa = A.size(), sb = B.size();
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for(int i = 0; i < sa; i++) {
			int t = 1;
			for(int j = 0; j < i; j++) {
				if(A[i] % A[j] == 0) {
					t = lcm(t, A[j]);
				}
			}
			if(A[i] != t) {
				SA.insert(A[i]);
			}
		}
		for(int i = 0; i < sb; i++) {
			int t = 1;
			for(int j = 0; j < i; j++) {
				if(B[i] % B[j] == 0) {
					t = lcm(t, B[j]);
				}
			}
			if(B[i] != t) {
				SB.insert(B[i]);
			}
		}
		for(int i: SA) {
			cout << i <<' ';
		}
		cout << endl;
		for(int i: SB) {
			cout << i <<' ';
		}
		cout << endl;
		return SA==SB?EQ:NEQ;
	}
};
