#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k1, k2, cas = 1;
    while(scanf(" %d %d %d %d", &n, &m, &k1, &k2) == 4 && ( n || m || k1 || k2 ) ) {
        deque <int> Q1, Q2, Q3;
        int a;
        int cnt = 0;
        bool rev = 0;
        for( int i = 0; i < k1; i++) {
            scanf(" %d", &a);
            Q1.push_back( a );
        }
        for( int i = k1; i < k2; i++) {
            scanf(" %d", &a);
            Q2.push_back( a );
        }
        for( int i = k2; i < n; i++) {
            scanf(" %d", &a);
            Q3.push_back( a );
        }
        printf("Case #%d:\n", cas++);
        for( int i = 0; i < m; i++) {
            char opt[10];
            scanf(" %s", opt);
            int input, temp;
            switch( opt[0]){
                case 'a':
                    scanf(" %d", &input);
                    cnt += input;
                    break;
                case 'r':
                    rev ^= 1;
                    break;
                case 'i':
                    scanf(" %d", &input);
                    if( !rev ) {
                        temp = Q1.front();
                        Q1.pop_front();
                        Q1.push_front( input - cnt );
                        Q1.push_front( temp );
                        Q2.push_front( Q1.back() );
                        Q1.pop_back();
                        Q3.push_front( Q2.back() + cnt );
                        Q2.pop_back();
                    }
                    else {
                        temp = Q1.back();
                        Q1.pop_back();
                        Q1.push_back( input - cnt );
                        Q1.push_back( temp );
                        Q2.push_front( Q1.front() );
                        Q1.pop_front();
                        Q3.push_front( Q2.back() + cnt );
                        Q2.pop_back();
                    }
                    break;
                case 'd':
                    if( !rev ) {
                        Q1.pop_front();
                        Q1.push_back( Q2.front() );
                        Q2.pop_front();
                        Q2.push_back( Q3.front() - cnt );
                        Q3.pop_front();
                    }
                    else {
                        Q1.pop_back();
                        Q1.push_front( Q2.front() );
                        Q2.pop_front();
                        Q2.push_back( Q3.front() - cnt );
                        Q3.pop_front();
                    }
                    break;
                case 'm':
                    scanf(" %d", &input);
                    if( input == 1 ) {
                        if( !rev ) {
                            Q1.push_front( Q3.back() - cnt );
                            Q3.pop_back();
                            Q2.push_front( Q1.back() );
                            Q1.pop_back();
                            Q3.push_front( Q2.back() + cnt );
                            Q2.pop_back();
                        }
                        else {
                            Q1.push_back( Q3.back() - cnt );
                            Q3.pop_back();
                            Q2.push_front( Q1.front() );
                            Q1.pop_front();
                            Q3.push_front( Q2.back() + cnt );
                            Q2.pop_back();
                        }
                    }
                    else {
                        if( !rev ) {
                            Q3.push_back( Q1.front() + cnt );
                            Q1.pop_front();
                            Q1.push_back( Q2.front() );
                            Q2.pop_front();
                            Q2.push_back( Q3.front() - cnt );
                            Q3.pop_front();
                        }
                        else {
                            Q3.push_back( Q1.back() + cnt );
                            Q1.pop_back();
                            Q1.push_front( Q2.front() );
                            Q2.pop_front();
                            Q2.push_back( Q3.front() - cnt );
                            Q3.pop_front();
                        }
                    }
                    break;
                case 'q':
                    if( !rev ) {
                        printf("%d\n", Q1.front() + cnt);
                    }
                    else {
                        printf("%d\n", Q1.back() + cnt);
                    }
                    break;
            }
        }
    }
}
