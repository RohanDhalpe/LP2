#include<bits/stdc++.h>
using namespace std;

void PrintSolution(vector<vector<int>> &board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int row,int col,vector<vector<int>> &board,int n)
{
   int i=row;
   int j=col;
   while(j>=0){
      if(board[i][j]==1){
          return false;
      }
    j--;  
   }

   i=row;
   j=col;
   while(i>=0 && j>=0)
   { 
       if(board[i][j]==1)
       {
         return false;
       }
     i--;
     j--;
    }

     i=row;
     j=col;
    while(i<n && j>=0)
    { 
       if(board[i][j]==1)
       {
         return false;
       }
     i++;
     j--;
    }
  return true;
}
void solve(vector<vector<int>>&board,int col,int n){
     if(col>=n){
        PrintSolution(board,n);
        return;
     }

     for(int row=0;row<n;row++)
     { 
        if(isSafe(row,col,board,n))
        {
          board[row][col]=1;
          solve(board,col+1,n);
          board[row][col]=0;
        }

     }
}

int main()
{ 
   int n=4;
   vector<vector<int>>board(n,vector<int>(n,0));

   int col=0;
   solve(board,col,n);

return 0;
}
