/*
red->blue->white(3,4)
red->white(3,4)
white->blue->red(1,2)
white->red(1,2)

red[1] = 1
white[1] = 1
red-blue[1] = 0
white-blue[1] = 0

red[2] = white[1]
white[2] = red[1]
red-blue[2] = red[1]
white-blue[2] = white[1]

red[3] = white[2] + white-blue[2]
white[3] = red[2] + red-blue[2]
white-blue[3] = white[2]
red-blue[3] = red[2]
*/

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
