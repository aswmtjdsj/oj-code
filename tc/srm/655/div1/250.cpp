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

class BichromePainting {
    public:
        string isThatPossible(vector <string> board, int k) {
            int n = board.size();
            auto B = board;
            while(true) {
                bool biu = false;
                for(int i = 0; i < n - k + 1; i++) {
                    for(int j = 0; j < n - k + 1; j++) {
                        bool white = false, black = false;
                        for(int p = 0; p < k; p++) {
                            for(int q = 0; q < k; q++) {
                                if(B[i+p][j+q] == 'B') {
                                    black = true;
                                }
                                if(B[i+p][j+q] == 'W') {
                                    white = true;
                                }
                            }
                        }
                        if((black && !white) || (!black && white)) {
                            biu = true;
                            for(int p = 0; p < k; p++) {
                                for(int q = 0; q < k; q++) {
                                    B[i+p][j+q] = '!';
                                }
                            }
                        }
                    }
                }
                if(!biu) break;
            }
            bool flag = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(B[i][j] != '!') {
                        flag = false;
                    }
                }
            }
            return flag?"Possible":"Impossible";
        }
};

int main() {
    BichromePainting a;
    cout << a.isThatPossible({"BWBWBB",
            "WBWBWB",
            "BWBWBB",
            "WBWBWB",
            "BWBWBB",
            "BBBBBB"}, 2) << endl;
    cout << a.isThatPossible({
            "BBBW",
            "BWWW",
            "BWWW",
            "WWWW"}, 3) << endl;
    cout << a.isThatPossible({
            "BWBWBB",
            "WBWBBB",
            "BWBWBB",
            "WBWBBB",
            "BBBBBB",
            "BBBBBB"}, 2) << endl;
    cout << a.isThatPossible({
            "BWWWWBWBB",
            "BWWBBWWWB",
            "WWBBBBBWB",
            "WBWWWWWBB",
            "BWWBBBBWB",
            "WBBWWBWBB",
            "WWBBWWWBB",
            "WWBWBBWBB",
            "BWBBWWBBW"}, 7) << endl;
}
