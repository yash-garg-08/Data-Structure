/*
  Video Link - https://www.youtube.com/watch?v=1cSzxlhxOw8&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA&index=4
  Problem Link - https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/

/* Cycle Detection in Undirected Graph Using BFS */

#include<unordered_map>
#include<queue>
#include<list>
bool cycleDetBfs( int src, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited){
  
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);
    
    while( !q.empty() ){

        int front = q.front();
        q.pop();

        for( auto i: adj[front] ){
            if( visited[i] == 1 && i != parent[front] ){
                return true;
            }else if( !visited[i] ){
                q.push(i);
                visited[i] = 1;
                parent[i] = front;
            }
        }

    }

    return false;

}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    for( int i=0; i<edges.size(); i++ ){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for( int i=0; i<n; i++ ){

        if( !visited[i] ){
            bool ans = cycleDetBfs( i, adj, visited );
            if( ans == 1 ){
                return "Yes";
            }
        }

    }
    return "No";
}
