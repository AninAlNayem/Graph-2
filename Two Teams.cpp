#include<bits/stdc++.h>
using namespace std;

const int mx=1e5+10;

vector<int>G[mx];
int dist[mx];

void Set(){

  for(int i=0;i<mx;i++){
     dist[i]=-1;
  }
}

bool BFS(int src){

    queue<int>Q;
    dist[src]=0;
    Q.push(src);
    bool is_bipartite=true;

    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(dist[v]==-1){
               dist[v]=dist[u]^1;
               Q.push(v);
            }
            else{
                is_bipartite = is_bipartite & (dist[u]!=dist[v]);
            }
        }
    }
return is_bipartite;
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
   bool res=true;
   for(int i=1;i<=node;i++){
    if(dist[i]==-1){
        res=BFS(i);
        if(res==0){
           break;
        }
    }
   }

   if(res){
     printf("YES\n");
   }
   else{
     printf("NO\n");
   }

return 0;
}
