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

class A {
    public:
        vector <int> biu;
        int id;
        int _f;
        void f() {
            int ans = 0;
            for(int i = 0; i < biu.size(); i++) {
                int _min = biu[i];
                for(int j = i; j < biu.size(); j++) {
                    _min = min(_min, biu[j]);
                    ans += _min;
                }
            }
            _f = ans;
        }

        friend bool operator < (const A & a, const A & b) {
            return a._f < b._f || (a._f == b._f && a.id > b.id);
        }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> p(n);
    for(int i = 0; i < n; i++) {
        p[i] = i+1;
    }
    set <A> s;
    int cnt = 0;
    do {
        A a;
        a.biu = p;
        a.f();
        a.id = cnt++;
        s.insert(a);
    } while(next_permutation(p.begin(), p.end()));
    //cout << s.size() << endl;
    for(auto idx = s.rbegin(); idx != s.rend(); idx++) {
        m--;
        if(m == 0) {
            for(auto j: idx->biu) {
                cout << j << ' ';
            }cout << endl;
            cout << idx->_f << endl;
            break;
        }
    }
    /*for(auto i = s.begin(); i != s.end(); i++) {
        cout << i->id << endl;
        cout << i->_f << endl;
        for(auto j: i->biu) {
            cout << j << ' ';
        }cout << endl;
    }*/
}
