/* 
  Video Link - https://www.youtube.com/watch?v=EaK6aslcC5g&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA&index=1
  Problem Link - https://www.naukri.com/code360/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/

/* Creating and printing Adjency List */

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<int> adj[n];
    for( int i=0; i<m; i++ ){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector <int> > ans(n);
    for( int i=0; i<n; i++ ){

        ans[i].push_back(i);

        for( int j=0; j<adj[i].size(); j++ ){
            ans[i].push_back( adj[i][j] );
        }

    }

    return ans;
}
