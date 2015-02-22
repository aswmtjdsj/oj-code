#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int maxn = 1500005;
long long numbers[maxn];
long long numbers_sum[maxn];
pair <int, int> pairs[maxn];
bool is_prime[maxn];
vector <int> prime_factors[maxn];
int num_cnt;

int main() {

    // find numbers
    num_cnt = 0;
    long long N = 1000000000000ll;
    for(int i = 1ll; ; i++) {
        if(i * (i+1ll) > N * 2) { // * 2!!!!
            break;
        }
        if(i % 2 == 0) {
            pairs[num_cnt] = make_pair(i/2, i+1);
        } else {
            pairs[num_cnt] = make_pair(i, (i+1)/2);
        }
        numbers[num_cnt++] = (i * (i+1ll)) / 2ll;
        // M[numbers[num_cnt-1]] = num_cnt-1;
    }

    /*cout << 1 << ' ' << numbers[0] << endl;
    cout << num_cnt << ' ' << numbers[num_cnt-1] << ':' 
        << pairs[num_cnt-1].first << ' ' << pairs[num_cnt-1].second << endl;*/

    // find primes
    memset(is_prime, true, sizeof(is_prime));
    int sqrt_n = sqrt(2*N) + 1; // *2 !!!!
    // cout << sqrt_n << endl;

    for(int i = 0; i < sqrt_n; i++) {
        prime_factors[i].clear();
        if(i % 2 == 0) {
            prime_factors[i].push_back(2);
        }
    }

    for(int i = 3; i < sqrt_n; i += 2) {
        if(is_prime[i]) {
            prime_factors[i].push_back(i);
            for(int j = i * 2; j < sqrt_n; j += i) {
                //if(j < sqrt_n) 
                is_prime[j] = false;
                prime_factors[j].push_back(i);
                /*if(M.find(j) != M.end()) {
                    prime_factors[M[j]].push_back(i);
                }*/
            }
        }
    }
    /*cout << 1 << ' ' << primes[0] << endl;
    cout << prime_cnt << ' ' << primes[prime_cnt-1] << endl;*/

    /*cout << num_cnt << ' ' << numbers[num_cnt-1] << ':' 
        << pairs[num_cnt-1].first << ' ' << prime_factors[pairs[num_cnt-1].first].size() << ", "
        << pairs[num_cnt-1].second << ' ' << prime_factors[pairs[num_cnt-1].second].size() << endl;*/
    for(int i = 0; i < num_cnt; i++) {
        long long temp = numbers[i];
        for(auto j: prime_factors[pairs[i].first]) {
            temp = temp / j * (j - 1ll);
        }
        /*for(auto j: prime_factors[pairs[i].first]) {
            for(auto k: prime_factors[pairs[i].second]) {
                if(j == k) {
                    puts("fuck");
                }
            }
        }*/
        for(auto j: prime_factors[pairs[i].second]) {
            temp = temp / j * (j - 1);
        }
        if(i == 0) {
            /*cout << numbers[i] << endl;
            cout << prime_factors[pairs[i].first].size() << " fuck" << endl;
            cout << prime_factors[pairs[i].second].size() << " fuck" << endl;
            cout << temp << endl;
            numbers_sum[i] = temp;*/
            numbers_sum[i] = 1ll;
        } else {
            numbers_sum[i] = numbers_sum[i-1] + temp;
        }
        /*if(i < 10) {
            cout << "num: " << numbers[i] << endl;
            for(auto j: prime_factors[pairs[i].first]) {
                cout << j << ", ";
            }
            for(auto j: prime_factors[pairs[i].second]) {
                cout << j << ", ";
            } cout << endl;
            cout << "div: " << temp << endl;
            cout << i << ':' << numbers_sum[i] << endl;
        }*/
    }

    // find prime factors
    /*vector < vector <int> > prime_factors(num_cnt);
    for(int i = 0; i < num_cnt; i++) {
        long long temp = numbers[i];
        for(int j = 0; j < prime_cnt; j++) {
            while(temp % primes[j] == 0) {
                temp /= primes[j];
            }
            if(temp == 1ll) break;
        }
        if(temp != 1) cout << numbers[i] << endl;
    }*/

    int t;
    cin >> t;
    while(t--) {
        long long L, R;
        cin >> L >> R;
        int low = lower_bound(numbers, numbers + num_cnt, L) - numbers;
        int up = upper_bound(numbers, numbers + num_cnt, R) - numbers;
        /*cout << num_cnt << endl;
        cout << numbers_sum[num_cnt-1] << endl;
        cout << low << ' ' << numbers[low] << ' ' << numbers_sum[low] << ", "
            << up << ' ' << numbers[up] << ' ' << numbers_sum[up] << endl;*/
        long long ans = numbers_sum[up-1];
        if(low > 0) ans -= numbers_sum[low-1];
        cout << ans << endl;
    }
}
