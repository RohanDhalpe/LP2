#include<bits/stdc++.h>
using namespace std;
void prims(vector<int> &visited,    vector<pair<int,int>>&mst,  vector<pair<int,int>>adjList[])
{
   priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
   pq.push({0,{0,-1}});  //weight node parent

   while(!pq.empty()) {
     pair<int,pair<int,int>>temp=pq.top();
     pq.pop();

     int weight=temp.first;
     int node=temp.second.first;
     int parent=temp.second.second;

     cout<<weight<<" "<<node<<" "<<parent<<endl;

     if(visited[node]==1){
        continue;

     }
     visited[node]=1;
     if(parent!=-1){
        mst.push_back({parent,node});
     }

     for(auto it:adjList[node])
     {  
        if(!visited[it.first]){
            int node_=it.first;
            int weight_=it.second;
            pq.push({weight_,{node_,node}});
        }

     }

   }              
}
int main(){
    int v,e;

    cout<<"Enter the number of vertices: ";
    cin>>v;

    cout<<"Enter the number of edjes: ";
    cin>>e;
     
     vector<  pair<int,int>  >adjList[v];

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }
    
    vector<int>visited(v,0);
    vector<pair<int,int>>mst;
    prims(visited,mst,adjList);

   cout<<"Edges in MST "<<endl;
   for(auto it:mst){
    cout<<it.first<<" "<<it.second<<" ";
   }





    return 0;

}