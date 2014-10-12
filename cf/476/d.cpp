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

int gcd(int a, int b) {
	return (b==0)?a:gcd(b, a%b);
}

int main() {
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	vector< vector<int> > biu;
	biu.resize(n);
	vector <int> temp = vector <int> {1, 2, 3, 5};
	biu[0] = temp;
	int even_idx = 4, odd_idx = 7;
	for(int i = 1; i < n; i++) {
		temp[1] = odd_idx;
		temp[2] = odd_idx += 2;
		temp[3] = odd_idx += 2;
		odd_idx += 2;
		bool flag = true;
		for(int j = 1; j <= 3; j++) {
			if(gcd(even_idx, temp[j]) != 1) {
				flag = false;
				break;
			}
		}
		if(flag) {
			temp[0] = even_idx;
		}
		else {
			even_idx += 2;
			temp[0] = even_idx;
		}
		even_idx += 2;
		biu[i] = temp;
	}
	cout << biu[n-1][3] * k << endl;
	for(auto v: biu) {
		for(auto i: v) {
			cout << i * k << ' ';
		}
		cout << endl;
	}
}
