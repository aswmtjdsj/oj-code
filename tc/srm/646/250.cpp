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

class TheConsecutiveIntegersDivOne {
	public:
        int find(vector <int> numbers, int k) {
            int len = numbers.size();
            int ans = inf;
            sort(numbers.begin(), numbers.end());
            for(int i = 0; i < len; i++) cout << numbers[i] << endl;
            for(int i = 0; i < len - k + 1; i++) {
                for(int j = 0; j < k; j++) {
                    int p = i + j;
                    vector <int> tobe;
                    int temp = 0;
                    for(int q = 0; q < k; q++) {
                        tobe.PB(numbers[p] + (q + i - p));
                    }
                    for(int q = 0; q < k; q++) {
                        temp += abs(tobe[q] - numbers[i + q]);
                    }
                    for(int q = 0; q < k; q++) cout << tobe[q] << ' ';
                    cout << i << ' ' << j << ' ' << temp << endl;
                    ans = min(ans, temp);
                }
            }
            return ans;
        }
};

int main() {
    TheConsecutiveIntegersDivOne a;
    cout << a.find({-296, 136, -144, 62, -187, -39, -80, 161, -91, 303, -293, 61, -112, -27, -179, -215, -41, 3, -12, -134, 38, 184, -95, -11, 151, -236, -3, -75, -56, -254, -288, 212, -315, 163, 73, 4, 41, -233, -108, -51, 238, -169, -130, -270, 145, -218, 112}, 2) << endl;
}
