#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct item {
    int x;
    int y;
    int z;
};
int main() {
    int t;
    cin >> t;
    for (int _ = 1; _ <= t; _++) {
        long double ans = 0.;
        int h, s;
        cin >> h >> s;
        vector <item> a(s);
        for (int i = 0; i < s; i++) {
            string in;
            cin >> in;
            size_t d = in.find('d');
            string xs = in.substr(0, d);
            istringstream xss(xs);
            xss >> a[i].x;
            size_t o = in.find('+');
            if (o == string::npos) {
                o = in.find('-');
                if (o == string::npos) { // no
                    string ys = in.substr(d + 1, in.size() - d);
                    istringstream yss(ys);
                    yss >> a[i].y;
                    a[i].z = 0;
                } else { // '-'
                    string ys = in.substr(d + 1, o - d);
                    istringstream yss(ys);
                    yss >> a[i].y;
                    string os = in.substr(o + 1, in.size() - o);
                    istringstream oss(os);
                    oss >> a[i].z;
                    a[i].z = -a[i].z;
                }
            } else { // '+'
                string ys = in.substr(d + 1, o - d);
                istringstream yss(ys);
                yss >> a[i].y;
                string os = in.substr(o + 1, in.size() - o);
                istringstream oss(os);
                oss >> a[i].z;
            }
        }
        /*for (int i = 0; i < s; i++) {
            cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << endl;
        }*/
        for (int i = 0; i < s; i++) {
            vector <vector<long double> >p;
            int tot = a[i].x * a[i].y;
            p.resize(a[i].x);
            for (int j = 0; j < p.size(); j++) {
                p[j].resize(tot+1, 0);
            }
            for (int j = 1; j <= a[i].y; j++) {
                p[0][j] = 1. / a[i].y;
            }
            for (int q = 0; q < a[i].x - 1; q++) {
                for (int j = 1; j <= tot; j++) {
                    for (int o = 1; o <= a[i].y; o++) {
                        if (j + o <= tot) {
                            p[q+1][j+o] += p[q][j] * (1. / a[i].y);
                        }
                    }
                }
            }
            long double tmp = 0.;
            for (int j = 1; j <= tot; j++) {
                if (j + a[i].z >= h) {
                    tmp += p[a[i].x-1][j];
                }
            }
            ans = max(tmp, ans);
            /*cout << i << ": " << endl;
            for (int j = 1; j <= tot; j++) {
                cout << j << ": ";
                for (int q = 0; q < a[i].x; q++) {
                    cout << p[q][j] << ' ';
                } cout << endl;
            }*/
        }
        cout << fixed << setprecision(6);
        cout << "Case #" << _ << ": " << ans << endl;
    }
    return 0;
}
