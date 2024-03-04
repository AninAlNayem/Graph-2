#include<bits/stdc++.h>
using namespace std;
const int mx=1002;
char grid[mx][mx];
bool vis[mx][mx];
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

bool grid_BFS(int r,int c,int n,int m){

     queue<int>Qx,Qy;

     Qx.push(r);
     Qy.push(c);
     vis[r][c]=1;
     bool flag=0;

     while(!Qx.empty()){

        int x=Qx.front();
        int y=Qy.front();
        Qx.pop(),Qy.pop();

        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx<1 || newy<1 || newx>n || newy>m){
                continue;
            }
            if(!vis[newx][newy]){
                vis[newx][newy]=1;
                if(grid[newx][newy]=='#'){
                    continue;
                }
                if(grid[newx][newy]=='.'){
                    flag=1;
                    Qx.push(newx),Qy.push(newy);
                }

            }

        }

     }
return flag;
}

int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    //getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
        }
    }

    for(int i=1;i<=mx;i++){
        for(int j=1;j<=mx;j++){
           vis[i][j]=0;
        }
    }

    int connectedComponent=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j]==0 && grid[i][j]=='.'){
               grid_BFS(i,j,n,m);
               connectedComponent++;
            }
        }
    }

    printf("%d\n",connectedComponent);



return 0;
}
