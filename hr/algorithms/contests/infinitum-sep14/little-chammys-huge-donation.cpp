#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long fun(long long n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        long long l = 1, r = 1000000;
        while(l < r) {
            long long mid = (l + r) / 2;
            if(fun(mid) >= x) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        if(fun(l) > x) l--;
        cout << l << endl;
    }
    return 0;
}
