#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
state : 8 ! * 9 = 9! = 362880, nearest prime = 362897 
// find a solution: no need to record ``steps'' with hash
// find an optimal solution: need to use hash struct to record steps
#define hashsize 362897
#define maxq 100

int hash[hashsize];
char ditu[4][4];
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
char dir[] = "udlr";
char Step[maxq];
int ans;
int xi,xj;

void insert(int x)
{
    int h = x % hashsize;
    int i = h;
    while(1)
    {
        if(hash[i] == -1)
        {
            hash[i] = x;
            break;
        }
        else
        {
            i++;
            i %= hashsize;
        }
    }
}

bool find(int x)
{
    int h = x % hashsize;
    int i = h;
    while(hash[i] != -1)
    {
        if(hash[i] == x)
            return true;
        i++;
        i %= hashsize;
    }
    return false;
}

void input()
{
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
        {
            scanf(" %c",&ditu[i][j]);
            //printf("%c",ditu[i][j]);
            if(ditu[i][j] == 'x')
            {
                ditu[i][j] = '9';
                xi = i;
                xj = j;
            }
        }
}

int h()
{
    int sum = 0;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
        {
            int now = ditu[i][j] - '0';
            sum += abs(now/4 - i) + abs(now % 4 - j);
        }
    return sum;
}

int gao()
{
    int sum = 0;
    int idx = 1;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
        {
            sum += (ditu[i][j] - '0') * idx;
            //printf("%c",ditu[i][j]);
            idx *= 10;
        }
    //puts("");
    //printf("%d\n",sum);
    return sum;
}

bool dfs(int step)
{
    if(gao() == 987654321)
    {
        ans = min(step,ans);
        //printf("%d\n",ans);
        return true;
    }
    //puts("fuck what");
    insert(gao());
    //puts("fuck ha");
    int ti= xi,tj= xj;
    for(int i = 0;i < 4;i++)
    {
        if(!(0 <= xi + dx[i] && xi + dx[i] < 3 && 0 <= xj + dy[i] && xj + dy[i] < 3))
            continue;
        xi += dx[i];
        xj += dy[i];
        swap(ditu[xi][xj], ditu[ti][tj]);
        if(!find(gao()) && h() + step + 1 < ans && dfs(step+1))
        {
            Step[step] = dir[i];
            return true;
        }
        // recover
        swap(ditu[xi][xj], ditu[ti][tj]);
        xi = ti;
        xj = tj;
    }
    return false;
}

void init()
{
    ans = 100;
    memset(hash,-1,sizeof(hash));
}

void output()
{
    if(ans == 100)
        puts("unsolvable");
    else
    {
        for(int i = 0;i < ans;i++)
            printf("%c",Step[i]);
        puts("");
    }
}

int main()
{
    input();
    //puts("fuck 1");
    init();
    //puts("fuck 2");
    dfs(0);
    //puts("fuck 3");
    output();
    //puts("fuck 4");
}
