/* 
  Video Link - https://www.youtube.com/watch?v=Tl5qbEmEQyY&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA&index=5
  Problem Link - https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/

#include<unordered_map>
#include<list>

bool checkCycle( int node, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited){

  visited[node] = true;
  dfsVisited[node] = true;

  for( auto i: adj[node] ){
    if( !visited[i] ){
      int ans = checkCycle( i, adj, visited, dfsVisited );
      if( ans ){
        return true;
      }
    }else if( dfsVisited[i] ){
      return true;
    }
  }

  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int, list<int>> adj;
  for( int i=0; i<edges.size(); i++ ){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;

  for( int i=1; i<=n; i++ ){
    if( !visited[i] ){
      bool ans = checkCycle( i, adj, visited, dfsVisited );
      if( ans ){
        return true;
      }
    }
  }

  return false;
  
}
