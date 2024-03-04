#include<bits/stdc++.h>
using namespace std;

const int mx=1e5+10;

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
    vis[1]=1;
    dist[1]=1;
    Q.push(src);

    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(!vis[v]){
               vis[v]=1;
               dist[v]=dist[u]+1;
               Q.push(v);
            }
        }
    }
return dist[des];
}


int main(){

   int node,edge;
   Set();
   scanf("%d%d",&node,&edge);
   for(int i=1;i<=edge;i++){
     int u,v;
     scanf("%d%d",&u,&v);
     G[u].push_back(v);
     G[v].push_back(u);
   }
   int src=1,des=node;
   int res=BFS(src,des);
   if(res==0){
     printf("IMPOSSIBLE\n");
   }
   else{
     printf("%d\n",res);
   }

return 0;
}
