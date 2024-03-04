#include<bits/stdc++.h>
using namespace std;

const int mx=1e5+10;

vector<int>G[mx];
bool vis[mx];

void Set(){

  for(int i=0;i<mx;i++){
    vis[i]=0;
  }

}

void BFS(int src){

   queue<int>Q;
   vis[src]=1;

   Q.push(src);

   while(!Q.empty()){
      int u=Q.front();
      Q.pop();
      for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v]==0){
            vis[v]=1;
            Q.push(v);
        }
      }
   }
}

int main(){

  int nodes,edges;
  Set();
  scanf("%d%d",&nodes,&edges);
  for(int i=1;i<=edges;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int connectedComponents=0;

  for(int i=1;i<=nodes;i++){
    if(vis[i]==0){
      connectedComponents++;
      BFS(i);
    }
  }

  printf("%d\n",connectedComponents-1);

}
