/*
  Video Link - https://www.youtube.com/watch?v=b5kij1Akf9I&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA&index=2
  Problem Link - https://www.naukri.com/code360/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/

/* BFS traversal */


void bfs( vector<vector<int>> &adj, unordered_map<int, bool>& visited,
vector<int>& ans, int node ){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while( !q.empty() ){

        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for( int i=0; i<adj[frontNode].size(); i++ ){
            if( !visited[adj[frontNode][i]] ){
                q.push(adj[frontNode][i]);
                visited[adj[frontNode][i]] = 1;
            }
        }
    }

}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    unordered_map<int, bool> visited;
    vector<int> ans;

    if( !visited[0] ){
        bfs( adj, visited, ans, 0 );      
    }
    
    return ans;
}
