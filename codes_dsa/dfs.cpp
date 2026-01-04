#include <iostream>
#include <vector>
using namespace std;

vector<int> g[5];
bool visited[5];

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int u : g[v])
        if (!visited[u]) dfs(u);
}

int main() {
    g[0] = {1, 2};
    g[1] = {3};
    g[2] = {4};

    dfs(0);
}
