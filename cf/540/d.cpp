#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>
#include <queue>
#include <iomanip>

using namespace std;

const int maxn = 105;

double dp[maxn][maxn][maxn] = {0.0};

void dfs(int r, int s, int t, double p) {
  
  int sum = r + s + t;
  dp[r][s][t] += p;
  cout << r << ' ' << s << ' ' << t << ' ' << dp[r][s][t] << endl;
  double below = (sum * (sum - 1) / 2) - (r > 0?(r * (r - 1)/2):0) - (s > 0?(s * (s - 1)/2):0) - (t > 0?(t * (t - 1)/2):0);
  //cout << below << endl;
  if(r > 0 && s > 0) dfs(r, s - 1, t, p * r * s * 1. / below);
  if(r > 0 && t > 0) dfs(r - 1, s, t, p * r * t * 1. / below);
  if(s > 0 && t > 0) dfs(r, s, t - 1, p * s * t * 1. / below);
}

int _r, _s, _t;

double dfs2(int r, int s, int t) {
  if(r > _r || s > _s || t > _t) return 0.;
  if(r == _r && s == _s && t == _t) return dp[r][s][t] = 1;
  if(dp[r][s][t] != 0) {
    return dp[r][s][t];
  }
  if(r == 0 && s == 0 && t == 0) {
    dfs2(r+1, s, t);
    dfs2(r, s+1, t);
    dfs2(r, s, t+1);
    return 0.;
  }
  int sum = r + s + t + 1;
  double below, above, p;
  
  above = (r + 1) * t;
  below = ((sum * (sum - 1) / 2) - (r > 0?(r * (r + 1)/2):0) - (s > 0?(s * (s - 1)/2):0) - (t > 0?(t * (t - 1)/2):0));
  if(below > 0) p = above / below;
  else p = 0.;
  dp[r][s][t] += p * dfs2(r + 1, s, t);
  
  above = r * (s + 1);
  below = ((sum * (sum - 1) / 2) - (r > 0?(r * (r - 1)/2):0) - (s > 0?(s * (s + 1)/2):0) - (t > 0?(t * (t - 1)/2):0));
  if(below > 0) p = above / below;
  else p = 0.;
  dp[r][s][t] += p * dfs2(r, s + 1, t);
  
  above= s * (t + 1);
  below = ((sum * (sum - 1) / 2) - (r > 0?(r * (r - 1)/2):0) - (s > 0?(s * (s - 1)/2):0) - (t > 0?(t * (t + 1)/2):0));
  if(below > 0) p = above / below;
  else p = 0.;
  dp[r][s][t] += p * dfs2(r, s, t + 1);
  return dp[r][s][t];
}
int main() {
  int r, s, t;
  //r = s = t = 1;
  //t = 3;
  cin >> r >> s >> t;
  //dp[r][s][t] = 1.;
  //dfs(r, s, t, 1.);
  _r = r, _s = s, _t = t;
  dfs2(0, 0, 0);
  double R, S, T;
  R = S = T = 0;
  for(int i = 1; i <= r; i++) R += dp[i][0][0];
  for(int i = 1; i <= s; i++) S += dp[0][i][0];
  for(int i = 1; i <= t; i++) T += dp[0][0][i];
  cout << fixed;
  cout << setprecision(10) << R << ' ' << S << ' ' << T << endl;
}
