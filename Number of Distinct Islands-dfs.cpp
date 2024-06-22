//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,
    vector<pair<int,int>> &ans,int row0,int col0){
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vis[row][col]=1;
        ans.push_back({row-row0,col-col0});
        for(int i=0;i<4;i++){
            int newRow= row+delrow[i];
            int newCol= col+delcol[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m
            && vis[newRow][newCol]==0 && grid[newRow][newCol]==1){
                dfs(newRow,newCol,vis,grid,ans,row0,col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> ans;
                    dfs(i,j,vis,grid,ans,i,j);
                    st.insert(ans);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
