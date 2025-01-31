#include <iostream>
#include <iomanip>
#include <climits>
#define MAX_NODES 10

using namespace std;

class Graph {
public:
    int edges;
    int vertices;
    int distance[MAX_NODES];
    bool visited[MAX_NODES];
    int adjmat[MAX_NODES][MAX_NODES];

    void input(int v, int e) {
        edges = e;
        vertices = v;
        
        // Initialize adjacency matrix
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                adjmat[i][j] = 0;
            }
        }

        // Input edges
        int src, dst, weight;
        for (int i = 0; i < e; i++) {
            cout << "Enter edge " << i + 1 << ":\n";
            cout << "Source: ";
            cin >> src;
            cout << "Destination: ";
            cin >> dst;
            cout << "Weight: ";
            cin >> weight;
            adjmat[src - 1][dst - 1] = weight;
            adjmat[dst - 1][src - 1] = weight; // For undirected graph
        }
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << setw(5) << adjmat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void linkStateRouting(int startNode) {
        // Initialize distance and visited arrays
        for (int i = 0; i < vertices; i++) {
            distance[i] = INT_MAX;
            visited[i] = false;
        }
        distance[startNode] = 0; // Distance to itself is zero

        // Main loop for Dijkstra's algorithm
        for (int count = 0; count < vertices - 1; count++) {
            // Find the vertex with the minimum distance
            int u = -1;
            for (int i = 0; i < vertices; i++) {
                if (!visited[i] && (u == -1 || distance[i] < distance[u])) {
                    u = i;
                }
            }

            visited[u] = true; // Mark the picked vertex as visited

            // Update distance values of adjacent vertices of the picked vertex
            for (int v = 0; v < vertices; v++) {
                if (adjmat[u][v] != 0 && !visited[v]) {
                    distance[v] = min(distance[v], distance[u] + adjmat[u][v]);
                }
            }
        }

        // Display the final distances
        cout << "Shortest distances from node " << (startNode + 1) << ":\n";
        for (int i = 0; i < vertices; i++) {
            if (distance[i] == INT_MAX) {
                cout << "Distance to node " << (i + 1) << " is INF\n";
            } else {
                cout << "Distance to node " << (i + 1) << " is " << distance[i] << "\n";
            }
        }
    }
};

int main() {
    int v, e;
    Graph g;
    
    cout << "Enter number of vertices and edges:\n";
    cin >> v >> e;
    
    g.input(v, e);
    
    cout << "Graph is:\n";
    g.display();
    
    int startNode;
    cout << "Enter starting node (1 to " << v << "): ";
    cin >> startNode;
    g.linkStateRouting(startNode - 1); // Convert to 0-based index

    return 0;
}

