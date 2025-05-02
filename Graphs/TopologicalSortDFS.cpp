/*
  Video Link - https://www.youtube.com/watch?v=T_boOrr0rvk&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA&index=6
  Problem Link - https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/

#include <bits/stdc++.h>

void dfs( int node, unordered_map<int, list<int>>& adj, 
unordered_map<int, int>& visited, stack<int>& s ){
    
    visited[node] = 1;

    for( auto i: adj[node] ){
        if( !visited[i] ){
            dfs( i, adj, visited, s );
        }
    }

    s.push(node);

}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, int> visited;
    stack<int> s;
    for( int i=0; i<v; i++ ){

        if( !visited[i] ){
            dfs( i, adj, visited, s );
        }

    }

    vector<int> res;

    while( !s.empty() ){
        res.push_back( s.top() );
        s.pop();
    }

    return res;

}
