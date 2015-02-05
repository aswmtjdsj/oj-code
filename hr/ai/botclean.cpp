#include<iostream>
#include<vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
void next_move(int posr, int posc, vector <string> board) {
    //add logic here
    if(board[posr][posc] == 'd') {
        cout << "CLEAN" << endl;
    } else {
        pair <int, int> s = make_pair(posr, posc);
        int n = board.size(), m = board[0].size();
        vector < pair <int, int> > ds;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'd') {
                    ds.push_back(make_pair(i, j));
                }
            }
        }
        int state = 0;
        for(int i = 0; i < ds.size(); i++) {
            state |= (1 << i);
        }
        queue < pair< pair<int, int>, int> > Q;
        Q.push(make_pair(s, state));
        map < pair< pair<int, int>, int>, int > M;
        map < pair< pair<int, int>, int>, pair< pair<int, int>, int> > pre;
        M[make_pair(s, state)] = 0;
        pre[make_pair(s, state)] = make_pair(make_pair(-1, -1), state);
        string dir_s[] = {"LEFT", "RIGHT", "UP", "DOWN"};
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        while(!Q.empty()) {
            pair < pair<int, int>, int> cur = Q.front();
            Q.pop();
            for(int i = 0; i < 4; i++) {
                pair <int, int> to = make_pair(cur.first.first + dx[i], cur.first.second + dy[i]);
                int to_state = cur.second;
                if(to.first < 0 || to.first >= n || to.second < 0 || to.second >= m) continue;
                if(board[to.first][to.second] == 'd') {
                    for(int j = 0; j < ds.size(); j++) {
                        if(ds[j] == to) {
                            if(to_state & (1 << j)) {
                                to_state ^=  (1 << j);
                            }
                            break;
                        }
                    }
                } 
                if(M.find(make_pair(to, to_state)) == M.end() || M[make_pair(to, to_state)] > M[cur] + 1) {
                    M[make_pair(to, to_state)] = M[cur] + 1;
                    pre[make_pair(to, to_state)] = cur;
                    Q.push(make_pair(to, to_state));
                }
            }
        }
        pair< pair<int, int>, int> ans;
        int better = n * m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(M.find(make_pair(make_pair(i, j), 0)) != M.end() && better > M[make_pair(make_pair(i, j), 0)]) {
                    better = M[make_pair(make_pair(i, j), 0)];
                    ans = make_pair(make_pair(i, j), 0);
                }
            }
        }
        // cout << better << endl;
        vector <string> output;
        while(true) {
            // cout << ans.first.first << ' ' << ans.first.second << endl;
            auto temp = pre[ans];

            if(temp == make_pair(make_pair(-1, -1), state)) {
                break;
            }

            if(temp.first.first > ans.first.first) {
                output.push_back("UP");
            } else if(temp.first.first < ans.first.first) {
                output.push_back("DOWN");
            } else if(temp.first.second < ans.first.second) {
                output.push_back("RIGHT");
            } else if(temp.first.second > ans.first.second) {
                output.push_back("LEFT");
            }
 
            ans = temp;
        }
        reverse(output.begin(), output.end());
        cout << output[0] << endl;
        /*for(auto i: output) {
            cout << i << endl;
        }*/
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
    next_move(pos[0], pos[1], board);
    return 0;
}

