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

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector<int> > g;
    g.resize(n*m);
    string opt;
    cin >> opt;
    for(int i = 0; i < n; i++) {
        // index as (i * m + j)
        if(opt[i] == '>') {
            for(int j = 0; j < m - 1; j++) {
                g[i*m+j].PB(i*m+j+1);
            }
        }
        else {
            for(int j = m - 1; j > 0; j--) {
                g[i*m+j].PB(i*m+j-1);
            }
        }
    }
    cin >> opt;
    for(int j = 0; j < m; j++) {
        // index as (i * m + j)
        if(opt[j] != '^') {
            for(int i = 0; i < n - 1; i++) {
                g[i*m+j].PB(i*m+j+m);
            }
        }
        else {
            for(int i = n - 1; i > 0; i--) {
                g[i*m+j].PB(i*m+j-m);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            queue <int> Q;
            set <int> vis;
            int index = i * m + j;
            Q.push(index);
            vis.insert(index);
            while(!Q.empty()) {
                int cur = Q.front();
                Q.pop();
                for(auto i: g[cur]) {
                    if(vis.find(i) == vis.end()) {
                        Q.push(i);
                        vis.insert(i);
                    }
                }
            }
            if(vis.size() != n * m) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
