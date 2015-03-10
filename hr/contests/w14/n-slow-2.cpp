#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int maxn = 200005;
int a[maxn];
pair <int, int> p[maxn];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++) {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            scanf(" %d", &a[i]);
            p[i] = make_pair(a[i], i);
        }
        sort(p, p + n, std::greater< pair<int, int> >());
        /*for(int i = 0; i < n; i++) {
            cout << p[i].first << ' ' << p[i].second << endl;
        }*/
        map <int, long long> c;
        long long ans = (long long)n * (long long)(n+1) / 2;
        vector <int> pos;
        pos.reserve(n);
        for(int i = 0; i < n; i++) {
            auto l = lower_bound(pos.begin(), pos.end(), p[i].second);
            auto u = upper_bound(pos.begin(), pos.end(), p[i].second);
            l --;

            int l_i, u_i;
            if(l - pos.begin() >= 0) {
                l_i = (*l)+1;
            } else {
                l_i = 0;
            }
            if(u != pos.end()) {
                u_i = (*u)-1;
            } else {
                u_i = n - 1;
            }
            // cout << l_i << ' ' << u_i << endl;
            long long leftp = p[i].second - l_i + 1,
                 rightp = u_i - p[i].second;
            c[p[i].first] = leftp * (rightp+1);
            pos.insert(u, p[i].second);
            /*for(auto j: pos) {
                cout << j << ' ';
            } cout << endl;*/
        }
        for(auto i: c) {
            // cout << i.first << ' ' << i.second << endl;
            if(i.first <= k) {
                ans -= i.second;
            } else {
                // break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

