#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxnum = 500005;
int n, q;
int a[maxnum];
int sum[maxnum];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
        ans += abs(a[i]);
    }
    cout << "ans: " << ans << endl;
    sort(a, a+n);

    int neg = -1, zero = -1, pos = -1;
    for(int i = 0; i < n; i++) {
        if(neg == -1 && a[i] < 0) neg = i;
        if(zero == -1 && a[i] == 0) zero = i;
        if(pos == -1 && a[i] > 0) pos = i;
        if(i == 0) {
            sum[i] = a[i];
        } else {
            sum[i] = sum[i-1] + a[i];
        }
    }
    int neg_num = 0, zero_num = 0, pos_num = 0;
    if(neg != -1) {
        if(zero != -1) {
            neg_num = zero - neg;
        } else if(pos != -1) {
            neg_num = pos - neg;
        } else {
            neg_num = n;
        }
    }
    if(zero != -1) {
        if(pos != -1) {
            zero_num = pos - zero;
        } else {
            zero_num = n - zero;
        }
    }
    if(pos != -1) {
        pos_num = n - pos;
    }

    cin >> q;
    int acc = 0;

    for(int i = 0; i < q; i++) {
        int opt;
        scanf(" %d", &opt);
        acc += opt;
        if(acc == 0) {
            printf("%lld\n", ans);
        } else {
            long long temp = ans;
            if(acc < 0) {
                temp += -acc * (long long)(zero_num + neg_num);
                if(pos_num > 0) {
                    auto biu = upper_bound(a, a+n, -acc);
                    int found = biu - a;
                    int change_num = found - pos, change = sum[found-1] - sum[pos-1];
                    temp += -(change - abs(change + acc * (long long)change_num)) + (acc * (pos_num - change_num));
                }
            } else if(acc > 0) {
                temp += acc * (long long)(zero_num + pos_num);
                if(neg_num > 0) {
                    auto biu = lower_bound(a, a+n, -acc);
                    int found = biu - a; 
                    int change_num = (neg_num - found), change = sum[neg_num-1] - sum[found-1];
                    temp += -(abs(change) - (acc * (long long)change_num + change)) - (acc * (neg_num - change_num));
                }
            }
            printf("%lld\n", temp);
        }
    }
    return 0;
}