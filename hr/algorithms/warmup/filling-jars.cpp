#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    long double ans = 0.;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        ans += (long double)(b - a + 1) * (long double) k / (long double) n;
    }
    cout << (long long)floor(ans) << endl;
    return 0;
}

