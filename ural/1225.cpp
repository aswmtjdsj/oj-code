#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    long long r[50] = {0}, w[50] = {0}, rb[50] = {0}, wb[50] = {0};
    r[1] = w[1] = 1;
    rb[1] = wb[1] = 0;
    for(int i = 2; i <= 45; i++) {
        r[i] = wb[i-1] + w[i-1];
        w[i] = rb[i-1] + r[i-1];
        rb[i] = r[i-1];
        wb[i] = w[i-1];
    }
    int n;
    while(cin >> n) {
        cout << r[n] + w[n] << endl;
    }
    return 0;
}
