#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>

using namespace std;
void nextMove(int posr, int posc, vector <string> board) {
    //add logic here
    typedef pair <int, int> pii;
#define MP make_pair

    pii s = MP(posr, posc);
    if(board[s.first][s.second] == 'd') {
        cout << "CLEAN" << endl;
        return ;
    }
    int n = board.size(), m = board[0].size();

    pii g;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'd') {
                g = MP(i, j);
                break;
            }
        }
    }

    vector < vector <int> > dp(n);
    vector < vector <int> > pre(n);
    for(auto &i: dp) {
        i.resize(m);
        fill(i.begin(), i.end(), n * m);
    }
    for(auto &i: pre) {
        i.resize(m);
        fill(i.begin(), i.end(), -1);
    }
    dp[s.first][s.second] = 0;
    queue < pii > Q;
    Q.push(s);
    string dir_s[] = {"LEFT", "RIGHT", "UP", "DOWN"};
    int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
    while(!Q.empty()) {
        pii cur = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++) {
            pii to = MP(cur.first + dx[i], cur.second + dy[i]);
            if(to.first < 0 || to.first >= n || to.second < 0 || to.second >= m) continue;
            if(dp[to.first][to.second] > dp[cur.first][cur.second] + 1) {
                dp[to.first][to.second] = dp[cur.first][cur.second] + 1;
                pre[to.first][to.second] = i;
                Q.push(to);
            }
        }
    }
    vector <string> ans;
    while(true) {
        int i = pre[g.first][g.second];
        if(i == -1) break;
        ans.push_back(dir_s[i]);
        g.first = g.first - dx[i];
        g.second = g.second - dy[i];
    }
    reverse(ans.begin(), ans.end());
    // cout << ans[0] << endl;
    for(auto i: ans) {
        cout << i << endl;
    }
}
int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    nextMove(pos[0], pos[1], board);
    return 0;
}

