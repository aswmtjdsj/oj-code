/*class FibonacciDiv2 {
public:
	int find(int N) {
		const int fib_size = 40;
		int fib[fib_size];
		fib[0] = fib[1] = 1;
		for(int i = 2; i < fib_size; i++) {
			fib[i] = fib[i-1] + fib[i-2];
			cout << i << ' ' << fib[i] << endl;
		}
		int ans = 1000000;
		for(int i = 0; i < fib_size; i++) {
			if(abs(N-fib[i]) < ans) {
				ans = abs(N-fib[i]);
			}
		}
		return ans;
	}
};*/
