#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices in the graph

// Function to check if it's safe to assign the color 'color' to vertex 'v'
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

// Function to recursively assign colors to the vertices of the graph
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true; // All vertices are assigned colors successfully

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            // Recur to assign colors to remaining vertices
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            // Backtrack if assigning color 'c' to vertex 'v' does not lead to a solution
            color[v] = 0;
        }
    }

    return false; // No valid color assignment found for vertex 'v'
}

// Function to solve the graph coloring problem
bool graphColoring(bool graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0; // Initialize all vertices as uncolored

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists. The colors assigned to vertices are:\n");
        for (int i = 0; i < V; i++)
            printf("Vertex %d: Color %d\n", i, color[i]);
        return true;
    }

    printf("Solution does not exist.\n");
    return false;
}

int main() {
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;
}
