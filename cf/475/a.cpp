#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>

#include <string>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <list>
#include <vector>

#include <algorithm>
#include <complex>
using namespace std;

#define len(x) (x).size()
#define VI vector<int> 

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

template <class T>
inline T sqr(T x) { return x * x; }

const int inf = ~0u >> 1;
const double eps = 1e-8;
const double pi = acos(-1.0);

int sgn(double x) {
	return fabs(x) < eps ? 0:x < -eps?-1:1;
}

int main() {
    int n;
    cin >> n;
    int k[4] = {0};
    int cnt = 0;
    for(int i = n; i > 0; i--) {
        if(cnt==2 && k[cnt] != 0) {
            cnt++;
        }
        k[cnt++]++;
        cnt = cnt % 4;
    }
    printf("+------------------------+\n");
    for(int j = 0; j < 4; j++) {
        printf("|");
        if(j != 2) {
            for(int i = 0; i < 11; i++) {
                if(i < k[j])
                    printf("O.");
                else
                    printf("#.");
            }
            printf("|");
            if(j==0) {
                printf("D");
            }
            else {
                printf(".");
            }
            if(j==1) {
                printf("|\n");
            }
            else {
                printf("|)\n");
            }
        }
        else {
            if(k[j] == 1) {
                printf("O");
            }
            else {
                printf("#");
            }
            printf(".......................|\n");
        }
    }
    printf("+------------------------+\n");
}
