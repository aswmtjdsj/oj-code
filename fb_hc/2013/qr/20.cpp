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
    char str[505];
    cin.getline( str, 505);
    for( int i = 0; i < m; i++) {
        map < char, int> M;
        cin.getline( str, 505);
        int l = strlen( str );
        int score = 26;
        for(int j = 0;j < l; j++) {
            if( !isalpha(str[j])) continue;
            if( isupper( str[j] )) {
                str[j] = tolower( str[j] );
            }
            M[ str[j] ] ++;
        }
        VI v;
        for( map<char,int>::iterator idx = M.begin(); idx != M.end(); idx++) {
            v.PB( idx->second );
        }
        sort( v.begin(), v.end());
        int sum = 0;
        for( VI::reverse_iterator idj = v.rbegin(); idj != v.rend(); idj++) {
            sum += (*idj) * score;
            score--;
        }
        printf("Case #%d: %d\n", i + 1, sum);
    }
}
