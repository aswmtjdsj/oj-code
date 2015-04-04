/* base IO */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>

/* data structure */
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>

/* alrotihm and math */
#include <algorithm>
#include <random>
#include <cmath>

/* run-time */
#include <cstdlib>
#include <ctime>
#include <climits>

/* system dependent */
#include <sys/time.h>

using namespace std;

#define VI vector<int>
#define VD vector<double>
#define PII pair<int, int>
#define PDD pair<double, double>
#define PB push_back
#define MP make_pair
#define len(x) ((x).size())

const int inf = INT_MAX;
const long long inf_ll = 0x7f7f7f7f;
const double eps = 1e-8;

/*
 * 0 1 2
 * 3   4
 * 5 6 7
 */
const int bfs_dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int bfs_dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
 *   3  
 * 2   0
 *   1  
 */
const int dfs_dy[] = {0, 1, 0, -1};
const int dfs_dx[] = {1, 0, -1, 0};

PII dir[] = {make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)};
/* TC HEADER END */

long long Gcd(long long u, long long v) {
    if(u<v)
    {
        long long t=u; u=v; v=t;
    } 
    long long remainder;
    remainder = u % v;
    while(remainder)
    {
        u = v;
        v = remainder;
        remainder = u % v;
    }
    return v;
}

long long Lcm(long long u, long long v) {
    return u * v / Gcd(u, v);
}

int main() {
    long long n, s1, v1, s2, v2, t; 
    cin >> n >> v1 >> v2 >> s1 >> s2;
    // scanf("%I64d%I64d%I64d%I64d%I64d", &n, &s1, &v1, &s2, &v2);
    long long lcm=Lcm(s1, s2);
    long long temp=n/lcm;
    n=n%lcm;
    if(temp){ temp--; n+=lcm; } 
    long long sum=temp*(max(lcm/s1*v1, lcm/s2*v2));
    if(s1<s2){ t=s1, s1=s2, s2=t; t=v1, v1=v2, v2=t; } 
    long long maxnum=0; 
    for(int i=0; i<=n/s1; i++)
    {
        t=i*v1+(n-i*s1)/s2*v2; 
        if(t>maxnum)
            maxnum=t;
    }
    maxnum+=sum;
    cout << maxnum << endl;
}
