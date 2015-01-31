#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++) {
        long long k;
        cin >> k;
        long long p = k / 2, q = k - p;

        cout << p * q << endl;
    }
    return 0;
}
