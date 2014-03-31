#include<iostream>
using namespace std;

const int maxn=1<<20;
bool mark[maxn];
int dp[maxn][4][4];
int dist[maxn];

bool isfullfill(int A[][4]){
    int temp=A[0][0];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            if(temp^A[i][j]!=0)return false;
    }
    return true;
}
bool ismark(int A[][4]){
    int n=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            if(A[i][j])n+=1<<(i*4+j);
    }
    if(mark[n])return false;
    mark[n]=1;
    return true;
}

int main()
{
    char ch;
    int ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >>ch;
            if(ch=='w')dp[0][i][j]=0;
            else dp[0][i][j]=1;
        }
        //fflush(stdin);
    }

    int front=0,rear=1;
    dist[0]=0;
    ismark(dp[0]);
    if(!isfullfill(dp[0]))while(front < rear && ans==0){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                memcpy(dp[rear],dp[front],sizeof(dp[0]));
                dp[rear][i][j]=!dp[front][i][j];
                if(i!=0)dp[rear][i-1][j]=!dp[front][i-1][j];
                if(j!=0)dp[rear][i][j-1]=!dp[front][i][j-1];
                if(i!=3)dp[rear][i+1][j]=!dp[front][i+1][j];
                if(j!=3)dp[rear][i][j+1]=!dp[front][i][j+1];

                dist[rear]=dist[front]+1;
                if(isfullfill(dp[rear])){ans=dist[rear];break;}
                if(ismark(dp[rear]))rear++; 
            }
        }
        front++;
    }
    if(front>=rear)cout<< "Impossible" << endl;
    else cout << ans << endl;
    return 0;
}
