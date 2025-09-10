#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    int shortestPath(int start, int end) {
        if (start == end) return 0;

        vector<int> dist(V, -1); 
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    if (neighbor == end) return dist[neighbor];
                    q.push(neighbor);
                }
            }
        }
        return -1;
    }
};

int main() {
    int V1 = 5;
    vector<vector<int>> edges1 = {{0,1}, {0,2}, {1,3}, {2,3}, {3,4}};
    Graph g1(V1);
    for (auto e : edges1) g1.addEdge(e[0], e[1]);
    cout << g1.shortestPath(0, 4) << endl; 

    return 0;
}
