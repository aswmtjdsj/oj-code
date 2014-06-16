#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include <iostream>
#include<queue>
#include<cstring>

using namespace std;

int n;

int dist[402][402];
bool visited[402][402];
int adj[402][402][4];

int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

struct prof {
    int r,c,dist;
    prof(int _r,int _c,int _dist): r(_r),c(_c),dist(_dist) {}
    bool operator < ( const prof& p) const {
        return dist > p.dist;
    }
};

int dijkstra()
{
    priority_queue<prof> pq;
    memset(visited,0,sizeof(visited));
    int i,j,k;

    for(j=1;j<=n;j++) {
        pq.push(prof(1,j,dist[1][j]));
    }
    for(i=2;i<=n;i++) {
        pq.push(prof(i,n,dist[i][n]));
    }

    int result=~0u>>1;
    //cout << result << endl;
    while(!pq.empty()) {
        int cdist=pq.top().dist;
        int cr=pq.top().r;
        int cc=pq.top().c;
        pq.pop();
        //printf("pop: %d %d %d\n",cr,cc,cdist);

        if(cr==-1) return cdist;

        if(visited[cr][cc]) continue;
        visited[cr][cc]=true;

        int nr,nc,ndist;

        if(cr>1) { // up
            nr=cr-1,nc=cc,ndist=cdist+adj[cr][cc][0];
            if(ndist<dist[nr][nc]) {
                dist[nr][nc]=ndist;
                //printf("push: %d %d %d\n",nr,nc,ndist);
                pq.push(prof(nr,nc,ndist));
            }
        }
        if(cc<n) { // right
            nr=cr,nc=cc+1,ndist=cdist+adj[cr][cc][3];
            if(ndist<dist[nr][nc]) {
                dist[nr][nc]=ndist;
                //printf("push: %d %d %d\n",nr,nc,ndist);
                pq.push(prof(nr,nc,ndist));
            }
        }
        
        // down
        nr=cr+1,nc=cc,ndist=cdist+adj[cr][cc][1];
        if(nr>n) {
            if(ndist<result) {
                result=ndist;
                //printf("push: %d %d %d\n",nr,nc,ndist);
                pq.push(prof(-1,-1,ndist));
            }
        } else {
            if(ndist<dist[nr][nc]) {
                dist[nr][nc]=ndist;
                //printf("push: %d %d %d\n",nr,nc,ndist);
                pq.push(prof(nr,nc,ndist));
            }
        }

        // left
        nr=cr,nc=cc-1,ndist=cdist+adj[cr][cc][2];
        if(nc<1) {
            if(ndist<result) {
                result=ndist;
                //printf("push: %d %d %d\n",nr,nc,ndist);
                pq.push(prof(-1,-1,ndist));
            }
        } else {
            if(ndist<dist[nr][nc]) {
                dist[nr][nc]=ndist;
                //printf("push: %d %d %d\n",nr,nc,ndist);
                pq.push(prof(nr,nc,ndist));
            }
        }
    }
}
int mat[350000];
int main()
{
    int t;
    int i,j,k;
    int cas;
    scanf("%d",&cas);
    for(int fuck = 0;fuck < cas;fuck++)
    {

    //scanf("%d%d",&r,&c);
    scanf("%d",&n);
    n--;
    for(i = 1;i <= (n + 1) * (n + 1);i++)
    {
        int a;
        scanf("%d",&a);
        int x = i / (n + 1),y = i % (n + 1);
        if(y > 0)
            x++;        
        if(y == 0)y = n + 1;
        if(y <= n)    
        {
            int temp = (x - 1) * (2 * n + 1) + y;
            mat[temp] = a;
        }
        if(x <= n)
        {
            int temp = (x - 1) * ( 2 * n + 1) + n + y;
            mat[temp] = a;
        }
        //        mat[i + n + 1] = a;
    }
    int cnt = 1;
    /*for(i = 1;i <= 2 * n + 1;i++)
    {
        for(j = 1;j <= n + 1;j++)
        {
            if(i % 2 && j == n + 1)
                continue;
            printf("%d ",mat[cnt++]);
        }
        puts("");
    }*/
    memset(dist,0x70,sizeof(dist));

    int cur;
    cnt = 1;
    for(j=1;j<=n;j++) {
    dist[1][j] = mat[cnt++];
        //scanf("%d",&dist[1][j]);
    }
    adj[1][1][2] = mat[cnt++];
    //scanf("%d",&adj[1][1][2]);
    for(j=1;j<=n;j++) {
        //scanf("%d",&cur);
    cur = mat[cnt++];
        adj[1][j][3]=adj[1][j+1][2]=cur;
    }
    if(dist[1][n]>cur) dist[1][n]=cur;

    for(i=2;i<=n;i++) {
        for(j=1;j<=n;j++) {
            //scanf("%d",&cur);
        cur = mat[cnt++];            
        adj[i][j][0]=adj[i-1][j][1]=cur;
        }
    adj[i][1][2] = mat[cnt++];
        //scanf("%d",&adj[i][1][2]);
        for(j=1;j<=n;j++) {
            //scanf("%d",&cur);
        cur = mat[cnt++];    
    adj[i][j][3]=adj[i][j+1][2]=cur;
        }
        dist[i][n]=cur;
    }
    for(j=1;j<=n;j++) {
        cur = mat[cnt++];
        //scanf("%d",&cur);
        adj[n][j][1]=cur;
    }
    //cout << cnt << endl;
    int result=dijkstra();

    printf("%d\n",result);
    }
    return 0;
}
