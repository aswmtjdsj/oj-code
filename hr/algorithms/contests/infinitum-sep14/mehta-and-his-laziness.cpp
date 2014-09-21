#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int prime[100000];
int cnt;
bool is_prime[1000005];

void sieve() {
    cnt = 0;
    prime[cnt++] = 2;
    memset(is_prime, true, sizeof(is_prime));
    for(int i = 3; i < 1000000; i += 2) {
        if(is_prime[i]) {
            prime[cnt++] = i;
            for(int j = i * 3; j < 1000000; j += i * 2) {
                is_prime[j] = false;
            }
        }
    }
}
inline int gcd(int a, int b) {
    return b == 0? a : gcd(b, a % b);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    sieve();
    /*for(int i = 0; i < 100; i++) {
     *         cout << prime[i] << endl;
     *             }*/
    int t;
    cin >> t;
    while(t--) {
        int x, n;
        cin >> x;
        n = x;
        int a = 0, b = 0;
        map <int, int> M;
        for(int i = 0; i < cnt; i++) {
            if(prime[i] > n || n == 1) break;
            while(n % prime[i] == 0) {
                n /= prime[i];
                if(M.find(prime[i]) == M.end()) M[prime[i]] = 1;
                else M[prime[i]]++;
            }
        }
        b = 1;
        int p = 0, q = 1;
        for(auto i: M) {
            b *= i.second + 1;
            cout << i.first << ": " << i.second << endl;
            if(i.first % 2 == 0) {
                p = i.second / 2;
            }
            else {
                q *= (i.second / 2) + 1;
            }
        }
        a = p * q;
        a = (a < 0)?0: a;
        b -= 1;

        if(ceil(sqrt(x)) * ceil(sqrt(x)) == x && x % 2 == 0) a--;

        if(a != 0) {
            int g = gcd(a, b);
            cout << a / g << "/" << b / g << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    return 0;
}
