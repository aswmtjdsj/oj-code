#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int maxn = 505;
char grid[maxn][maxn];
bool vis[maxn][maxn];
int r, c;
typedef pair <int, int> pii;
pii st, en;

int dx[] = {-1, 0 , 1, 0}, dy[] = {0, -1, 0, 1};

bool check(pii p) {
  return 0 <= p.first && p.first < r && 0 <= p.second && p.second < c;
}

bool dfs2(pii s, pii e) {
  //cout << "d2: " << s.first << ' ' << s.second << endl;
  for(int i = 0; i < 4; i++) {
    pii n = s;
    n.first += dx[i], n.second += dy[i];
    if(check(n)) {
      if(grid[n.first][n.second] == '.') {
        grid[n.first][n.second] = 'X';
        bool temp = dfs2(n, e);
        if(temp) {
          return true;
        }
        //grid[n.first][n.second] = '.';
      } else if(n == e) {
        return true;
      }
    }
  }
  return false;
}

bool dfs1(pii s, pii e) {
  //cout << "d1: " << s.first << ' ' << s.second << endl;
  for(int i = 0; i < 4; i++) {
    pii n = s;
    n.first += dx[i], n.second += dy[i];
    if(check(n)) {
      if(n == e) {
        if(grid[n.first][n.second] == 'X') return true;
        grid[n.first][n.second] = 'X';
        bool temp = dfs2(n, e);
        if(temp) {
          return true;
        }
        //grid[n.first][n.second] = '.';
      } else if(grid[n.first][n.second] == '.') {
        grid[n.first][n.second] = 'X';
        bool temp = dfs1(n, e);
        if(temp) {
          return true;
        }
        //grid[n.first][n.second] = '.';
      }
    }
  }
  return false;
}

int main() {
  cin >> r >> c;
  for(int i = 0; i < r; i++) {
    scanf(" %s", grid[i]);
  }
  cin >> st.first >> st.second;
  cin >> en.first >> en.second;
  st.first--;
  st.second--;
  en.first--;
  en.second--;
  bool flag = false;
  flag = dfs1(st, en);
  cout << (flag?"YES":"NO") << endl;
  return 0;
}
