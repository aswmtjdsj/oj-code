#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>

#include <string>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <list>
#include <vector>

#include <algorithm>
#include <complex>
using namespace std;

#define len(x) (x).size()
#define VI vector<int> 

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

template <class T>
inline T sqr(T x) { return x * x; }

const int inf = ~0u >> 1;
const double eps = 1e-8;
const double pi = acos(-1.0);

int sgn(double x) {
		return fabs(x) < eps ? 0:x < -eps?-1:1;
}

const int64 mod = 1000000007ll;

int64 mod_pow(int64 x, int64 n, int64 mod) {
	int64 ans = 1;
	while(n) {
		if(n & 1) {
			ans = (ans * x) % mod;
		}
		x = (x * x) % mod;
		n >>= 1;
	}
	return ans;
}

int64 mod_inverse(int64 a, int64 p) {
	return mod_pow(a, p-2, p);
}

int main() {
	int64 a, b;
	cin >> a >> b;
	int64 ans = 0;
	ans = 0;
	for(int64 i = 1; i <= a; i++) {
		/*for(int64 j = 1; j < b; j++) {
			ans = (ans + i * b + j) % mod;
		}*/
		
		int64 temp = ((1 + b - 1) * (b-1) / 2) % mod;
		int64 ta = (temp * i) % mod;
		ta = (ta * b) % mod;
		int64 tb = (temp * 1) % mod;
		ans = (ans + ta + tb) % mod;
	}
	cout << ans << endl;
}
