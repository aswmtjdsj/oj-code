#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
void nextMove(int n, int r, int c, vector <string> grid){
    //your logic here
    pair <int, int> s, t;
    int m = grid[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'm') {
                s = make_pair(i, j);
            }
            if(grid[i][j] == 'p') {
                t = make_pair(i, j);
            }
        }
    }
    vector < vector <int> > maze;
    vector < vector <int> > pre;
    maze.resize(n);
    pre.resize(n);
    for(auto &i: maze) {
        i.resize(m);
        fill(i.begin(), i.end(), -1);
    }

    for(auto &i: pre) {
        i.resize(m);
        fill(i.begin(), i.end(), -1);
    }
    maze[s.first][s.second] = 0;
    pre[s.first][s.second] = 4;
    queue < pair<int, int> > Q;
    Q.push(s);
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
    string step[] = {"UP", "DOWN", "RIGHT", "LEFT"};
    while(!Q.empty()) {
        pair <int, int> cur = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++) {
            pair <int, int> temp = make_pair(cur.first + dx[i], cur.second + dy[i]);
            if(temp.first < 0 || temp.first >= n || temp.second < 0 || temp.second >= m) continue;
            if(maze[temp.first][temp.second] == -1 || maze[temp.first][temp.second] > maze[cur.first][cur.second] + 1) {
                maze[temp.first][temp.second] = maze[cur.first][cur.second] + 1;
                pre[temp.first][temp.second] = i;
                Q.push(temp);
            }
        }
    }
    vector <string> ans;
    pair <int, int> back = t;
    while(true) {
        int choice = pre[back.first][back.second];
        if(choice != 4) {
            ans.push_back(step[pre[back.first][back.second]]);
            back.first += dx[choice^1];
            back.second += dy[choice^1];
        } else {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    /*for(auto i: ans) {
      cout << i << endl;
      }*/
    cout << ans[0] << endl;

}
int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}

