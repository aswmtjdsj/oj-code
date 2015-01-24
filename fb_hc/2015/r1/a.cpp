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
#include <cassert>

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

class Sieve {
    public:
        Sieve();
        Sieve(const int &);

        void sieve();
        void print(int start = 0, int end = 0);

        int size, prime_count;
        vector <bool> is_prime;
        vector <int> prime;
};

Sieve::Sieve(): size(0), prime_count(0){
    is_prime.clear();
    prime.clear();
}

Sieve::Sieve(const int &n): size(n + 1), prime_count(0) {
    is_prime.resize(size);
    int prime_size = size / round(log(size) / 2);
    prime.resize(prime_size);
}

void Sieve::sieve() {
    fill(is_prime.begin(), is_prime.end(), true);
    prime[prime_count++] = 2;
    cout << 2 << endl;
    for(int x = 3; x < size; x += 2) {
        if(is_prime[x]) {
            prime[prime_count++] = x;
            cout << x << endl;
            assert(prime_count <= size);
            for(int j = x * 3; j < size; j += x) {
                is_prime[j] = false;
            }
        }
    }
    prime.resize(prime_count);
}

void Sieve::print(int start, int end) {
    cout << "prime: " << prime.size() << endl;
    auto s = lower_bound(prime.begin(), prime.end(), start);
    auto e = upper_bound(prime.begin(), prime.end(), end);
    cout << "[" << start << ", " << end << "]: ";
    int cnt = 0;
    for(auto idx = s; idx != e; idx++) {
        cout << *idx << ", ";
        cnt++;
    }
    cout << endl;
    cout << "count: " << cnt << endl;
}

#define maxn 10000000

set <int> p_count[maxn+1];
int ans_count[maxn+1][10] = {0};

int main() {
    int t;
    Sieve sieve(maxn);
    sieve.sieve();
    // memset(count, 0, sizeof(count));
    // count[1] = 0;
    int max_p = 0;
    memset(ans_count, 0, sizeof(ans_count));
    p_count[1].clear();
    ans_count[1][0] = 1;
    clock_t start = clock(), end;
    for(int i = 2; i <= maxn; i++) {
        int temp = i;
        p_count[i].clear();
        if(binary_search(sieve.prime.begin(), sieve.prime.end(), i)) {
            p_count[i].insert(i);
        } else {
            for(size_t j = 0; j < sieve.prime.size() && temp != 1; j++) {
                int p_f = sieve.prime[j];
                bool flag = false;
                bool is = false;
                while(temp % p_f == 0 && !flag) {
                    temp /= p_f;
                    is = true;
                    if(p_count[temp].size() != 0) {
                        flag = true;
                        if(p_count[temp].find(p_f) == p_count[temp].end()) {
                            p_count[i].insert(p_f);
                        }
                        for(auto k: p_count[temp]) {
                            p_count[i].insert(k);
                        }
                    }
                }
                if(flag) {
                    break;
                }
                if(is) {
                    p_count[i].insert(p_f);
                }
            }
        }
        // cout << i << ' ' << p_count[i].size() << endl;
        for(int b = 0; b <= 10; b++) {
            ans_count[i][b] = ans_count[i-1][b];
        }
        ans_count[i][p_count[i].size()]++;
        max_p = max(max_p, (int) p_count[i].size());
        /*if(i % 1000000 == 0) {
            end = clock();
            cout << "time: " << (end - start) / 1000. << " ms." << endl;
            start = clock();
            cout << max_p << endl;
        }*/
    }
    // cout << "done" << endl;

    cin >> t;
    for(int c = 1; c <= t; c++) {
        int a, b, k;
        cin >> a >> b >> k;
        int ans = 0;
        if(k >= 9) ans = 0;
        else ans = ans_count[b][k] - ans_count[a-1][k];
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
}
