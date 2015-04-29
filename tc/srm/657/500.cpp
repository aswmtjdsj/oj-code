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
}

long long modp(long long a, int p, long long mod) {
    long long w = 1;
	while(p > 0) {
		if(p & 1) {
			w = (w * a) % mod;
        }
		a = (a * a) % mod;
		p >>= 1;
	}
	return w;
}

class PolynomialGCD {
	public:
        // the solution is
        // for any prime divisor p
        // in x ^ d[0] * (x - p) ^ d[p] * (x - 2 * p) ^ d[2 * p] ...
        //    (x - 1) ^ d[1] * (x - p - 1) ^ d[p+1] * (x - 2 * p - 1) ^ d[2 * p + 1] ...
        //    ....
        //    at least one item can be divided by p
        //    so we try to find the minimum degree (p ^ deg) among all these items
        //    (which means we group the original formula into p groups, according to modulo (% p))
        //    the minimum degree should consider not only p, but p ^ 2, p ^ 3 ....
        //    in continuous form, using the quick method is okay, like said below
        //    but in non-continuous form, recursive method is the correct way
        //
        //    by the way, prime divisors don't affect each other
        int gao(const string & s, int p) {
            int ret = 100000;
            int n = s.size();
            if(p > n) return 0; // why this, because product of n continuous numbers can definitely be divided by n, if any of them has degree 0, then the minimum degree would be 0
            // that's why when p <= n, there should always be some reasonable degree
            // and if p > n, you cannot guarantee any degree is reasonable
            for(int i = 0; i < p; i++) { // different from prime divisor decomposition of a factorial number, here the adjacent divisors may be non-continuous
                string ns = ""; // so instead using formula, floor(deg / p) + floor(deg / p ^ 2) + ....
                int temp = 0; // we use recursive method to acquire adjacent divisors, and get the sub degree 
                for(int j = i; j < n; j += p) {
                    ns.PB(s[j]);
                    temp += s[j] - '0';
                }
                temp += gao(ns, p);

                ret = min(temp, ret);
            }
            return ret;
        }

        int gcd(string s) {
            Sieve sieve(10000);
            sieve.sieve();

            long long ans = 1ll;
            const long long mod = 1000000007ll;

            for(auto p: sieve.prime) {
                ans = (ans * modp(p, gao(s, p), mod)) % mod;
            }

            return ans;
        }
};

int main() {
    PolynomialGCD a;
    cout << a.gcd("111") << endl;
    cout << a.gcd("2014") << endl;
    cout << a.gcd("31415926535") << endl;
}
