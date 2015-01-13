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
char dir_s[] = {'>', 'v', '<', '^'};
/* TC HEADER END */

int main() {
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++) {
        int m, n;
        cin >> m >> n;
        vector <string> maze;
        maze.resize(m);
        for(int i = 0; i < m; i++) {
            cin >> maze[i];
        }
        /*if(k == 52) {
            for(int i = 0; i < m; i++) {
                cout << maze[i] << endl;
            }
        } else {
            continue;
        }*/
        PII sp = MP(-1, -1), gp = MP(-1, -1);
        vector < pair<PII, int> > ts;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(maze[i][j] == 'S') {
                    sp = MP(i, j);
                }
                if(maze[i][j] == 'G') {
                    gp = MP(i, j);
                }
                for(int p = 0; p < 4; p++) {
                    if(maze[i][j] == dir_s[p]) {
                        ts.PB(MP(MP(i, j), p));
                        break;
                    }
                }
            }
        }
        /*for(int i = 0; i < ts.size(); i++) {
            cout << ts[i].first.first << ' ' << ts[i].first.second << ' ' << ts[i].second << endl;
        }*/
        map<pair<PII, int>, bool> M;
        queue<pair<PII, int> > Q;
        Q.push(MP(sp, 0));
        M[MP(sp, 0)] = true;
        int ans = inf;
        while(!Q.empty()) {
            pair<PII, int> cur = Q.front();
            // cout << "cur: " << cur.first.first << ' ' << cur.first.second << ' ' << cur.second << endl;
            Q.pop();
            if(cur.second != 0) {
                bool shot = false;
                for(int i = 0; i < ts.size() && !shot; i++) {
                    // cout << "O " << ts[i].first.first << ' ' << ts[i].first.second << endl;
                    // cout << "C " << cur.first.first << ' ' << cur.first.second << ": " << cur.second << endl;
                    int t_dir = (ts[i].second + cur.second) % 4;
                    int j = 1;
                    while(1) {
                        PII light = MP(ts[i].first.first + dir[t_dir].first * j, ts[i].first.second + dir[t_dir].second * j);
                        if(light.first < 0 || light.first >= m || light.second < 0 || light.second >= n) break;
                        bool hit = false;
                        // cout << light.first << ' ' << light.second << endl;
                        if(maze[light.first][light.second] == '#') {
                            hit = true;
                        }
                        for(int d = 0; d < 4; d++) {
                            if(maze[light.first][light.second] == dir_s[d]) {
                                hit = true;
                                break;
                            }
                        }
                        if(light == cur.first) {
                            hit = true;
                            shot = true;
                        }
                        if(hit) {
                            break;
                        }
                        j++;
                    }
                }
                if(shot) {
                    continue;
                }
                // cout << "Pass" << endl;
            }
            if(cur.first == gp) {
                ans = min(ans, cur.second);
            }
            for(int d = 0; d < 4; d++) {
                PII next = MP(cur.first.first + dir[d].first, cur.first.second + dir[d].second);
                if(next.first < 0 || next.first >= m || next.second < 0 || next.second >= n || maze[next.first][next.second] == '#') {
                    continue;
                }

                bool okay = true;
                for(int p = 0; p < 4; p++) {
                    if(maze[next.first][next.second] == dir_s[p]) {
                        okay = false;
                        break;
                    }
                }
                if(!okay) {
                    continue;
                }

                if(M.find(MP(next, (cur.second+1) % 4)) == M.end()) {
                    Q.push(MP(next, cur.second+1));
                    M[MP(next, (cur.second+1) % 4)] = true;
                }
            }
        }

        cout << "Case #" << k << ": ";
        if(ans != inf) {
            cout << ans << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
}
