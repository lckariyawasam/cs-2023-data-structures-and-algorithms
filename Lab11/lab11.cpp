#include <iostream>
using namespace std;

#define N 6


int findMin(int visited[], int key[]) {
    /*

    Returns the unvisited vertex with the lowest key

    Args:
        visited (int[]) : Array containing whether or not each of the vertexes have been visited
        key (int[])     : Array containing the key (minimum distance to a neighbour) of each vertex

    Returns:
        minVertex (int) : The unvisited vertex with least key

    */

    int min = INT_MAX;
    int minVertex;

    for (int i = 0; i < N; i++) {
        if (visited[i] == 0 && key[i] < min) {
            minVertex = i;
            min = key[i];
        }
    }

    return minVertex;

}

void prims_algorithm(int G[N][N], int start) {

    /*
    Finds the minimum spanning tree of a graph (with no negtive edges)
    and prints the MST
    Args:
        G (int[][]) : Adjacency Matrix of the graph
        start (int) : The start vertex

    Returns:
        -
    */


    int visited[N];
    int key[N]; // For each vertex, its key is the minimum distance to a neighbour
    int parent[N];


    // Initializing the vertices
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
        key[i] = INT_MAX;
    }

    // Set the key of the start vertex to 0 and parent to NULL
    key[start] = 0;
    parent[start] = NULL;

    
    for (int i = 0; i < N; i++) {
        // Get the unvisited vertex with the lowest key
        int vertex = findMin(visited, key);

        // Iterate through each of its neighbours
        for (int j = 0; j < N; j++) {
            if (visited[j] == 0 && G[vertex][j] != 0) {
                if (key[j] > G[vertex][j]) {
                    key[j] = G[vertex][j];
                    parent[j] = vertex;
                }
            }
        }    

        visited[vertex] = 1;
    }


    // Print the MST by showing the parent vertex of each vertex

    int sum = 0;
    cout << "Each edge shown with weight with brackets" << endl;
    for (int i = 0; i < N; i++) {
        if (i != start) {
            cout << i << " -- (" << key[i] << ") -- "  << parent[i] << endl;
            sum += key[i];
        }
    }
    cout << "Total weight of MST = " << sum << endl;
}


int main(void) {

    // Running the prims algorithm for the given graph
    // N is defined as the number of vertices in the graph

    int G[N][N] = {
        {0,3,0,0,0,1},
        {3,0,2,1,10,0},
        {0,2,0,3,0,5},
        {0,1,3,0,5,0},
        {0,10,0,5,0,4},
        {1,5,0,0,4,0}
    };

    prims_algorithm(G, 0);

    return 0;
}