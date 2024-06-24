//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool dfsCheck(int st,vector<int> &vis,vector<int> &currVis,vector<int> adj[]){
        vis[st]=1;
        currVis[st]=1;
        for(auto it : adj[st]){
            if(!vis[it]){
                if(dfsCheck(it,vis,currVis,adj)==false){
                    return false;
                }
            }
                else if(currVis[it]==1){
                    return false;
                }
            }
        
        currVis[st]=0;
        return true;
        
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> currVis(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsCheck(i,vis,currVis,adj);
            }
        }
       for(int i=0;i<V;i++){
           if(currVis[i]==0){
               ans.push_back(i);
           }
       }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
