#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++) {
        int n, a, b;
        cin >> n >> a >> b;
        set <int> s;
        for(int i = 0; i < n; i++) {
            s.insert(i * a + (n - 1 - i) * b);
        }
        for(auto i: s) {
            cout << i << ' ';
        }cout << endl;
    }
    return 0;
}

