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
        int n;
        cin >> n;
        int five = -1, three = -1;
        for(int i = 0; i <= (n / 5); i++) {
            if((n - i * 5) % 3 == 0) {
                five = n - i * 5;
                three = i * 5;
                break;
            }
        }
        if(five == -1) {
            cout << -1 << endl;
        } else {
            for(int i = 0; i < five; i++) cout << 5;
            for(int i = 0; i < three; i++) cout << 3;
            cout << endl;
        }
    }
    return 0;
}

