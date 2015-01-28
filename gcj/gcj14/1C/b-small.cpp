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

int ans;
int n;
vector <string> opt;
vector <bool> vis;
void dfs(int id, vector <int> & step) {
    if(step.size() == n) {
        string tmp = "";
        for(auto i: step) {
            tmp += opt[i];
        }
        int cnt[30];
        fill(cnt, cnt + 30, -1);
        bool flag = true;
        for(int idx = 0; idx < tmp.size(); idx++) {
            if(cnt[tmp[idx]-'a'] != -1 && cnt[tmp[idx]-'a'] != idx - 1) {
                flag = false;
                break;
            }
            cnt[tmp[idx]-'a'] = idx;
        }

        if(flag) {
            // cout << tmp << endl;
            ans++;
        }
        return ;
    }
    for(int i = 0; i < n; i++) {
        if(id != i && !vis[i]) {
            vis[i] = true;
            step.PB(i);
            dfs(i, step);
            vis[i] = false;
            step.pop_back();
        }
    }
}
int main() {
    int t;
    cin >> t;
    const int mod = 1000000007;
    for(int _ = 1; _ <= t; _++) {
        cin >> n;
        opt.resize(n);
        vis.resize(n);
        ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> opt[i];
        }
        for(int i = 0; i < n; i++) {
            fill(vis.begin(), vis.end(), false);
            vis[i] = true;
            vector <int> step;
            step.PB(i);
            dfs(i, step);
        }
        printf("Case #%d: %d\n", _, ans);
    }
}
