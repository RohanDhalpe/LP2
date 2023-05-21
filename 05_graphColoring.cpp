#include<bits/stdc++.h>
using namespace std;

void graphColor(vector<int>adjList[],vector<int> &color,int &cromaticNo){
     queue<int>q;
     q.push(0);

     while(!q.empty())
     {
        int currNode=q.front();
        q.pop();
        vector<bool>availableColors(cromaticNo,true);

        if(color[currNode]==-1)
        {   
            for(auto it:adjList[currNode]){
               if(color[it]!=-1){
                 availableColors[color[it]]=false;
               }else{
                q.push(it);
               }
            }

            int availablecolor=-1;
            for(int i=0;i<cromaticNo;i++)
            {  
                if(availableColors[i]==true){
                   availablecolor=i;
                   break;
                }
            }

            if(availablecolor==-1){
                cromaticNo=cromaticNo+1;
                color[currNode]=cromaticNo-1;
            }else{
                color[currNode]=-1;
            }

        }
   }

}
int main(){
    int v;
    cout<<"Enter the number of vertice :";
    cin>>v;

    int e;
    cout<<"Enter the number of edges ";
    cin>>e;
    
    vector<int>adjList[v];
    for(int i=0;i<e;i++)
    {  int p,q;
       cin>>p>>q;
       adjList[p].push_back(q);
       adjList[p].push_back(q);
    }
    int cromaticNo=0;
    vector<int>color(v,-1);

    graphColor(adjList,color,cromaticNo);
    for(auto it:color){
        cout<<it<<" ";
    }
    return 0;
}
  