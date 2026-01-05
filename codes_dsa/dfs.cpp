#include <iostream> 
#include <vector> 
using namespace std; 
void DFS(int node, vector<int> adj[], bool visited[]) { 
    visited[node] = true; 
    cout << node << " "; 
    for (int i = 0; i < adj[node].size(); i++) { 
        int next = adj[node][i]; 
        if (!visited[next]) { 
            DFS(next, adj, visited); 
        } 
    } 
} 
int main() { 
    int vertices, edges; 
    cout << "Enter number of stations (vertices): "; 
    cin >> vertices; 
    vector<int> adj[vertices]; 
    bool visited[vertices] = {false}; 
    cout << "Enter number of connections (edges): "; 
    cin >> edges; 
    cout << "Enter connections (station1 station2):\n"; 
    for (int i = 0; i < edges; i++) { 
        int u, v; 
 
        cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u);  
    } 
    int start; 
    cout << "Enter starting station: "; 
    cin >> start; 
    cout << "DFS Traversal: "; 
    DFS(start, adj, visited); 
    return 0; 
}
