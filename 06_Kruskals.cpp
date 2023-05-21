#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
     public:
     vector<int>rank;
     vector<int>parent;
     
     DisjointSet(int n){
          rank.resize(n+1,0);
          parent.resize(n+1);
          for(int i=0;i<n+1;i++){
               parent[i]=i;
          }
     }
     
      int findUpar(int node){
           if(node==parent[node]){
                return node;
           }
           return parent[node]=findUpar(parent[node]);
      }
      
      void uniByrank(int u,int v)
      {
           int ulp_u=findUpar(u);
           int ulp_v=findUpar(v);
           if(ulp_u==ulp_v){
                return;
           }
           
           if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
           }
           else if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v]=ulp_u;
           }else if(rank[ulp_u]==rank[ulp_v]){
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
           }
           
      }
};
int main(){
     
     int v,e;
     cout<<"Enter the number of Edges :";
     cin>>v;
     
     cout<<"Enter the number of vertices :";
     cin>>e;
     vector<pair<int,pair<int,int>>> edges;
     
     
     for(int i=0;i<e;i++){
          int u,v,w;
          cin>>u>>v>>w;
          edges.push_back({w,{u,v}});
     }
     sort(edges.begin(),edges.end());
     vector<pair<int,int>>mst;
     
     DisjointSet ds(v);
     
     for(auto it:edges){
          pair<int,pair<int,int>>temp=it;
          int startnode=temp.second.first;
          int endnode=temp.second.second;
          
          if(ds.findUpar(startnode) !=ds.findUpar(endnode)){
               mst.push_back({startnode,endnode});
               ds.uniByrank(startnode,endnode);
          }
     }
     
     cout<<"MST :"<<endl;
     for(auto it:mst){
          cout<<it.first<<" "<<it.second<<endl;
     }
     
     return 0;
}
