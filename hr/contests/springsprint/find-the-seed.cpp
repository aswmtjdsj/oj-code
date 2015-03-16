#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define MAXN 105
typedef long long LL;

/*
 *    5      - 
 *       6         /  
 *          7 */

LL GCD(LL a, LL b) {
    if(!b) {
        return a;
    }
    return GCD(b, a%b);
}

LL ExpGcd(LL a, LL b, LL &X, LL &Y) {
    LL q, temp;
    if( !b ) {
        q = a; X = 1; Y = 0;
        return q;
    }else {
        q = ExpGcd(b, a % b, X, Y);
        temp = X; 
        X = Y;
        Y = temp - (a / b) * Y;
        return q;
    }
}

LL Mod(LL a, LL b, LL c) {
    if(!b) {
        return 1 % c;
    }
    return Mod(a*a%c, b/2, c) * ( (b&1)?a:1 ) % c; 
}

class GaussMatrix {
    public:
        int r, c;
        LL d[MAXN][MAXN];
        LL x[MAXN];        //  
        LL  xcnt;          //  

        LL abs(LL v) {
            return v < 0 ? -v : v;
        }

        void swap_row(int ra, int rb) {
            for(int i = 0; i <= c; i++) {
                LL tmp = d[ra][i];
                d[ra][i] = d[rb][i];
                d[rb][i] = tmp;
            }
        }
        void swap_col(int ca, int cb) {
            for(int i = 0; i < r; i++) {
                LL tmp = d[i][ca];
                d[i][ca] = d[i][cb];
                d[i][cb] = tmp;
            }        
        }

        void getAns(LL mod) {
            for(int i = c-1; i >= 0; i--) {
                LL tmp = d[i][c];
                // d[i][i] * x[i] + (d[i][i+1]*x[i+1] +  + d[i][c]*x[c]) = K*mod + tmp;
                for(int j = i+1; j < c; j++) {
                    tmp = ((tmp - d[i][j] * x[j] + mod) % mod + mod) % mod;
                }
                // d[i][i] * x[i] = K * mod + tmp;
                // d[i][i] * x[i] + (-K) * mod = tmp;
                // a * x[i] + b * (-K) = tmp;
                LL X, Y;
                ExpGcd(d[i][i], mod, X, Y);
                x[i] = ( (X % mod + mod) % mod ) * tmp % mod;
            }
        }

        // -1  
        LL gauss(LL mod) {
            int i, j, k;
            int col, maxrow;

            //  
            for(i = 0, col = 0; i < r && col < c; i++) {
                //debug_print();
                maxrow = i;
                // ir-1col 
                for(j = i+1; j < r; j++) {
                    if( abs(d[j][col]) > abs(d[maxrow][col]) ){
                        maxrow = j;
                    }
                }
                // i 
                if(maxrow != i) {
                    swap_row(i, maxrow);
                }
                if( d[i][col] == 0 ) {
                    // col 0
                    col ++;
                    i--;
                    continue; 
                }

                for(j = i+1; j < r; j++) {
                    if( d[j][col] ) {
                        // col0
                        // icol0 
                        LL lastcoff = d[i][col];
                        LL nowcoff = d[j][col];
                        for(k = col; k <= c; k++) {
                            d[j][k] = (d[j][k] * lastcoff - d[i][k] * nowcoff + mod) % mod;
                            if (d[j][k] < 0) d[j][k] += mod;
                        }
                    }
                }
                col ++;
            }
            // ii0 
            //  (0 0 0 0 0 0 d[j][c]) (d[j][c] != 0)  
            for(j = i; j < r; j++) {
                if( d[j][c] ) {
                    return -1;
                }
            }
            //   ( - )
            int free_num = c - i;

            // 0 
            for(i = 0; i < r && i < c; i++) {
                if( !d[i][i] ) {
                    // 0 
                    for(j = i+1; j < c; j++) {
                        // 0i 
                        if(d[i][j]) break;
                    }
                    if(j < c) {
                        swap_col(i, j);
                    }
                }
            }
            xcnt = ( ((LL)1) << (LL)free_num );

            getAns(mod);
            return xcnt;
        }    

        void debug_print() {
            int i, j;
            printf("-------------------------------\n");
            for(i = 0; i < r; i++) {
                for(j = 0; j <= c; j++) {
                    cout << d[i][j] << ' ';
                }
                puts("");
            }
            printf("-------------------------------\n");
        }  
};

const long long MOD = 1000000007ll;
struct matrix {
    int r,c;
    vector < vector <long long> > mat;
    matrix(){}
    matrix(int a, int b):r(a), c(b) {
        mat.resize(r);
        for(int i = 0; i < r; i++) {
            mat[i].resize(c);
            fill(mat[i].begin(), mat[i].end(), 0);
        }
        // memset(mat,0,sizeof(mat));
    }
    matrix operator *(const matrix p) {
        matrix w(r,p.c);
        for(int i = 0;i < r;i++) {
            for(int j = 0;j < p.c;j++) {
                long long temp = 0;
                for(int k = 0;k < c;k++) {
                    temp += (mat[i][k] * p.mat[k][j]) % MOD;
                }
                w.mat[i][j] = temp % MOD;
            }
        }
        return w;
    }
};

matrix modp(matrix a,int p) {
    matrix w(a.r, a.c);
    for(int i = 0;i < w.r;i++) {
        w.mat[i][i] = 1;
    }
    // cout << p << endl;
    while(p > 0) {
        if(p&1) {
            w = w * a;
        }
        a = a * a;
        p >>= 1;
    }
    return w;
}

int main() {
    /*GaussMatrix g;
      g.r = 2;
      g.c = 2;
      g.d[0][0] = 1;
      g.d[0][1] = 1;
      g.d[0][2] = 13;
      g.d[1][0] = 1;
      g.d[1][1] = 0;
      g.d[1][2] = 8;
      cout << g.gauss(1000000007ll) << endl;
      for(int i = 0; i < 2; i++) {
      cout << g.x[i] << endl;
      }*/
    int N, K;
    cin >> N >> K;
    int P = K - N + 1;
    int n = N;
    matrix M(n, n);
    vector < long long > c, b;
    c.resize(n);
    b.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0) {
                M.mat[i][j] = c[j];
            } else {
                if(j == i-1) {
                    M.mat[i][j] = 1;
                } else {
                    M.mat[i][j] = 0;
                }
            }
        }
    }
    /*cout << "o:" << endl;
      for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
      cout << M.mat[i][j] << ' ';
      }
      cout << endl;
      }*/
    matrix res = modp(M, P);
    /*cout << "res:" << endl;
      for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
      cout << res.mat[i][j] << ' ';
      }
      cout << endl;
      }*/
    GaussMatrix g;
    g.r = n;
    g.c = n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            g.d[i][j] = res.mat[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        g.d[i][n] = b[i];
    }
    g.gauss(MOD);
    for(int i = 0; i < n; i++) {
        cout << g.x[i] << ' ';
    } cout << endl;
}
