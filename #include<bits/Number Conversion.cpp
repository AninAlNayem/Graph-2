#include<bits/stdc++.h>
using namespace std;

const int mx=2e5+10;

vector<int>G[mx];
bool vis[mx];
int dist[mx];

void Set(){

  for(int i=0;i<mx;i++){
    vis[i]=dist[i]=0;
  }

}

int BFS(int src,int des){

   queue<int>Q;
   vis[src]=1;
   dist[src]=0;

   Q.push(src);

   while(!Q.empty()){
      int u=Q.front();
      Q.pop();
      for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v]==0){
            vis[v]=1;
            dist[v]=dist[u]+1;
            Q.push(v);
        }
      }
   }
return dist[des];
}

int main(){

  int edges;
  Set();
  scanf("%d",&edges);
  for(int i=1;i<=edges;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
  }
  int src,des;
  scanf("%d%d",&src,&des);
  int res=BFS(src,des);
  if(res==0){
    printf("Impossible\n");
  }
  else{
    printf("%d\n",res);
  }

}
