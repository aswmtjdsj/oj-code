#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
using namespace std;

#define len(x) (x).size()
#define PB push_back
#define VI vector<int> 
#define pii pair<int, int>
#define MP make_pair
typedef long long int64;

const int inf = ~0u >> 1;
const double eps = 1e-8;
const double pi = acos(-1.0);
int sgn(double x)
{
    return fabs(x) < eps ? 0:x < -eps?-1:1;
}
int main()
{
    int m;
    cin >> m;
    char str[102];
    cin.getline( str, 102 );
    for( int q = 1; q <= m; q++) {
        bool mark = true;
        int cnt = 0;
        cin.getline( str, 102 );
        int len = strlen( str );

        for( int i = 0; i < len; i++) {
            if( !islower(str[i]) && str[i] != ':' && str[i] != ' ' && str[i] != '(' && str[i] != ')') {
                mark = false;
            }
        }

        for( int i = 0; i < len; i++) {
            if( str[i] == '(') {
                cnt++;
            }
            if( str[i] == ')') {
                cnt--;
            }
            if( cnt < 0 ) {
                mark = false;
                break;
            }
        }
        if( cnt != 0) {
            mark = false;
        }

        if( !mark ) {
            for( int i = 0; i < len; i++) {
                if( str[i] == ':' ) {
                }
            }
            for( int i = 0; i < len; i++) {
                if( str[i] == '(') {
                    cnt++;
                }
                if( str[i] == ')') {
                    cnt--;
                }
                if( cnt < 0 ) {
                    mark = false;
                    break;
                }
            }
            if( cnt != 0) {
                mark = false;
            }
        }

        printf("Case #%d: %s\n", q, mark?"YES":"NO");
    }
}
