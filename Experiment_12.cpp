#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:

    void createGraph() {
        cout << "Enter number of vertices: ";
        cin >> V;

        adj.resize(V);

        int edges, u, v;
        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "Enter edges (u v):\n";
        for (int i = 0; i < edges; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
    }

    void bfs(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void dfsUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        dfsUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g;
    int choice, start;

    do {
        cout << "\n--- Graph Menu ---";
        cout << "\n1. Create Graph";
        cout << "\n2. BFS Traversal";
        cout << "\n3. DFS Traversal";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.createGraph();
                break;

            case 2:
                cout << "Enter starting vertex: ";
                cin >> start;
                g.bfs(start);
                break;

            case 3:
                cout << "Enter starting vertex: ";
                cin >> start;
                g.dfs(start);
                break;

            case 4:
                cout << "Program Ended\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while (choice != 4);

    return 0;
}
