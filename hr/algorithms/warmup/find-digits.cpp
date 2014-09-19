#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
    cin >> a;
    int b = a;
    int cnt = 0;
    while(b != 0) {
        int t = b % 10;
        if(t != 0 && a % t == 0) cnt++;
        b /= 10;
    }
    cout << cnt << endl;
    }
    return 0;
}
