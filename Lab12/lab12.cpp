#include <iostream>
using namespace std;

#define N 6

int getMin(int visited[], int avg_time[]) {
    /*
    Returns the unvisited city with least distance to source
    Args:
        visited (int[])  : Array containing city is visited or not, 1 = visited and 0 = not visited
        avg_time (int[]) : Array containing the average time to get to each city from start city
    
    */

    // Initialize the min_time and min_city
    int min_time = INT_MAX;
    int min_city;
    
    // Iterate through the cities and get the unvisited city with smallest time to start
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0 && avg_time[i] < min_time) {
            min_city = i;
            min_time = avg_time[i];
        }
    }

    return min_city;
}


void dijkstra(int G[N][N], int start) {
    /*
    Given the graph and start node, returns the smallest time between 
    each city of the graph and start city
    Args:
        G[][] (int)    : 2D array which represents the adjacency matrix
        start (int)    : The start city

    Returns:
        -
    */

    int time[N];
    int visited[N];
    int parent[N];

    // Initialize the algorithm
    for (int i = 0; i < N; i++) {
        parent[i] = NULL;
        time[i] = INT_MAX;
        visited[i] = 0;
    }

    // Set the distance of start node as 0
    time[start] = 0;

    for (int i = 0; i < N; i++) {
        // Get the unvisited city with the least time from the origin
        int city = getMin(visited, time);

        // Iterate through all the vertices of the graph
        for (int j = 0; j < N; j++) {
            // Make sure the neighbour is not visited and the two cities are connected
            if (visited[j] == 0 && G[city][j] != 0) {
                // Relax the edge
                if (time[j] > time[city] + G[city][j]) {
                    time[j] = time[city] + G[city][j];
                    parent[j] = city;
                }
            }
        }

        visited[city] = 1;

    }

    float total_time = 0;

    // Print the time taken to travel to each city from the start city
    cout << "Starting at city " << start << endl;
    for (int i = 0; i < N; i++) {
        cout << "Distance to City " << i << " : " << time[i] << endl;
        total_time += time[i];

        // Print the path from start city to each city
        int current = i;
        cout << "Path ";
        while (current != start) {
            cout << current << " -> ";
            current = parent[current];
        }
        cout << start << endl;
    }

    // Print the average of the time taken to reach the start city
    float average_time = total_time /  (N - 1);
    cout << "Average time to reach city " << start << " is " << average_time  << endl;

}

int main(void) {
    int G[N][N] = {
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0}
    };


    int parents[N];


    // Run the Dijkstras algorithm taking each city as start city
    for (int i = 0; i < N; i++) {
        dijkstra(G, i);
        cout << "\n\n\n" ;
    }

}