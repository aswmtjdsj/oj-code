#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 3 * 100000;
long long a[maxn];

int main() {
	int n;
	scanf(" %d", &n);
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++) {
		sum += (i + 1) * a[i];
		if(i == n - 1) {
			sum -= a[i];
		}
	}
	cout << sum << endl;
}
