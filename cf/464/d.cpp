#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>

#include <string>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <list>
#include <vector>

#include <algorithm>
#include <complex>
using namespace std;

#define len(x) (x).size()
#define VI vector<int> 

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

template <class T>
inline T sqr(T x) { return x * x; }

const int inf = ~0u >> 1;
const double eps = 1e-6;
const double pi = acos(-1.0);

int sgn(double x) {
	return fabs(x) < eps ? 0:x < -eps?-1:1;
}

long long vert[9][4];
long long calc(int i, int j) {
    long long ans = 0;
    for(int k = 0; k < 3; k++) {
        ans += sqr(vert[i][k] - vert[j][k]);
    }
    return ans;
}
bool dfs(int step) {
    if(step == 9) {
        long long dis[8], min_dis = 1e18;
        for(int i = 1; i < 8; i++) {
            dis[i] = calc(0, i);
            min_dis = min(dis[i], min_dis);
        }
        dis[0] = 1e18;
        /*cout << "dis:\t";
        for(int i = 0; i < 8; i++) {
            cout << dis[i] << ' ';
        }
        cout << endl;*/
        vector <int> nei;
        for(int i = 1; i < 8; i++) {
            if(min_dis-dis[i] == 0) {
                nei.push_back(i);
            }
        }
        if(nei.size() != 3) {
            return false;
        }
        
        /*cout <<"nei:\t";
        for(int i = 0; i < nei.size(); i++) {
            cout << nei[i] << ' ';
        }
        cout << endl;*/
        
        vector <int> neinei, neinei_real;
        for(int i = 0; i < nei.size(); i++) {

            long long sub_dis[8], sub_min_dis = 1e18;
            for(int j = 0; j < 8; j++) {
                if(j != nei[i]) {
                    sub_dis[j] = calc(nei[i], j);
                    sub_min_dis = min(sub_dis[j], sub_min_dis);
                }
                else {
                    sub_dis[j] = 1e18;
                }
            }
            for(int j = 0; j < 8; j++) {
                if(sub_min_dis-sub_dis[j] == 0) {
                    neinei.push_back(j);
                }
            }
            if(neinei.size() != (i+1) * 3) {
                return false;
            }
            /*
            cout <<"neinei:\t";
            for(int i = 0; i < neinei.size(); i++) {
                cout << neinei[i] << ' ';
            }
            cout << endl;
            */
        }
        for(int i = 0; i < neinei.size(); i++) {
            bool flag = true;
            if(neinei[i] == 0) {
                flag = false;
                continue;
            }
            for(int j = 0; j < nei.size(); j++) {
                if(neinei[i] == nei[j]) {
                    flag = false;
                    break;
                }
            }
            for(int j = 0; j < neinei_real.size(); j++) {
                if(neinei[i] == neinei_real[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                neinei_real.push_back(neinei[i]);
            }
        }
        if(neinei_real.size() != 3) {
            return false;
        }
        /*
        cout <<"neinei_real:\t";
        for(int i = 0; i < neinei_real.size(); i++) {
            cout << neinei_real[i] << ' ';
        }
        cout << endl;
        */

        int biu = -1;
        vector <int> fin;
        for(int i = 0; i < neinei_real.size(); i++) {
            long long ris[8], min_ris = 1e18;
            for(int j = 0; j < 8; j++) {
                if(j != neinei_real[i]) {
                    ris[j] = calc(neinei_real[i], j);
                    min_ris = min(ris[j], min_ris);
                }
                else {
                    ris[j] = 1e18;
                }
            }
            for(int j = 0; j < 8; j++) {
                if(min_ris-ris[j] == 0) {
                    fin.push_back(j);
                }
            }
            if(fin.size() != (i+1) * 3) {
                return false;
            }
            /*
            cout <<"fin:\t";
            for(int j = 0; j < fin.size(); j++) {
                cout << fin[j] << ' ';
            }
            cout << endl;
            */
            
        }
        for(int i = 0; i < fin.size(); i++) {
            bool flag = true;
            for(int j = 0; j < nei.size(); j++) {
                if(fin[i] == nei[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                if(biu == -1) {
                    biu = fin[i];
                }
                else {
                    if(fin[i] != biu) {
                        return false;
                    }
                }
            }
        }
        //cout << "biu: " << biu << endl;
        if(biu == 0) return false;
        for(int i = 0; i < nei.size(); i++) {
            if(biu == nei[i]) return false;
        }
        for(int i = 0; i < neinei_real.size(); i++) {
            if(biu == neinei_real[i]) return false;
        }
        vector <long long> a, b, c;
        a.push_back(calc(biu, 0));
        for(int i = 0; i < nei.size(); i++) {
            b.push_back(calc(biu, nei[i]));
        }
        for(int i = 0; i < neinei_real.size(); i++) {
            c.push_back(calc(biu, neinei_real[i]));
        }
        /*
        cout << "a: ";
        for(int i = 0; i < a.size(); i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
        cout << "b: ";
        for(int i = 0; i < b.size(); i++) {
            cout << b[i] << ' ';
        }
        cout << endl;
        cout << "c: ";
        for(int i = 0; i < c.size(); i++) {
            cout << c[i] << ' ';
        }
        cout << endl;
        */
        if(b.size() != c.size()) return false;
        for(int i = 0; i < b.size() -1; i++) {
            if(b[i]-b[i+1] != 0) return false;
        }
        for(int i = 0; i < c.size() -1; i++) {
            if(c[i]-c[i+1] != 0) return false;
        }
        if(a[0] - b[0] - c[0] != 0) return false;

        return true;
    }
    sort(vert[step], vert[step] + 3);
    do {
        /*cout << "step #" << step << ":\t";
        for(int j = 0; j < 3; j++) {
            cout << vert[step][j] << ' ';
        }
        cout << endl;*/

        if(dfs(step+1)) {
            return true;
        }
    } while(next_permutation(vert[step], vert[step] + 3));
    return false;
}

int main() {
    for(int i = 0; i < 8 ;i++) {
        for(int j = 0; j < 3; j++) {
            cin >> vert[i][j];
        }
    }
    if(dfs(0)) {
        cout << "YES" << endl;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 3; j++) {
                cout << vert[i][j] << (j==2?'\n':' ');
            }
        }
    }
    else {
        cout << "NO" << endl;
    }
}
