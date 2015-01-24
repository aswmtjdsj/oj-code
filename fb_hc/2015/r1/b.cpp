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

class Trie {
    public:
        Trie() {
            for(int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }

        Trie * child[26];

};

int find(Trie * node, const string &look, int idx) {
    // cout << look[idx] << endl;
    if((size_t) idx == look.size()-1 || node->child[look[idx]-'a'] == NULL) {
        return idx;
    } else {
        return find(node->child[look[idx]-'a'], look, idx+1);
    }
}

void insert(Trie *& node, const string &todo, int idx) {
    if((size_t)idx == todo.size()) return;
    if(node->child[todo[idx]-'a'] == NULL) {
        node->child[todo[idx]-'a'] = new Trie;
    }
    insert(node->child[todo[idx]-'a'], todo, idx+1);
}

int main() {
    int t;
    cin >> t;
    for(int c = 1; c <= t; c++) {
        int ans = 0;
        Trie * root = new Trie;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            string opt;
            cin >> opt;
            int temp = 0;
            temp = find(root, opt, 0) + 1;
            insert(root, opt, 0);
            ans += temp;
            // cout << opt << ' ' << temp << endl;
        }
        cout << "Case #" << c << ": " << ans << endl;
    }
}
