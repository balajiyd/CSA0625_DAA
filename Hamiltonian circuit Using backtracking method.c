#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

// Function to check if the current vertex can be added to the Hamiltonian circuit
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (!graph[path[pos - 1]][v]) // If there is no edge between the last vertex in the path and the current vertex
        return false;

    for (int i = 0; i < pos; i++) { // Check if the current vertex is already in the path
        if (path[i] == v)
            return false;
    }

    return true;
}

// Function to recursively find a Hamiltonian circuit
bool hamiltonianCircuitUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) { // If all vertices are included in the path
        if (graph[path[pos - 1]][path[0]]) // Check if there is an edge between the last vertex and the starting vertex
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) { // Check if the current vertex can be added to the path
            path[pos] = v;

            if (hamiltonianCircuitUtil(graph, path, pos + 1)) // Recur to add the next vertex
                return true;

            path[pos] = -1; // Backtrack if adding the current vertex doesn't lead to a solution
        }
    }

    return false; // No Hamiltonian circuit found
}

// Function to find a Hamiltonian circuit in the graph
void hamiltonianCircuit(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // Start from vertex 0

    if (hamiltonianCircuitUtil(graph, path, 1)) {
        printf("Hamiltonian circuit exists: ");
        for (int i = 0; i < V; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[0]); // Print the starting vertex again to complete the circuit
    } else {
        printf("Hamiltonian circuit does not exist.\n");
    }
}

int main() {
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCircuit(graph);

    return 0;
}
