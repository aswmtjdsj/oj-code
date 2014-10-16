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
typedef pair<int64, int64> pll;
typedef pair<double, double> pdd;

template <class T>
inline T sqr(T x) { return x * x; }

const int inf = ~0u >> 1;
const double eps = 1e-8;
const double pi = acos(-1.0);

int sgn(double x) {
		return fabs(x) < eps ? 0:x < -eps?-1:1;
}

void rotate(int64 &x, int64 &y, int p) {
	// vx, vy
	// ccw 90 -vy, vx
	// ccw 180 -vx, -vy
	// ccw 270 vy -vx
	if(p == 1) {
		swap(x, y);
		x = -x;
	} else if(p == 2) {
		x = -x;
		y = -y;
	} else if(p == 3) {
		swap(x, y);
		y = -y;
	}
}

bool comp(pll a, pll b) {
	return a.first < b.first || (a.first == b.first && a.second > b.second);
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int64 x[4], y[4], a[4], b[4], vx[4], vy[4], vxr[4], vyr[4], ex[4], ey[4];
		vector < pll > nodes(4);
		for(int j = 0; j < 4; j++) {
			cin >> x[j] >> y[j] >> a[j] >> b[j];
			vx[j] = x[j] - a[j];
			vy[j] = y[j] - b[j];
		}
		int ans = -1;

		for(int p = 0; p < 4; p++) {
			for(int q = 0; q < 4; q++) {
				for(int r = 0; r < 4; r++) {
					for(int s = 0; s < 4; s++) {
						for(int k = 0; k < 4; k++) {
							vxr[k] = vx[k];
							vyr[k] = vy[k];
						}
						rotate(vxr[0], vyr[0], p);
						rotate(vxr[1], vyr[1], q);
						rotate(vxr[2], vyr[2], r);
						rotate(vxr[3], vyr[3], s);
						bool flag = true;
						for(int k = 0; k < 4; k++) {
							nodes[k] = MP(a[k] + vxr[k], b[k] + vyr[k]);
						}
						for(int k = 0; k < 4 && flag; k++) {
							for(int nk = k + 1; nk < 4 && flag; nk++) {
								if(nodes[k] == nodes[k+1]) {
									flag = false;
								}
							}
						}
						if(flag) {
							sort(nodes.begin(), nodes.end(), comp);
							swap(nodes[3], nodes[2]);
						}
						for(int k = 0; k < 4 && flag; k++) {
							int nk = (k + 1)%4;
							ex[k] = nodes[nk].first - nodes[k].first, ey[k] = nodes[nk].second - nodes[k].second;
						}
						for(int k = 0; k < 4 && flag; k++) {
							int nk = (k + 1)%4;
							if(ex[k] * ex[nk] + ey[k] * ey[nk] != 0 || sqr(ex[k]) + sqr(ey[k]) != sqr(ex[nk]) + sqr(ey[nk])) {
								flag = false;
							}
						}
						if(flag) {
							/*for(int k = 0; k < 4; k++) {
								cout << nodes[k].first << ' ' << nodes[k].second << endl;
							}*/
							if(ans == -1 || ans > p + q + r + s) {
								ans = p + q + r + s;
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}
