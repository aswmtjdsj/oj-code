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
/* TC HEADER END */

class TaroJiroDividing {
	public:
        int getNumber(int a, int b) {
            VI va, vb;
            va.PB(a);
            while(a % 2 == 0) {
                a /= 2;
                va.PB(a);
            }
            vb.PB(b);
            while(b % 2 == 0) {
                b /= 2;
                vb.PB(b);
            }
            for(auto i: va) {
                cout << i << ' ';
            } cout << endl;
            for(auto i: vb) {
                cout << i << ' ';
            } cout << endl;
            int cnt = 0;
            for(int i = 0; i < va.size(); i++) {
                for(int j = 0; j < vb.size(); j++) {
                    if(va[i] == vb[j]) {
                        cnt++;
                        break;
                    }
                }
            }
            return cnt;
        }
};

int main() {
    TaroJiroDividing a;
    cout << a.getNumber(1000000000, 500000000) << endl;
}
