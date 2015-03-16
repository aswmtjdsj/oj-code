#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int board[12][12];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 1) {
                queue <pair<int, int> > Q;
                Q.push(make_pair(i, j));
                board[i][j] = 2;
                int temp = 0;
                while(!Q.empty()) {
                    pair <int, int> cur = Q.front();
                    /*cout << cur.first << ' ' << cur.second << endl;
                     *                     for(int i = 0; i < m; i++) {
                     *                                             for(int j = 0; j < n; j++) {
                     *                                                                         cout << board[i][j] << ' ';
                     *                                                                                                 } cout << endl;
                     *                                                                                                                     } cout << endl;*/
                    Q.pop();
                    temp++;
                    for(int i = 0; i < 8; i++) {
                        pair <int, int> next = make_pair(cur.first+dx[i], cur.second+dy[i]);
                        if(0 <= next.first && next.first < m && 0 <= next.second && next.second < n && board[next.first][next.second] == 1) {
                            // cout << "p: " << next.first << ' ' << next.second << endl;
                            Q.push(next);
                            board[next.first][next.second] = 2;
                        }
                    }
                }
                ans = max(ans, temp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

