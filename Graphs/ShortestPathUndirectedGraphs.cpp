/* 
  Video Link - https://www.youtube.com/watch?v=abIEXKFpLNE&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA&index=9
  Problem Link - https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/

/* Shortest Path in Undirected Graph using BFS */

#include<unordered_map>
#include<list>
#include<queue>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int, list<int>> adj;
	for( int i=0; i<edges.size(); i++ ){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;
	queue<int> q;
	q.push( s );
	visited[s] = 1;
	parent[s] = -1;

	while( !q.empty() ){

		int front = q.front();
		q.pop();

		for( auto i: adj[front] ){
			if( !visited[i] ){
				visited[i] = 1;
				parent[i] = front;
				q.push(i);
			}
		}

	}

	vector<int> ans;
	int currentNode = t;
	ans.push_back(t);

	while( currentNode != s ){
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}

	reverse( ans.begin(), ans.end() );
	return ans;
	
}
