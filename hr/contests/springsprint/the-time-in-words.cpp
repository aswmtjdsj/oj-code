#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 5 : 00 five o' clock 
 * 5 : 01 one minute past five 
 * 5 : 10 ten minutes past five 
 * 5 : 30 half past five 
 * 5 : 40 twenty minutes to six 
 * 5 : 45 quarter to six 
 * 5 : 47 thirteen minutes to six 
 * 5 : 28 twenty eight minutes past five
 * */

char numbers[][15] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "forteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty"};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int h, m;
    cin >> h >> m;
    if(m == 0) {
        cout << numbers[h-1] << " o' clock" << endl;
    } else if(m < 15) {
        cout << numbers[m-1] << " minute" << (m==1?" ":"s ") << "past " << numbers[h-1] << endl;
    } else if(m == 15) {
        cout << "quarter past " << numbers[h-1] << endl;
    } else if(m < 30) {
        if(m < 20) {
            cout << numbers[m-1] << " minute" << (m==1?" ":"s ") << " past " << numbers[h-1] << endl;
        } else {
            cout << numbers[m/10 + 17];
            if(m % 10 != 0) {
                cout << " " << numbers[m%10 - 1];
            }
            cout << " minutes" << " past " << numbers[h-1] << endl;
        }
    } else if(m == 30) {
        cout << "half past " << numbers[h-1] << endl;
    } else {
        if(m == 45) {
            cout << "quarter to " << numbers[h] << endl;
        } else {
            m = 60 - m;
            if(m < 20) {
                cout << numbers[m-1] << " minute" << (m==1?" ":"s ") << "to " << numbers[h] << endl;
            } else {
                cout << numbers[m/10 + 17];
                if(m % 10 != 0) {
                    cout << " " << numbers[m%10 - 1];
                }
                cout << " minutes" << " to " << numbers[h] << endl;
            }
        }
    }
    return 0;
}

