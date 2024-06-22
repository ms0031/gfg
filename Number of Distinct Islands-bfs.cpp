//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,
    vector<pair<int,int>> &ans){
        int n=grid.size();
        int m=grid[0].size();
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        ans.push_back({row-row,col-col});
        while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
        for(int i=0;i<4;i++){
            int newRow= node.first+delrow[i];
            int newCol= node.second+delcol[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m
            && vis[newRow][newCol]==0 && grid[newRow][newCol]==1){
                vis[newRow][newCol]=1;
                q.push({newRow,newCol});
                ans.push_back({newRow-row,newCol-col});
            }
        }
    }}
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
                    bfs(i,j,vis,grid,ans);
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
