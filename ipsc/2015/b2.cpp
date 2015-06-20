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
#include <stack>
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

vector <string> a, b, c;
map <string, int> ia, ib, ic;
vector <int> sa, sb, sc;
map <int, vector <pair<short, short> > > ab;
map <int, vector<int> > mc;
set < vector<int> > uni_ans;
int main() {
    int m, n;
    cin >> m;
    a.resize(m);
    b.resize(m);
    c.resize(m);
    sa.resize(m);
    sb.resize(m);
    sc.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> sa[i];
        ia[a[i]] = i;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> b[i] >> sb[i];
        ib[b[i]] = i;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> c[i] >> sc[i];
        ic[c[i]] = i;
        mc[sc[i]].push_back(i);
    }
    cerr << "begin" << endl;
    for(short i = 0; i < m; i++) {
        for(short j = 0; j < m; j++) {
            ab[sa[i]+sb[j]].push_back(MP(i, j));
        }
    }
    cerr << "after" << endl;
    cin >> n;
    uni_ans.clear();
    for(int i = 0; i < n; i++) {
        string ta, tb, tc;
        cin >> ta >> tb >> tc;
        int s = sa[ia[ta]] + sb[ib[tb]] + sc[ic[tc]];
        vector <int> ans;
        for(auto x: mc) {
            bool flag = false;
            for(auto z: x.second) {
                for(auto y: ab[s + 1 - x.first]) {
                    vector <int> temp;
                    temp.PB(y.first);
                    temp.PB(y.second);
                    temp.PB(z);
                    if(uni_ans.find(temp) == uni_ans.end()) {
                        uni_ans.insert(temp);
                        ans = temp;
                        flag = true;
                        break;
                    }
                }
                if(flag) {
                    break;
                }
            }
            if(flag) {
                break;
            }
        }
        cout << a[ans[0]] << ' ' << b[ans[1]] << ' ' << c[ans[2]] << endl;
        // cout << a[ans[0]] << ' ' << b[ans[1]] << ' ' << c[ans[2]] << ' ' << s << ' ' << sa[ans[0]] + sb[ans[1]] + sc[ans[2]] << endl;
    }
}
