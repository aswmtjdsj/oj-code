#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <queue>

using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)

#define MULTIPLE "Bad magician!"
#define NOANS "Volunteer cheated!"

typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int inf = INT_MAX;
const double eps = 1e-8;

int sgn(double x) {
    return fabs(x) < eps ? 0:x < -eps ? -1:1;
}

vector <vector<int> > g;
int dfs(int cur, int p) {
    if((p == -1 && g[cur].size() < 2) || // root and no more than 1 child
            (p != -1 && g[cur].size() < 3)) { // non root and no more than one child
        return 1;
    }
    vector<int> a; // number denoting children size
    for(int v = 0; v < g[cur].size(); v++) {
        if(g[cur][v] == p) {
            continue;
        }
        a.PB(dfs(g[cur][v], cur));
    }
    sort(a.begin(), a.end(), std::greater<int>());
    return a[0] + a[1] + 1;
}

int main(){
    int T;
    cin >> T;
    for(int c = 1; c <= T; c++) {
        g.clear();
        int n;
        cin >> n;
        g.resize(n);
        int ans = n;
        for(int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].PB(b);
            g[b].PB(a);
        }
        for(int i = 0; i < n; i++) {
            ans = min(ans, n - dfs(i, -1));
        }
        printf("Case #%d: %d\n", c, ans);
    }
}
