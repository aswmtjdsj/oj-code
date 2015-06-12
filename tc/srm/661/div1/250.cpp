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
    for(int x = 3; x < size; x += 2) {
        if(is_prime[x]) {
            prime[prime_count++] = x;
            assert(prime_count <= size);
            for(int j = x * 3; j < size; j += x) {
                is_prime[j] = false;
            }
        }
    }
    prime.resize(prime_count);
    // cout << "prime: " << prime.size() << endl;
}
int gcd(int a, int b) {
    return (b == 0)?a: gcd(b, a % b);
}

int lcm(int a, int b) {
    int c = gcd(a, b);
    return a / c * b;
}

class MissingLCM {
	public:
        int getMin(int N) {
            Sieve s(N + 1);
            s.sieve();
            int ans = N + 1;
            for(auto i: s.prime) {
                if(i < N + 1) {
                    for(long long temp = 1; temp < N + 1; temp *= (long long)i) {
                        if(temp * 2 > N) {
                            ans = max((long long)ans, temp * 2);
                        }
                    }
                }
            }
            return ans;
        }
};

int main() {
    MissingLCM a;
    int n;
    while(cin >> n) {
        cout << a.getMin(n) << endl;
    }
}
