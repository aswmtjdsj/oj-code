#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

const char * pi_song = "31415926535897932384626433833";

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    string a;
    getline(cin, a);
    for(int i = 0; i < n; i++) {
        getline(cin, a);
        //cout << a << endl;
        int j = 0;
        istringstream b(a);
        string temp;
        bool flag = true;
        while(b >> temp) {
            if(temp.size() == (pi_song[j] - '0')) {
                j++;
            } else {
                flag = false;
            }
        }
        if(flag) {
            cout << "It's a pi song." << endl;
        } else {
            cout << "It's not a pi song." << endl;
        }
    }
    return 0;
}
