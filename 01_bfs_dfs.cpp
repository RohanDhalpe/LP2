#include<bits/stdc++.h>
using namespace std;

void bfsTraversal( map<int,list<int>>adjList,vector<int> &visited,int node)
{
    visited[node]=1;
    queue<int>q;
    q.push(node);

    while(!q.empty())
    { 
        int temp=q.front();
        cout<<temp<<" ";
        q.pop();

        for(auto it:adjList[temp]){
            if(!visited[it])
            {
               q.push(it);
               visited[it]=1;
            }
        }
    }
}
void dfsTraversal( map<int,list<int>>adjList,vector<int> &visited,int node)
{   
   visited[node]=1;
   cout<<node<<" ";
   for(auto it:adjList[node])
   {
      if(!visited[it]){
        dfsTraversal(adjList,visited,it);
      }
   }

}

int main(){

    map<int,list<int>>adjList;

    int v,e;
    cout<<"Enter the number of vertices: ";
    cin>>v;

    cout<<"Enter the number of edges ";
    cin>>e;

    for(int i=0;i<e;i++)
    {   
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int>visited(v,0);
    cout<<"BFS TRAVERSAL IS : ";
    for(int i=1;i<=v;i++){
        if(!visited[i]){
            bfsTraversal(adjList,visited,i);
        }
    }

    vector<int>visited(v,0);
    cout<<"DFS TRAVERSAL IS : ";
    for(int i=1;i<=v;i++){
        if(!visited[i]){
            dfsTraversal(adjList,visited,i);
        }
    }
    return 0;
}