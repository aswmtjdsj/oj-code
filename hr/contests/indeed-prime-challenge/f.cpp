/* base IO */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>
#include <cassert>

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
 *  * 0 1 2
 *   * 3   4
 *    * 5 6 7
 *     */
const int bfs_dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int bfs_dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
 *  *   3  
 *   * 2   0
 *    *   1  
 *     */
const int dfs_dy[] = {0, 1, 0, -1};
const int dfs_dx[] = {1, 0, -1, 0};

PII dir[] = {make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)};
/* TC HEADER END */

int main() {
    vector <string> a, b;
    string _a, _b, opt, raw;
    vector <int> data;
    int train_size = 0, test_size = 0;
    while(cin >> _a >> opt >> _b >> raw) {
        a.PB(_a);
        b.PB(_b);
        if(raw[0] == 'M') {
            data.PB(-1);
            test_size ++;
        } else {
            data.PB(stoi(raw));
            train_size ++;
        }
        // cout << *data.rbegin() << endl;
    }
    /*cout << "train: " << train_size << endl;
      cout << "test: " << test_size << endl;*/
    double delta = data[train_size-1] - data[train_size-1-53];
    delta += data[train_size-2] - data[train_size-2-53];
    //delta += data[train_size-3] - data[train_size-3-53];
    delta /= 2;
    for(int i = 0; i < test_size; i++) {
        data[i+train_size] = data[i+train_size-53] + delta;
        delta = data[i+train_size] = data[i+train_size-53];
        delta += data[i+train_size-1] = data[i+train_size-1-53];
        delta /= 2.;
        cout << data[i+train_size] << endl;
    }

    return 0;
}
