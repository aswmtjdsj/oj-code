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

class ApplesAndOrangesEasy {
	public:
        int maximumApples(int n, int k, vector <int> info) {
            vector <int> f, s;
            f.resize(n, 0);
            s.resize(n, 0);
            for(auto i: info) {
                f[i-1] = 1;
            }
            for(int i = 0; i < n; i++) {
                if(f[i] == 1) {
                    for(int j = i; j < n; j++) {
                        s[j]++;
                    }
                }
            }
            /*for(auto i: f) {
                cout << i << ' ';
            } cout << endl;
            for(auto i: s) {
                cout << i << ' ';
            } cout << endl;*/
            for(int i = 0; i < n - k + 1; i ++ ) {
                int temp = k / 2;
                temp -= (s[i+k-1] - ((i > 0)?s[i-1]:0));
                // cout << i << ' ' << temp << endl;
                int j = i;
                // cout << i << ' ' << temp << endl;
                while(temp > 0) {
                    bool mark = false;
                    // cout << "j: " << j << endl;
                    for(; j < i + k; j++) {
                        if(f[j] == 0) {
                            bool gogo = true;
                            // key point
                            for(int p = j - k + 1; p <= j; p++) {
                                // cout << "p: " << p << endl;
                                if(p < 0 || p + k > n) continue;
                                int c = s[p+k-1] - ((p > 0)?s[p-1]:0);
                                if(c + 1 > (k / 2)) {
                                    gogo = false;
                                    break;
                                }
                            }
                            if(gogo) {
                                mark = true;
                                f[j] = 1;
                                for(int p = j; p < n; p++) {
                                    s[p]++;
                                }
                                temp--;
                            } else {
                                break;
                            }
                        }
                        if(temp == 0) {
                            break;
                        }
                    }
                    if(!mark) {
                        break;
                    }
                }
                for(int j = i; j < i + k; j++) {
                    if(f[j] == 0) {
                        f[j] = 2;
                    }
                }
                /*for(auto i: f) {
                    cout << i << ' ';
                } cout << endl;
                for(auto i: s) {
                    cout << i << ' ';
                } cout << endl;*/
            }
            int ans = 0;
            for(auto i: f) {
                if(i == 1) ans++;
                cout << i << ' ';
            } cout << endl;
            return ans;
        }
};

int main() {
    ApplesAndOrangesEasy a;
    cout << a.maximumApples(2000, 2000, {138, 130, 458, 168, 970, 807, 385, 398, 810, 385, 554, 752, 816, 333, 213, 968, 379, 100, 733, 602, 685, 531, 797, 865, 138, 7, 934, 300, 682, 937, 884, 618, 121, 749, 602, 234, 697, 614, 302, 124, 269, 210, 263, 541, 132, 981, 963, 214, 194, 84, 108, 973, 232, 511, 964, 13, 331, 963, 676, 623, 387, 785, 329, 881, 347, 233, 98, 80, 184, 35, 914, 541, 686, 97, 147, 1000, 390, 177, 424, 608, 800, 439, 288, 4, 191, 124, 367, 526, 434, 664, 936, 761, 693, 472, 530, 7, 569, 680, 60, 547, 542, 746, 293, 846, 372, 793, 388, 604, 645, 292, 104, 178, 26, 144, 982, 541, 400, 149, 336, 785, 235, 794, 91, 734, 236, 132, 30, 796, 65, 572, 96, 924, 661, 968, 127, 14, 730, 952, 475, 448, 719, 155, 443, 417, 996, 296, 365, 970, 848, 244, 337, 981, 489, 556, 320, 296, 572, 265, 595, 187, 780, 641, 567, 158, 707, 844, 168, 250, 69, 304, 219, 871, 296, 171, 524, 895, 783, 491, 955, 701, 994, 382, 517, 696, 288, 819, 85, 943, 918, 372, 98, 498, 505, 298, 152, 723, 865, 716, 459, 985, 508, 652, 268, 480, 215, 471, 420, 789, 963, 417, 865, 59, 302, 361, 698, 625, 623, 426, 678, 380, 800, 714, 33, 838, 542, 736, 531, 165, 128, 253, 606, 194, 561, 433, 841, 309, 490, 263, 548, 938, 794, 480, 54, 540, 803, 741, 603, 729, 15, 187, 15, 119, 143, 714, 440, 592, 130, 525, 821, 868, 95, 608, 569, 447, 154, 932, 430, 122, 265, 144, 747, 173, 538, 114, 491, 362, 648, 754, 609, 943, 669, 741, 485, 424, 226, 203, 497, 534, 158, 229, 961, 649, 968, 662, 110, 731, 730, 974, 854, 538, 763, 285, 885, 21, 477, 37, 495, 1000, 257, 670, 616, 839, 882, 733, 169, 889, 714, 329, 253, 354, 402, 516, 100, 199, 223, 749, 203, 981, 751, 736, 488, 511, 533, 753, 473, 655, 957, 571, 642, 549, 231, 542, 287, 709, 514, 430, 547, 811, 568, 880, 97, 778, 468, 31, 134, 221, 953, 767, 874, 415, 550, 636, 432, 775, 185, 419, 533, 437, 342, 124, 286, 321, 2, 486, 325, 367, 687, 181, 553, 264, 907, 846, 449, 846, 469, 600, 262, 199, 720, 2, 659, 935, 188, 522, 472, 311, 692, 781, 831, 928, 947, 444, 259, 106, 508, 968, 262, 165, 138, 981, 192, 139, 286, 813, 7, 292, 767, 522, 61, 595, 780, 218, 568, 686, 590, 448, 905, 30, 780, 280, 325, 653, 743, 722, 339, 452, 675, 486, 22, 927, 537, 3, 225, 655, 982, 655, 421, 493, 596, 223, 203, 231, 209, 515, 530, 494, 934, 826, 898, 56, 388, 666, 123, 499, 163, 757, 925, 609, 213, 229, 542, 581, 309, 706, 119, 351, 502, 273, 322, 354, 989, 346, 438, 324, 431, 187, 32, 311, 170, 369, 952, 672, 279, 977, 35, 407, 557, 711, 508, 191}) << endl;
}
