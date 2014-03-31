/*
 * POJ 2739 Sum of Consecutive Prime Numbers
 * coded by BUPT-aswmtjdsj@BSW
 * time:2010-09-06
 * @915
 * */
/*
 * OEIS - TABLE
 * */
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
typedef long long ll;
const double eps=1e-7;
const ll MAX=1<<30;
int main()
{
    int a[10001] = {0,0,1,1,0,2,0,1,1,0,1,1,1,1,0,1,0,2,1,1,0,0,0,2,1,0,1,0,1,1,1,2,0,0,0,0,2,1,0,1,0,3,1,1,0,0,0,1,1,1,0,0,1,2,0,0,1,0,1,2,2,1,0,0,0,0,0,2,1,0,0,2,2,1,0,1,0,1,1,1,0,0,0,3,1,0,0,0,1,1,2,0,0,0,0,1,0,2,1,0,2,2,1,1,0,0,0,1,0,2,0,0,2,1,0,0,0,0,0,2,2,1,0,0,1,0,0,2,1,1,0,2,1,0,0,0,0,1,2,2,0,0,0,2,1,0,0,0,0,1,1,1,2,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,2,0,0,0,0,0,1,2,2,0,0,1,0,1,2,0,0,0,1,1,1,0,1,0,3,1,3,0,0,1,0,2,0,0,0,0,0,2,2,0,0,0,0,1,0,0,0,1,2,1,3,0,0,0,1,2,1,0,0,0,2,0,1,1,0,1,1,3,1,0,1,0,0,0,0,0,0,0,3,1,1,0,0,0,1,2,0,0,0,0,2,1,0,0,0,1,2,1,2,1,0,0,0,2,1,0,1,1,3,0,1,0,0,0,3,1,0,1,0,0,1,0,0,0,0,0,0,2,1,0,0,2,0,1,1,1,0,0,5,0,1,0,0,0,1,1,1,1,0,0,2,1,0,1,0,1,1,2,2,0,0,0,0,0,1,0,0,3,1,0,0,0,0,0,1,1,2,0,1,1,2,0,0,0,0,1,1,1,0,0,1,1,0,0,1,0,0,1,3,2,2,0,0,1,0,0,2,0,1,1,1,2,0,0,0,0,1,2,0,0,0,0,2,1,1,0,1,0,3,0,0,0,0,0,1,2,1,2,0,1,0,0,0,0,0,0,1,1,2,0,1,1,1,0,0,0,0,1,2,1,1,2,1,0,0,1,3,1,0,1,2,0,0,0,0,0,2,1,0,0,0,0,0,2,2,0,0,1,1,2,2,0,0,0,1,1,0,0,1,1,2,1,0,0,0,0,2,2,0,0,0,1,0,0,2,0,0,0,3,2,1,0,0,1,1,0,2,0,1,0,2,0,0,0,0,2,1,3,0,0,0,0,1,0,1,0,1,1,1,1,2,0,0,0,1,0,0,0,0,1,2,1,0,0,0,0,1,2,1,0,0,0,0,1,1,1,0,0,2,2,1,0,0,1,1,2,2,0,0,1,2,1,1,1,0,1,1,0,1,0,0,0,0,2,1,0,0,1,2,1,1,0,0,0,2,0,1,0,0,0,3,1,0,1,0,1,1,1,1,0,0,0,0,1,2,0,0,0,1,1,1,0,0,0,2,1,1,2,0,1,0,1,1,0,0,0,1,2,2,0,1,1,2,1,1,1,1,0,1,0,1,0,0,0,2,1,0,0,0,0,1,1,0,0,0,0,2,3,2,1,0,0,0,0,0,1,0,0,1,0,1,0,0,0,2,0,2,0,0,2,2,2,0,0,0,0,2,1,2,0,0,0,1,2,0,0,0,1,2,2,0,0,0,0,2,0,1,1,0,2,1,2,0,0,0,0,2,0,1,0,0,2,1,1,1,0,0,0,1,2,3,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,0,0,1,2,0,1,0,1,2,2,0,0,1,0,1,1,0,1,1,1,2,0,0,0,0,1,2,1,0,0,0,0,2,2,0,2,0,2,0,0,0,0,1,2,1,0,1,0,1,3,0,0,0,0,0,1,1,2,0,0,0,0,1,1,0,0,0,1,1,1,1,0,0,2,1,2,1,0,0,2,2,0,0,0,0,2,1,2,0,0,0,0,2,0,0,0,0,0,1,1,0,0,0,3,0,1,1,0,0,5,3,0,0,0,0,1,1,0,2,0,1,0,0,1,0,0,1,2,1,3,0,0,1,1,1,0,1,1,1,0,0,0,1,0,0,0,1,0,0,0,0,2,1,1,0,0,0,2,2,0,0,0,0,1,1,1,0,0,1,1,1,0,1,0,2,2,1,3,0,0,0,1,1,1,0,0,0,3,1,0,0,0,2,2,0,0,0,0,0,2,1,0,0,0,1,0,2,3,0,1,2,0,2,1,0,0,0,1,0,0,0,0,0,2,1,1,0,0,0,3,0,1,0,0,1,0,3,3,0,0,0,0,0,1,0,0,0,1,2,0,0,0,0,0,1,1,0,0,3,1,0,1,0,0,0,2,1,1,0,1,0,2,1,1,0,0,1,1,2,2,0,0,0,0,0,1,2,0,0,2,1,0,0,0,0,2,1,1,0,0,1,1,1,1,1,0,3,3,0,2,1,0,0,2,0,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,2,0,0,1,1,1,1,1,1,1,0,0,0,1,1,3,0,0,0,2,3,0,0,0,0,1,0,0,1,0,2,1,0,1,0,1,2,0,0,2,0,0,0,0,0,1,0,0,1,2,1,2,0,0,0,2,2,0,0,0,1,0,0,0,1,0,0,4,2,2,1,0,1,0,0,1,0,1,0,2,4,0,0,0,0,2,0,2,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,3,0,0,0,0,1,2,2,0,0,1,0,1,1,1,0,0,0,0,1,1,1,0,0,2,2,2,1,0,1,1,0,1,1,1,0,2,1,0,0,0,0,2,1,1,0,0,0,0,3,1,0,0,0,0,2,0,0,0,0,2,1,2,2,1,0,1,1,0,0,0,0,2,0,0,1,0,1,1,1,1,0,0,0,2,2,0,0,0,1,1,1,1,1,2,0,3,1,1,1,0,0,1,1,1,0,0,1,0,0,1,1,0,1,1,0,2,0,0,0,1,0,0,0,1,2,3,0,1,0,0,0,1,4,2,1,0,0,0,0,1,0,0,1,1,1,0,1,0,1,1,0,1,0,0,0,1,0,0,0,0,0,2,2,2,0,0,1,1,0,0,0,0,1,3,2,0,1,0,1,4,0,1,0,1,0,1,1,0,1,0,0,0,1,3,0,0,0,0,1,0,0,0,0,1,3,0,0,1,1,0,0,1,0,0,1,1,1,1,0,0,1,2,1,1,0,0,0,2,0,0,0,0,2,0,1,2,0,0,0,1,2,1,0,0,0,3,1,0,0,0,0,3,0,2,0,0,1,0,1,1,0,0,1,1,2,1,0,0,0,1,0,2,1,0,0,1,2,0,0,0,0,0,2,1,1,0,0,2,0,1,2,1,2,1,2,2,1,1,0,2,1,1,0,0,0,3,2,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,3,0,0,0,0,1,0,1,1,1,0,0,3,3,0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,0,1,1,2,0,0,1,0,2,1,0,0,2,3,0,1,0,0,0,2,2,1,0,0,1,1,0,1,0,0,2,1,0,0,1,0,1,0,0,2,0,0,0,2,1,1,1,0,2,0,0,2,0,1,0,0,2,1,0,0,0,2,0,1,0,0,1,3,0,2,0,1,0,2,0,0,0,0,1,1,2,2,1,0,0,0,2,1,0,0,0,0,1,0,0,0,1,2,0,0,0,0,0,3,2,2,0,0,0,0,4,0,0,0,1,0,1,1,0,0,1,0,1,1,0,0,0,2,1,1,1,0,0,1,1,0,0,1,0,1,1,1,0,0,0,0,0,2,0,1,0,2,2,1,0,0,0,1,0,1,0,0,0,2,2,0,0,1,1,1,3,0,2,1,0,2,2,2,1,0,1,1,2,1,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,1,2,2,0,0,1,1,2,3,0,0,0,1,2,1,0,0,0,0,2,0,0,0,0,0,1,0,0,0,1,2,0,1,0,1,0,0,0,1,1,0,1,2,3,1,0,2,0,3,1,0,0,0,0,1,1,3,1,0,0,0,0,1,0,0,2,1,0,0,0,0,0,0,1,0,0,1,0,3,1,0,0,0,1,1,2,2,0,0,1,0,1,1,0,0,0,1,0,1,0,0,2,1,2,2,0,2,0,0,4,0,0,0,0,2,0,2,0,0,0,0,1,2,0,1,1,1,2,2,0,0,0,1,1,1,0,0,0,0,0,0,0,0,2,2,0,2,0,0,0,2,1,0,0,0,2,3,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,1,0,1,1,0,0,1,0,2,0,0,0,2,2,0,1,0,0,0,1,1,0,1,0,0,1,0,1,0,1,2,2,0,4,0,0,0,0,3,0,0,1,2,0,0,0,0,0,0,2,0,0,0,1,0,2,2,0,0,0,1,2,2,1,1,1,0,0,1,2,2,0,0,0,0,2,1,1,0,1,1,2,0,0,2,1,0,0,1,0,0,0,0,3,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,3,0,1,1,0,2,1,1,1,0,0,1,1,3,0,0,0,0,1,1,1,0,0,1,1,1,2,0,0,1,0,0,0,0,0,0,1,1,1,0,0,1,2,0,0,1,0,0,1,2,1,0,1,0,2,0,2,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,3,2,1,0,0,0,2,0,0,1,0,2,3,2,2,0,0,1,1,0,0,0,0,1,1,2,1,0,1,0,2,0,1,2,0,0,0,0,1,0,0,0,2,1,2,1,0,1,1,1,0,0,0,1,1,0,2,1,0,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,3,1,0,0,1,1,0,0,0,0,1,1,0,1,0,1,1,0,0,0,2,1,0,1,3,0,0,1,1,1,2,0,0,1,2,1,1,0,0,1,0,0,2,0,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,2,1,0,0,1,1,0,1,0,1,1,2,2,1,1,0,0,1,0,0,1,1,0,0,2,0,0,1,3,0,2,0,1,0,2,1,1,1,0,0,0,2,1,0,0,0,0,1,2,1,0,0,0,1,1,0,0,1,2,1,0,0,1,0,3,3,1,0,1,1,1,1,2,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,2,1,1,0,0,0,1,1,0,1,0,0,1,0,1,0,0,0,0,2,2,0,1,1,2,1,0,0,0,1,3,1,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,2,1,1,1,0,0,2,1,1,2,0,1,1,3,0,1,0,0,1,4,1,0,0,0,1,2,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,3,0,1,1,0,1,2,1,1,0,1,0,0,1,0,1,0,0,1,3,1,1,0,1,2,0,2,0,1,0,1,1,0,1,0,1,0,0,2,1,0,0,2,2,1,0,0,0,0,1,1,1,0,0,1,0,1,1,1,0,2,1,1,2,0,0,0,2,1,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,1,1,0,0,0,3,2,1,0,0,0,0,1,0,0,0,0,1,0,2,0,1,0,0,1,1,0,0,1,1,0,2,2,0,1,0,0,1,0,0,0,2,0,0,0,0,1,2,1,1,1,0,1,2,3,1,0,0,0,0,2,1,1,0,0,2,0,1,0,0,1,2,1,0,0,0,1,3,1,0,2,0,2,0,3,2,1,0,0,1,0,1,0,0,0,1,1,1,0,0,1,2,1,1,0,0,0,1,1,0,2,0,0,0,1,1,1,0,1,2,0,0,0,0,1,1,0,0,0,0,1,2,2,0,0,0,0,0,1,2,0,1,0,0,1,4,1,0,0,1,1,1,0,0,1,2,1,1,0,0,0,1,0,0,0,0,0,0,3,1,0,1,0,2,1,2,0,0,0,0,1,1,0,0,1,1,1,4,1,0,0,1,1,0,0,0,1,1,1,0,0,1,0,1,3,1,0,0,0,1,1,2,0,0,0,1,1,2,0,0,0,0,1,0,0,0,1,1,1,3,0,0,0,1,0,2,0,0,2,1,1,1,0,1,0,2,0,1,0,0,2,1,2,0,0,1,0,2,1,1,0,0,2,1,1,1,0,0,1,1,0,1,0,0,1,3,0,0,1,0,0,0,1,2,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,1,2,2,0,1,1,1,0,2,1,1,0,0,2,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,3,0,1,0,2,2,1,0,1,0,1,1,1,1,1,0,0,0,0,4,1,0,0,0,1,1,0,1,1,0,4,2,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,1,3,1,1,0,1,2,0,0,0,0,0,3,1,0,1,0,0,1,2,1,0,0,0,2,1,1,2,0,2,1,1,1,1,0,0,0,1,1,0,1,2,3,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,1,0,0,0,0,1,2,2,0,0,0,3,2,0,0,0,0,3,1,1,1,0,2,1,1,2,0,0,0,0,1,0,0,0,1,0,1,0,1,1,0,2,0,0,2,0,1,1,1,1,0,1,0,2,1,1,0,0,0,1,0,1,0,0,3,1,1,1,0,0,0,1,0,2,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1,1,0,3,2,1,1,2,0,0,0,0,2,0,1,1,1,0,0,1,1,0,0,1,0,1,1,1,0,1,0,1,2,2,1,1,2,1,1,2,2,0,0,1,0,1,0,0,1,2,0,2,0,2,0,1,1,0,1,0,1,0,1,0,1,0,0,0,1,1,0,0,1,0,0,1,0,0,1,2,0,0,0,0,0,3,1,3,0,0,0,1,2,0,0,1,0,0,0,1,0,0,0,3,1,1,0,0,0,0,1,1,0,0,0,0,2,1,0,0,2,0,0,0,1,0,0,1,2,1,0,0,3,3,1,1,0,0,0,0,1,1,0,0,0,1,1,3,0,0,0,1,0,1,1,1,0,2,1,1,0,1,0,0,4,0,0,0,0,1,1,0,0,0,2,2,0,0,0,0,0,1,1,1,0,2,0,1,1,1,0,1,0,0,0,1,0,0,3,0,0,0,0,1,2,0,1,0,0,1,0,0,1,2,1,1,2,2,1,2,0,0,1,2,1,1,0,2,0,3,4,0,2,0,0,0,0,2,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,1,0,0,2,1,1,0,0,0,2,3,1,0,0,1,1,0,1,0,1,2,0,0,2,0,0,1,0,2,1,1,2,0,2,1,0,0,0,0,2,2,1,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,3,2,2,1,0,0,2,0,0,0,1,0,1,0,1,2,0,0,0,0,0,0,1,1,1,0,1,0,0,1,0,2,0,0,0,0,0,2,1,0,1,0,4,2,2,0,0,0,0,2,3,0,0,1,1,0,2,0,0,1,1,3,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,2,1,0,0,0,0,2,0,1,2,0,1,1,1,0,0,0,1,2,0,2,1,1,1,0,1,1,0,0,0,0,0,2,2,0,0,2,2,1,1,0,1,0,2,0,2,0,0,1,0,1,1,0,0,1,0,1,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,1,1,0,2,2,0,0,3,1,0,0,0,0,1,0,1,2,0,1,2,1,3,0,0,0,0,0,0,1,0,0,2,2,1,0,0,0,2,1,0,1,0,1,2,0,2,0,1,1,0,0,2,0,0,1,0,0,0,1,0,0,1,1,1,1,2,0,0,2,0,0,0,0,0,1,2,0,0,0,0,2,0,1,0,1,2,0,1,0,0,0,2,3,1,2,1,0,2,0,0,0,1,0,0,1,2,0,0,1,0,0,2,0,0,1,0,2,1,1,0,0,3,0,0,0,1,0,1,2,0,0,1,1,1,2,2,0,1,2,0,2,2,1,0,0,0,0,2,0,0,0,2,0,0,0,0,0,1,2,0,1,0,1,2,0,1,0,0,0,0,1,0,1,1,0,3,0,1,0,0,0,1,1,0,0,0,0,2,0,0,0,1,1,0,0,2,0,2,2,0,2,2,1,0,1,2,1,1,0,0,1,0,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,3,2,2,0,0,1,0,1,0,0,0,0,2,2,0,0,0,0,1,1,2,1,0,0,2,1,0,0,4,1,1,2,0,0,0,2,0,0,1,0,0,1,1,1,0,0,0,2,0,0,1,0,1,1,1,1,0,1,0,1,0,2,0,0,3,0,0,2,0,0,0,1,1,1,0,0,0,2,1,1,0,0,2,0,1,1,0,0,1,1,0,0,0,0,1,3,1,1,0,1,1,0,1,1,0,2,0,1,1,0,0,1,1,1,0,0,1,0,1,1,1,2,0,0,1,2,0,3,1,0,1,0,0,0,0,0,0,2,1,0,0,0,3,1,3,1,0,0,1,1,1,2,0,0,0,1,1,0,0,0,0,1,0,2,0,0,0,0,0,1,0,0,2,2,2,2,0,0,1,0,0,1,0,0,0,3,0,0,0,0,0,1,0,1,0,1,1,1,1,2,0,0,1,2,0,1,0,0,1,1,1,2,1,0,0,0,0,1,0,0,1,2,1,1,0,1,1,1,2,0,3,0,0,0,0,0,0,0,0,0,1,3,0,0,2,2,0,0,0,0,0,1,0,2,2,0,0,0,1,0,0,1,0,2,1,0,0,0,0,0,2,1,1,0,1,1,2,1,0,1,1,1,0,1,1,1,1,1,2,0,0,3,1,1,0,1,1,1,1,1,1,1,2,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,2,0,0,0,1,1,0,1,0,0,1,1,1,3,0,1,0,2,3,0,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,2,0,0,1,0,3,1,3,0,0,0,3,1,2,0,1,0,0,1,0,0,0,0,1,3,2,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,2,0,1,0,0,1,1,2,1,1,0,0,2,0,0,0,0,1,1,0,0,0,0,2,1,2,2,1,0,0,2,0,2,1,0,0,0,1,0,0,0,0,1,1,1,1,1,1,0,2,2,0,0,1,1,1,0,0,0,1,0,1,2,0,0,0,0,0,0,0,1,0,1,4,1,0,0,0,1,0,0,1,0,2,2,0,0,0,0,0,3,1,1,0,1,1,0,2,1,0,2,0,2,2,2,1,0,0,0,0,2,0,0,0,2,2,2,1,0,0,1,0,2,0,0,1,2,0,0,0,0,0,2,1,1,0,0,1,1,0,1,1,0,0,2,0,1,0,0,0,0,2,1,3,0,0,1,2,0,2,1,0,2,1,0,0,0,0,0,1,2,0,0,0,1,1,0,0,0,0,1,0,2,1,0,0,0,1,0,0,0,1,1,1,0,0,0,0,2,1,1,1,1,1,1,0,1,0,0,0,3,1,1,2,0,0,0,1,0,0,0,0,1,2,1,0,0,0,1,0,2,0,1,0,3,1,3,1,0,0,0,1,1,2,1,0,1,0,0,0,0,0,0,2,0,1,1,1,0,0,2,0,0,0,2,1,0,1,0,0,2,0,0,0,0,1,0,0,1,1,0,0,1,2,2,1,0,0,0,1,0,0,1,1,2,0,2,0,0,1,0,2,0,0,0,0,2,2,3,1,0,1,0,0,1,0,2,1,0,0,1,2,0,1,3,1,0,0,1,0,2,2,2,0,0,0,1,2,0,0,0,0,2,0,0,0,0,1,0,2,0,2,1,0,2,1,1,1,0,0,1,1,0,0,0,0,2,1,0,0,0,0,0,0,2,0,1,2,0,1,3,0,0,0,0,1,1,0,0,0,1,1,2,2,0,1,1,0,0,0,0,0,1,0,0,1,1,0,2,1,0,0,0,0,0,1,0,0,1,0,1,1,3,0,0,0,2,3,0,1,1,0,1,1,2,0,0,1,2,1,1,1,0,0,0,0,0,0,0,0,1,2,0,1,0,0,1,1,0,0,0,0,0,1,1,0,0,1,0,1,3,1,0,0,1,1,3,0,0,1,1,0,0,0,0,1,2,0,0,2,0,1,0,2,2,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,3,2,2,1,0,0,1,3,1,0,0,0,1,2,2,0,1,0,0,1,1,0,1,1,2,0,1,0,0,1,0,1,1,0,1,1,2,0,0,0,1,0,2,1,1,0,0,0,0,0,0,1,0,0,3,0,0,0,0,2,2,1,1,0,0,1,1,1,0,0,1,2,0,1,1,0,0,1,1,1,1,0,0,0,1,0,1,0,0,0,0,3,2,0,0,1,2,0,0,2,1,0,0,0,0,0,1,0,3,1,0,2,0,1,2,0,0,0,0,1,0,1,3,0,0,1,2,1,1,0,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,2,1,0,1,0,1,1,2,0,0,1,1,2,1,0,0,2,1,0,1,1,0,0,1,1,0,0,0,1,1,0,1,0,1,1,3,0,0,0,0,0,0,1,2,1,0,2,1,1,1,0,1,1,0,2,0,0,0,1,2,0,1,0,0,0,1,1,1,0,1,0,2,1,0,0,0,1,0,2,1,1,0,0,2,0,2,0,0,0,2,0,0,1,0,0,2,2,1,2,1,2,2,0,1,1,0,3,2,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,2,4,2,0,0,0,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,2,2,0,1,0,0,1,3,1,1,0,0,0,1,4,0,0,0,0,0,1,0,0,1,2,0,3,0,0,1,1,0,0,1,0,0,1,1,0,0,0,0,0,0,2,1,0,0,1,1,2,1,0,0,0,1,3,0,0,0,1,0,0,0,0,1,3,0,1,0,0,2,0,0,1,1,3,1,3,2,1,1,0,0,0,1,2,0,0,0,0,0,1,0,0,0,2,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0,4,0,0,1,0,3,0,0,0,1,2,1,1,0,0,2,0,1,1,0,0,0,2,2,0,0,1,0,1,2,2,0,0,1,1,0,0,1,0,1,1,4,1,0,0,0,2,0,2,1,0,1,0,2,1,0,2,0,2,2,2,0,2,0,0,0,0,0,0,1,1,0,0,0,0,0,2,1,0,0,0,0,0,2,1,0,0,0,1,1,1,1,0,0,4,1,0,0,0,0,1,2,1,0,1,0,0,0,1,0,1,1,1,0,1,1,0,0,2,3,1,0,0,0,0,1,0,0,0,2,1,2,1,1,1,0,0,0,2,1,1,0,0,1,1,0,0,0,1,3,1,0,1,0,0,0,1,0,1,0,0,1,2,0,0,0,0,2,1,0,0,2,1,0,2,0,1,0,1,1,0,0,2,0,0,0,0,0,0,0,0,3,0,0,1,3,1,0,0,0,1,0,3,2,1,0,1,0,1,0,0,0,0,1,2,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,2,1,2,2,0,0,2,1,2,0,1,0,0,2,1,1,0,0,1,2,0,0,0,0,0,0,2,2,0,1,0,0,2,1,0,0,0,0,1,1,0,1,1,2,1,0,0,2,0,0,1,1,0,0,1,1,2,2,2,0,1,2,0,0,0,0,0,0,0,1,1,1,1,0,0,2,0,0,0,1,1,1,0,0,0,2,2,1,0,0,0,1,1,0,0,0,0,1,1,0,2,0,2,2,0,2,0,0,2,1,0,1,1,2,1,0,1,1,0,0,1,0,0,2,0,0,1,1,1,1,0,2,0,1,1,0,0,0,1,1,3,1,1,0,0,1,1,2,0,0,1,1,1,1,0,0,1,0,1,2,0,0,0,1,1,0,0,0,0,0,2,0,0,0,1,1,0,1,0,1,0,3,1,0,0,0,0,1,1,1,0,0,1,2,0,0,0,0,0,1,2,1,0,1,0,2,0,0,0,1,1,2,2,1,0,0,0,2,1,0,0,0,1,1,2,0,0,0,1,2,2,2,0,0,0,0,0,1,1,0,1,2,0,0,0,0,0,1,0,1,0,1,0,0,2,0,0,1,2,3,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,3,2,1,0,1,2,1,0,1,0,1,0,1,3,2,0,0,2,0,0,1,1,1,0,1,1,1,0,0,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0,1,2,0,0,0,0,0,0,1,0,2,1,2,0,0,2,2,2,2,0,0,0,1,0,0,0,0,2,1,1,2,0,0,0,1,0,1,0,0,1,2,1,1,0,0,0,2,1,1,0,1,0,0,0,0,0,0,1,2,2,1,0,1,1,1,0,0,0,0,1,0,0,3,1,0,0,0,1,1,0,1,1,2,1,0,0,1,1,1,1,2,1,0,1,0,2,0,2,1,0,2,1,0,0,0,1,2,1,1,0,1,0,1,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1,0,1,2,0,1,0,0,0,0,1,1,0,1,0,3,0,0,1,0,0,2,0,0,1,0,1,0,2,1,0,1,4,2,1,0,0,0,0,2,0,1,0,0,0,1,1,0,1,0,0,1,1,2,0,0,0,0,0,0,1,0,2,1,1,1,1,0,1,1,0,0,3,0,1,3,0,0,0,0,0,1,1,1,1,1,1,2,2,2,1,0,1,0,0,1,1,1,0,1,0,1,0,0,1,2,1,0,0,0,3,3,1,1,0,0,0,2,0,1,0,0,1,1,0,1,1,0,1,1,0,1,0,0,0,1,0,0,0,2,1,1,1,1,0,0,1,3,1,1,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,3,0,1,0,1,0,0,2,0,0,0,0,0,0,0,0,0,1,2,1,1,0,0,0,2,1,0,1,0,2,1,1,0,0,1,1,2,3,0,0,0,1,0,0,0,0,0,0,0,2,2,0,0,0,1,0,1,1,0,1,0,1,0,0,0,1,0,2,0,0,0,0,1,0,2,0,2,2,3,0,0,1,0,0,2,0,1,0,0,1,0,1,0,1,0,1,4,1,1,0,0,1,0,0,1,0,0,2,2,3,2,1,0,0,0,0,0,0,0,0,2,0,0,2,0,0,2,2,1,0,1,0,0,0,1,0,0,1,0,1,2,1,1,0,3,0,0,1,0,0,2,0,1,0,1,0,0,1,0,0,0,2,1,0,1,0,0,0,2,1,3,0,0,2,0,1,3,1,2,0,1,0,0,0,0,0,1,3,1,0,0,0,1,0,0,0,0,3,1,0,0,0,0,1,2,2,0,1,0,0,2,1,1,0,1,0,1,0,2,0,1,1,0,1,0,1,0,0,2,0,2,0,0,1,1,1,0,0,1,0,1,0,0,3,1,1,1,0,1,0,0,1,2,1,1,1,0,0,1,1,2,1,0,0,0,0,1,0,0,2,2,0,0,1,0,2,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,0,1,2,1,0,0,0,2,1,1,0,1,0,0,1,1,1,1,2,1,0,2,1,0,1,1,2,2,0,2,0,1,0,0,0,0,1,0,1,1,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,3,3,1,0,1,1,1,2,1,0,1,0,1,0,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,2,0,0,0,0,1,0,0,0,1,1,0,2,2,2,2,0,0,1,2,0,0,2,2,3,0,1,0,0,0,2,0,0,1,1,0,2,0,0,0,0,3,1,3,1,1,1,0,0,2,1,1,0,1,0,0,1,0,0,0,1,0,1,2,0,1,2,0,0,0,0,1,1,2,1,0,1,0,0,0,1,1,1,0,1,0,3,0,0,0,1,1,2,2,0,0,0,1,0,0,1,1,2,1,0,0,0,2,1,1,2,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,1,2,2,0,1,0,1,1,0,1,2,1,0,0,0,1,1,2,1,1,0,1,0,0,1,2,0,0,2,2,1,1,0,0,0,2,0,1,0,1,0,1,1,0,1,0,1,0,0,2,0,0,1,1,0,0,0,0,0,1,3,2,1,0,0,0,0,0,0,1,0,3,1,1,0,0,0,1,0,1,2,1,3,0,4,0,0,0,0,1,2,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,1,0,0,0,1,0,0,1,1,0,1,0,2,2,1,0,0,2,0,0,0,2,0,3,0,1,1,0,0,0,1,0,0,1,0,0,0,0,2,2,1,1,0,2,0,0,0,2,0,2,2,1,0,0,2,0,0,1,1,3,1,1,0,1,1,0,1,0,0,2,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,0,1,2,0,1,1,1,0,0,1,1,0,0,0,2,0,0,1,0,2,0,2,1,1,2,0,1,1,0,0,0,1,0,0,1,1,0,0,1,0,1,2,3,1,0,0,0,0,0,0,1,0,0,1,0,2,1,0,0,0,1,1,0,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,2,0,1,0,0,2,1,1,1,1,1,0,0,0,1,0,0,1,2,1,0,0,0,0,0,1,0,0,0,0,1,2,2,0,0,1,1,0,1,0,1,0,0,2,1,1,0,1,2,2,1,1,1,1,0,0,0,1,0,1,2,2,2,0,0,1,1,0,0,1,0,0,0,1,0,1,0,0,3,1,1,1,0,0,0,0,1,0,2,0,1,0,2,0,1,0,0,2,0,0,0,1,1,1,0,0,0,0,2,0,1,1,2,0,0,0,0,0,0,1,1,0,2,0,1,2,1,1,2,0,0,0,1,0,0,1,0,0,2,0,3,1,0,0,1,1,0,0,1,2,0,1,1,0,0,0,1,1,1,2,1,2,1,0,1,0,0,1,1,2,2,0,0,0,0,0,2,1,0,0,2,1,1,0,0,1,0,1,1,1,0,0,0,0,1,0,0,0,2,2,0,0,1,1,1,1,1,1,0,0,1,2,0,0,0,0,3,2,0,0,0,1,1,1,1,0,0,0,1,2,1,0,0,0,0,1,0,1,1,1,1,0,0,2,0,0,2,2,2,0,0,0,1,0,1,0,0,1,1,2,1,0,0,0,0,0,1,0,0,0,2,0,0,2,0,0,1,1,0,0,1,0,2,1,1,1,1,0,3,1,2,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,0,0,1,2,1,3,1,1,0,1,0,2,1,0,0,0,0,0,0,2,1,0,0,0,0,1,0,0,1,1,0,3,0,1,1,1,1,0,0,0,2,0,0,1,1,0,1,1,3,2,0,0,1,0,1,0,1,0,0,1,1,1,0,0,2,0,0,1,0,0,1,3,1,1,0,1,0,1,0,1,1,0,1,1,1,0,0,0,2,0,0,0,1,1,1,1,2,1,1,1,1,1,0,0,0,1,1,0,2,0,0,0,0,3,1,1,1,0,0,1,1,3,1,2,0,0,1,0,2,1,0,1,0,2,0,0,0,0,1,2,0,0,2,3,2,1,0,0,0,0,0,1,1,2,0,0,1,2,0,0,0,0,0,0,0,1,0,1,1,1,0,0,1,1,0,0,1,0,0,2,1,0,0,2,1,1,2,1,1,0,1,1,1,0,0,1,0,1,0,1,0,0,0,2,1,1,0,1,0,1,1,1,1,1,1,1,1,0,0,1,0,1,1,0,0,0,1,0,0,1,0,0,1,1,0,2,0,0,0,2,1,2,0,1,0,1,2,0,2,1,1,2,0,0,1,0,0,0,1,0,1,0,3,1,1,0,0,0,1,3,0,1,1,1,0,1,0,1,1,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,2,0,0,1,0,1,0,1,0,0,2,0,2,1,0,1,3,0,0,1,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1,2,1,2,1,0,0,2,0,2,2,1,0,0,0,1,0,0,0,0,2,0,1,0,0,1,0,0,2,1,0,1,1,1,0,0,0,1,1,0,0,1,0,0,0,0,2,0,1,0,1,0,0,1,0,0,1,2,2,1,0,2,0,0,0,0,1,0,2,3,2,2,0,2,1,0,1,3,3,1,0,1,0,0,0,0,0,1,2,1,0,0,1,2,0,1,0,0,0,0,1,0,0,0,2,1,2,0,0,0,0,4,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,1,3,1,0,0,0,1,0,1,0,2,1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,2,1,1,0,1,1,0,1,1,0,0,0,1,0,1,2,0,1,1,1,0,0,2,1,0,1,0,0,2,1,1,0,2,0,0,1,1,1,0,1,1,2,1,0,0,0,1,2,1,2,0,0,0,1,0,2,1,1,1,1,0,2,0,1,1,0,0,0,0,0,1,2,1,1,0,0,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,2,1,0,0,0,0,0,0,1,1,3,1,2,0,0,0,3,0,0,2,1,0,2,1,0,0,0,0,1,0,2,2,0,3,0,0,1,0,1,0,1,0,1,1,0,2,0,0,1,0,1,0,2,1,0,0,0,0,3,0,1,1,0,1,0,1,2,1,0,2,0,0,0,1,0,0,0,0,1,0,1,1,2,0,0,1,0,2,0,1,1,1,0,1,1,1,3,0,1,0,1,0,1,1,0,0,2,2,3,0,1,0,1,1,0,0,1,1,0,0,0,0,1,0,0,2,1,0,1,1,0,0,1,0,0,2,3,0,0,1,0,2,1,1,1,0,0,0,1,2,2,0,0,1,0,0,1,0,0,0,2,0,1,0,0,0,1,2,1,2,0,0,2,3,0,0,0,1,0,1,2,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,2,0,3,0,1,1,0,0,2,1,0,0,1,1,0,2,0,0,0,0,0,0,0,0,0,0,1,2,2,0,0,1,1,0,1,0,2,2,3,1,0,0,1,0,2,2,0,1,0,1,1,1,0,0,0,0,1,2,0,0,1,2,2,0,0,0,0,1,1,1,0,0,0,0,0,1,2,0,0,1,1,0,3,1,0,0,1,3,1,0,0,1,1,0,1,0,0,0,0,2,0,0,0,1,0,0,1,0,1,0,4,0,0,0,1,0,1,2,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,1,0,1,0,0,2,1,1,1,0,0,1,3,2,0,0,1,1,1,0,1,0,2,0,1,1,1,0,2,3,0,3,0,0,0,2,1,0,2,0,1,0,1,0,0,0,0,1,1,1,2,1,1,1,1,1,1,1,0,1,0,1,1,0,0,1,0,1,2,1,0,0,1,1,0,0,0,1,1,1,0,0,1,0,1,3,2,0,0,1,0,0,1,0,1,1,0,0,0,0,0,0,1,0,0,1,2,1,0,0,0,0,1,1,1,1,0,0,1,0,2,2,1,2,1,0,1,0,1,0,1,0,3,1,2,0,0,0,0,2,0,0,0,2,3,0,1,0,0,0,0,1,1,1,0,0,3,0,0,1,0,0,1,0,2,0,0,0,2,0,0,1,0,0,1,1,1,1,0,0,0,0,0,1,1,0,2,3,0,1,1,2,3,0,1,0,0,0,2,0,0,1,0,0,0,2,2,0,0,1,2,0,0,0,0,2,0,2,1,0,0,2,1,1,0,0,1,4,1,0,0,0,0,0,0,0,3,1,0,0,1,0,1,0,0,1,1,0,0,0,1,0,0,0,2,1,2,0,0,2,0,0,0,0,0,0,2,1,0,0,1,1,0,1,1,1,2,0,1,0,1,0,2,1,2,1,0,0,1,1,0,0,1,0,1,1,2,0,0,1,0,1,0,0,0,0,1,0,1,1,0,0,1,1,0,0,0,0,3,0,0,1,1,0,1,0,1,0,0,2,0,2,0,2,3,1,2,2,1,0,2,2,0,0,3,1,0,1,2,0,1,0,0,0,1,1,0,0,0,0,0,1,1,0,0,2,1,1,2,0,0,1,2,1,0,0,1,0,1,2,0,0,0,0,1,1,2,0,0,0,0,1,1,0,1,1,0,0,0,0,1,1,0,2,1,0,1,1,2,0,1,1,1,0,0,3,1,0,0,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,0,1,1,2,0,0,0,0,0,1,0,0,2,1,1,0,0,2,1,0,0,0,1,0,0,1,1,1,1,3,1,0,1,0,0,0,2,1,0,0,0,1,0,0,1,0,0,0,0,0,0,2,3,0,0,2,0,1,0,3,0,0,1,2,0,1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,0,0,1,0,0,0,1,2,0,0,0,2,2,0,1,1,0,1,1,3,1,0,2,0,1,0,2,2,0,0,1,1,0,0,1,1,0,0,0,0,0,1,1,2,0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,0,1,2,0,2,0,3,2,0,1,0,1,0,2,2,1,0,0,2,0,1,1,0,0,0,1,1,0,0,0,0,2,1,1,0,2,0,1,1,0,2,0,0,2,2,2,1,0,1,0,1,0,0,0,2,0,0,1,1,3,0,1,1,2,0,0,2,1,1,1,0,1,0,2,2,1,1,0,0,1,1,0,0,0,1,0,0,0,0,0,1,2,3,2,0,0,1,0,0,1,0,0,0,1,0,1,2,0,0,0,1,0,0,0,0,0,0,1,1,0,1,3,2,1,1,0,0,0,0,0,1,1,2,0,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1,0,0,1,0,1,0,3,2,2,1,2,0,2,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,0,2,1,1,1,0,0,3,0,0,2,1,1,2,1,2,1,0,0,2,2,1,0,1,1,1,2,1,1,0,0,0,0,1,2,0,0,0,0,0,0,1,0,1,0,1,1,2,0,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,2,1,0,2,0,0,0,1,0,0,1,3,1,0,2,0,2,0,0,0,1,0,0,0,0,0,0,1,2,1,0,1,0,2,1,0,0,0,1,0,0,0,0,1,1,1,1,0,1,0,1,0,1,1,0,0,1,2,0,0,0,1,0,1,0,1,1,0,2,4,2,1,0,0,0,1,0,1,0,1,1,1,0,0,1,1,1,1,0,2,0,0,0,1,3,0,0,0,0,2,0,1,2,0,0,0,0,0,1,1,1,2,1,1,2,1,0,3,0,0,1,0,0,2,1,0,1,0,2,1,0,0,1,1,1,1,0,2,2,1,0,2,1,2,0,2,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,2,1,0,1,0,3,0,1,0,0,1,2,0,0,1,1,2,1,1,1,1,0,1,2,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1,1,2,0,0,0,3,2,1,3,0,0,0,1,1,0,0,0,1,1,1,2,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,2,2,1,1,0,0,0,0,1,1,1,0,3,0,1,0,1,0,2,0,0,1,0,1,0,1,1,0,0,0,1,3,2,0,0,0,1,2,0,0,0,0,2,2,2,0,0,2,0,1,1,0,0,2,2,0,1,1,0,2,1,1,0,0,1,0,0,0,1,0,0,1,2,1,2,0,0,0,1,1,1,1,0,0,1,0,0,1,0,0,0,1,1,0,0,0,0,1,1,1,0,1,1,0,1,0,0,1,1,2,1,2,0,0,2,0,2,1,1,0,0,0,0,0,0,0,1,0,3,1,1,0,1,0,1,1,0,0,1,0,1,0,1,3,1,0,0,1,0,1,0,2,2,0,1,0,0,1,1,1,0,0,1,0,0,0,1,0,2,0,0,0,1,2,2,1,1,0,1,1,0,0,1,1,0,0,0,2,1,2,1,0,1,0,0,0,1,2,1,0,3,1,1,0,1,1,0,1,2,1,1,2,1,0,0,1,1,0,0,0,1,0,1,0,0,1,0,1,1,1,2,1,0,0,0,0,0,0,1,0,2,0,1,1,0,0,0,0,0,0,0,1,1,2,0,0,0,0,1,3,2,1,0,0,1,0,1,0,0,0,1,1,1,0,0,1,0,1,2,0,0,0,2,1,1,1,1,2,1,1,0,0,0,2,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,3,1,2,1,1,0,2,1,0,1,0,2,1,0,0,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,0,3,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,3,0,0,1,2,0,0,0,1,0,3,2,0,0,0,2,0,0,0,0,0,1,3,0,3,1,0,2,0,1,1,0,1,3,0,1,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,2,0,2,1,1,1,1,1,0,0,0,0,1,0,1,0,0,1,1,1,1,0,0,0,0,2,0,1,1,0,2,0,0,3,1,1,1,3,2,0,0,0,1,3,2,0,1,0,3,0,0,0,0,1,2,0,0,0,0,1,2,0,0,1,2,2,0,2,0,0,1,0,1,1,0,0,1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,1,1,1,0,1,3,0,1,1,0,2,1,0,2,1,1,0,1,0,1,0,1,1,2,0,2,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,3,0,0,0,0,0,2,0,0,2,0,1,3,0,0,1,1,2,1,0,2,1,1,1,1,0,1,0,3,0,0,0,1,0,0,0,1,1,0,2,0,0,0,1,0,0,1,1,0,1,1,0,1,2,0,1,1,0,0,3,0,1,0,1,0,2,2,2,0,1,0,0,0,0,0,0,0,0,0,1,1,0,2,2,1,1,1,0,0,0,1,0,0,2,0,2,1,2,0,0,2,0,0,1,0,1,1,0,1,0,0,0,0,2,1,1,0,0,0,0,0,0,0,0,1,1,2,0,1,0,2,1,1,2,0,1,2,1,0,0,0,1,0,1,0,0,0,0,0,1,0,2,1,0,1,1,0,1,0,0,0,1,3,0,0,0,0,0,1,2,0,0,1,1,1,1,0,0,0,1,1,0,0,1,3,1,1,1,0,0,1,1,0,1,0,0,1,1,0,0,0,1,2,1,2,2,0,0,0,2,1,0,0,1,0,1,0,1,0,0,1,2,0,2,0,0,0,1,1,0,0,0,1,1,0,0,2,0,0,1,1,1,0,0,1,2,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,0,3,1,1,3,1,0,1,1,0,1,0,1,1,3,0,1,0,0,1,1,1,0,0,1,2,1,2,1,1,0,0,1,2,2,0,0,0,1,1,2,1,0,1,1,1,2,1,0,0,0,1,0,0,1,2,0,0,2,0,0,0,2,0,1,0,0,0,0,1,0,0,0,0,1,0,2,0,0,0,1,0,3,1,0,1,0,2,0,1,2,0,0,0,0,2,1,1,1,2,0,0,0,0,2,0,1,0,0,0,1,1,1,0,1,0,1,1,0,0,0,0,0,3,2,0,0,0,1,0,2,0,1,1,1,1,0,0,0,1,0,0,1,2,0,2,2,0,1,1,0,1,0,1,1,1,0,0,2,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0};
    int n;
    while(scanf("%d",&n) != EOF && n)
    {
        printf("%d\n",a[n]);
    }
}
