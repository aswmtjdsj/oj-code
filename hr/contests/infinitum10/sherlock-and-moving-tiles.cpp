#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double s1, s2, l;
    int q;
    cin >> l >> s1 >> s2;
    if(s1 < s2) swap(s1, s2);
    cin >> q;
    while(q--) {
        double _q;
        cin >> _q;
        cout << fixed;
        cout << setprecision(8) << sqrt(2) * (l - sqrt(_q)) / (s1 - s2) << endl;
    }
    return 0;
}
