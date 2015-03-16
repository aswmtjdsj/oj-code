#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = (1 << 16);

bool is[maxn+1];

int primes[maxn];

int tot;

void sieve() {
    tot = 0;
    primes[tot++] = 2;
    fill(is, is + maxn+1, true);

    for(int i = 3; i <= maxn; i += 2) {
        if(is[i]) {
            primes[tot++] = i;
            for(int j = i * 2; j <= maxn; j += i) {
                is[j] = false;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    sieve();
    scanf("%d", &n);
    string _n = to_string(n);
    int od = 0;
    for(int i = 0; i < _n.size(); i++) {
        od += _n[i] - '0';
    }
    vector <int> factors;
    for(int i = 0; i <= sqrt(n); i++) {
        while(n % primes[i] == 0) {
            factors.push_back(primes[i]);
            n /= primes[i];
        }
    }
    if(n != 1) {
        factors.push_back(n);
    }
    int fd = 0;
    for(auto i: factors) {
        string _i = to_string(i);
        int temp = 0;
        for(int j = 0; j < _i.size(); j++) {
            temp += _i[j] - '0';
        }
        fd += temp;
    }
    if(fd == od) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
