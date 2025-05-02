/* 
  Video Link - https://www.youtube.com/watch?v=aJa3U-hydXc&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA&index=3
  Problem Link - https://www.naukri.com/code360/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar 
*/
/* DFS Traversal */


void dfs( unordered_map< int, list<int> >& adj, unordered_map< int, bool >& visited,
int node, vector<int>& components){
    
    components.push_back(node);
    visited[node] = 1;

    for( auto i: adj[node] ){
        if( !visited[i] ){
            dfs( adj, visited, i, components );
        }
    }

}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    //first create an adjlist

    unordered_map< int, list<int> > adj;

    for( int i=0; i<edges.size(); i++ ){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map< int, bool > visited;

    for( int i=0; i<V; i++ ){
        if( !visited[i] ){
            vector<int> components;
            dfs( adj, visited, i, components );
            ans.push_back(components);
        }
    }

    return ans;

}
