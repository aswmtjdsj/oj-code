/* base IO */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>
#include <cassert>

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

const int maxn = 100005;
int arr[maxn];

const int MAXNUM = 800005;
struct SegTreeNode
{
    int val;
    int l, r;
}segTree[MAXNUM]; // def of seg tree

/*
 * function: build seg tree
 * root: the index of current tree node
 * arr: array to build seg tree
 * istart: start index in the array
 * iend: end index in the array
 * */
void build(int root, int arr[], int istart, int iend)
{
    if(istart == iend) // leaf node
    {
        segTree[root].val = arr[istart];
        segTree[root].l = segTree[root].r = istart;
    }
    else
    {
        int mid = (istart + iend) / 2;
        build(root*2+1, arr, istart, mid); // build left sub-tree recursively
        build(root*2+2, arr, mid+1, iend); // build right sub-tree recursively
        // update value of current node accordint to two recursive results of the two sub-trees
        // segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
        int a = segTree[root*2+1].val, b = segTree[root*2+2].val;
        int l1 = segTree[root*2+1].l, r1 = segTree[root*2+1].r, 
            l2 = segTree[root*2+2].l, r2 = segTree[root*2+2].r;
        printf("B [%d, %d]: (%d, %d) %d, [%d, %d]: (%d, %d) %d\n", 
                istart, mid, 
                segTree[root*2+1].l, segTree[root*2+1].r, a,
                mid+1, iend,
                segTree[root*2+2].l, segTree[root*2+2].r, b);
        if(a == 0 || b == 0) {
            segTree[root].val = 0;
            segTree[root].l = istart;
            segTree[root].r = iend;
        } else if(r1 + 1 == l2 && a  == 1 && b == 1) {
            segTree[root].val = 1;
            segTree[root].l = l1;
            segTree[root].r = r2;
        } else if(a < b || (a == b && r1 - l1 >= r2 - l2)) {
            segTree[root].val = a;
            segTree[root].l = l1;
            segTree[root].r = r1;
        } else if(a > b || (a == b && r1 - l1 < r2 - l2)) {
            segTree[root].val = b;
            segTree[root].l = l2;
            segTree[root].r = r2;
        }
    }
}
/*
 * function: interval query on the seg tree
 * root: the index of current tree node
 * [nstart, nend]: the interval which current node is representing
 * [qstart, qend]: query interval
 * */
int query(int root, int nstart, int nend, int qstart, int qend, int & l, int & r)
{
    // query interval doesnot intersect with current tree node
    if(qstart > nend || qend < nstart) {
        l = r = -1;
        return inf;
    }
    // current tree node is involved in the query interval, inclusively
    if(qstart <= nstart && qend >= nend) {
        l = segTree[root].l;
        r = segTree[root].r;
        return segTree[root].val;
    }
    // query in the two sub-trees and return the compared result
    int mid = (nstart + nend) / 2;
    int l1 = -1, l2 = -1;
    int r1 = -1, r2 = -1;
    int a = query(root*2+1, nstart, mid, qstart, qend, l1, r1),
        b = query(root*2+2, mid + 1, nend, qstart, qend, l2, r2);
    // cout << a << ' ' << pos1 << ' ' << b << ' ' << pos2 << endl;
    printf("Q [%d, %d]: (%d, %d) %d, [%d, %d]: (%d, %d) %d\n", 
            nstart, mid, 
            l1, r1, a,
            mid+1, nend,
            l2, r2, b);
    int ans;
    if(a == 0 || b == 0) {
        l = qstart;
        r = qend;
        ans = 0;
    } else if(r1 + 1 == l2 && a == 1 && b == 1) {
        l = l1;
        r = r2;
        ans = 1;
    } else if(a < b || (a == b && r1 - l1 >= r2 - l2)) {
        l = l1;
        r = r1;
        ans = a;
    } else if(a > b || (a == b && r1 - l1 < r2 - l2)) {
        l = l2;
        r = r2;
        ans = b;
    }
    // cout << "ANS: " << ans << ' ' << pos << endl;
    return ans;
}
/*
 * fucntion: update the value of some leaf node in the seg tree
 * root: the index of current tree node
 * [nstart, nend]: the interval which current node is representing
 * index: the index, of the node to update, in the original array
 * Val: value to update
 * */
void updateOne(int root, int nstart, int nend, int index, int Val)
{
    if(nstart == nend)
    {
        if(index == nstart) // found the corresponding node, update it
            segTree[root].val = Val;
        return;
    }
    int mid = (nstart + nend) / 2;
    if(index <= mid) // update value in left sub-tree
        updateOne(root*2+1, nstart, mid, index, Val);
    else updateOne(root*2+2, mid+1, nend, index, Val); // update in right sub-tree
    // update value of current node accordint to two recursive results of the two sub-trees
    // segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
    int a = segTree[root*2+1].val, b = segTree[root*2+2].val;
    int l1 = segTree[root*2+1].l, r1 = segTree[root*2+1].r, 
        l2 = segTree[root*2+2].l, r2 = segTree[root*2+2].r;
    if(a == 0 || b == 0) {
        segTree[root].val = 0;
        segTree[root].l = nstart;
        segTree[root].r = nend;
    } else if(r1 + 1 == l2 && a  == 1 && b == 1) {
        segTree[root].val = 1;
        segTree[root].l = l1;
        segTree[root].r = r2;
    } else if(a < b || (a == b && r1 - l1 >= r2 - l2)) {
        segTree[root].val = a;
        segTree[root].l = l1;
        segTree[root].r = r1;
    } else if(a > b || (a == b && r1 - l1 < r2 - l2)) {
        segTree[root].val = b;
        segTree[root].l = l2;
        segTree[root].r = r2;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        scanf(" %d", &arr[i]);
    }
    build(0, arr, 0, n - 1);
    for(int i = 0; i < q; i++) {
        int o, a, b;
        scanf(" %d %d %d", &o, &a, &b);
        if(o == 1) { // query [a, b] min sub product
            a--; b--;
            int l = -1, r = -1;
            int ans = query(0, 0, n - 1, a, b, l, r);
            l++; r++;
            printf("%d %d %d\n", ans, l, r);
        } else { // o == 2, change arr[a] = b
            a--;
            updateOne(0, 0, n - 1, a, b);
        }
    }
}
