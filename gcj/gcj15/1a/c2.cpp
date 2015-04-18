/* base IO */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>

/* data structure */
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <bitset>

/* alrotihm and math */
#include <algorithm>
#include <random>
#include <cmath>

/* run-time */
#include <cstdlib>
#include <ctime>
#include <climits>

/* system dependent */
#include <sys/time.h>

using namespace std;

#define VI vector<int>
#define VD vector<double>
#define PII pair<int, int>
#define PDD pair<double, double>
#define PB push_back
#define MP make_pair
#define len(x) ((x).size())

const int inf = INT_MAX;
const long long inf_ll = 0x7f7f7f7f;
const double eps = 1e-8;

/*
 * 0 1 2
 * 3   4
 * 5 6 7
 */
const int bfs_dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int bfs_dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
 *   3  
 * 2   0
 *   1  
 */
const int dfs_dy[] = {0, 1, 0, -1};
const int dfs_dx[] = {1, 0, -1, 0};

PII dir[] = {make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)};
/* TC HEADER END */

/*bool cmp2(const Point &a,const Point &b) {
	double theta1 = atan2((a.y - c.y),(a.x - c.x));
	double theta2 = atan2((b.y - c.y),(b.x - c.x));
	return (comp(theta1 - theta2) < 0) || (comp(theta1 - theta2) == 0 && comp(a.norm() - b.norm()) < 0);
}*/

const int maxn = 3005;
int ans[maxn];
PII pts[maxn], angles[maxn];

int main() {
    int T;
    cin >> T;
    for(int _ = 1; _ <= T; _++) {
        int n;
        cin >> n;
        fill(ans, ans + n, n - 1);
        for(int i = 0; i < n; i++) {
            cin >> pts[i].first >> pts[i].second;
        }
        if(n > 1) {
            for(int i = 0; i < n; i++) {
                int cnt = 0;
                for(int j = 0; j < n; j++) {
                    if(j != i) {
                        angles[cnt++] = MP(pts[j].first - pts[i].first, pts[j].second - pts[i].second);
                        // cout << cnt -1 << ' ' << angles[cnt-1].first << ' ' << angles[cnt-1].second << endl;
                    }
                }
                // cout << "calc" << endl;
                // cout << atan2(0, 0) << endl;
                int debug = 0;
                auto f = [&debug](const PII &a, const PII &b) { 
                    // cout << atan2(a.second, a.first) << ' ' <<  atan2(b.second, b.first) << endl;
                    // cout << debug << ' ' << a.first << ' ' << a.second << '\t' << b.first << ' ' << b.second << endl;
                    debug++;
                    return atan2(a.second, a.first) - atan2(b.second, b.first) < -eps;
                    // return atan2(a.second, a.first) - atan2(b.second, b.first) < -eps || (fabs(atan2(a.second, a.first) - atan2(b.second, b.first)) < eps && (a.second * (long long) a.second + a.first * (long long) a.first) <  (b.second * (long long) b.second + b.first * (long long) b.first));
                };
                auto f2 = [](PII a, PII b) { 
                    return (a.first * (long long)b.second - a.second * (long long)b.first) >= 0;
                };
                // cout << "f f2" << endl;
                sort(angles, angles + cnt, f);
                // cout << "sorted" << endl;
                /*if(i == 4) {
                  cout << "AA " << pts[i].first << ' ' << pts[i].second << " : " << endl;
                  for(int j = 0; j < cnt; j++) {
                  cout << angles[j].first << ' ' << angles[j].second << endl;
                  }
                  }*/
                int p = 0, q = 0;
                int temp = 2;
                while(true) {
                    bool flag = false;
                    /*if(i == 4) {
                      cout << p << ' ' << q << endl;
                      }*/
                    while(f2(angles[p], angles[q])) {
                        ans[i] = min(ans[i], n - temp);
                        q++;
                        temp++;
                        q %= cnt;
                        if(q == p) {
                            flag = true;
                            break;
                        }
                    } 
                    if(flag) break;
                    while(!f2(angles[p], angles[q])) {
                        p++;
                        temp--;
                        if(p == cnt) {
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }
            }
        }

        printf("Case #%d: \n", _);
        for(int i = 0; i < n; i++) {
            cout << ans[i] << endl;
        }
    }
}