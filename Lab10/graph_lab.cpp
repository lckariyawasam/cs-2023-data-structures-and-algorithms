#include <iostream>
#include<list>
using namespace std;

struct Node{
    // A node will 2 entities
    //1. data type int called label
    //2. a int type list called neighbours

    int label;
    list<int> neighbours;

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=8;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){

            // The code provided here has been changed to address an issue
            // Here the loop goes from 0 to n-1 but the labels go from 1-8
            // Therefore it is modified to hold each label at the (label - 1) index
            // nodes[0] = 1, nodes[1] = 2 etc

            nodes[i].label=i+1;
        }
    }

    void addedge(int u, int v){
        //select node u and push v into u's neighbour

        // *** Here u-1 index is used due to the reason mentioned above within the initializenodes function
        nodes[u-1].neighbours.push_back(v);

        //select node v and push u into v's neighbour

        // *** Here v-1 index is used due to the reason mentioned above within the initializenodes function
        nodes[v-1].neighbours.push_back(u);
    }

    void print(){
        //lets iterate through each node and print its neighbours

        for (int i = 0; i < n; i++) {
            cout << nodes[i].label << " -> ";
            // Iterate through each of the neighbours and print
            for (int neighbour : nodes[i].neighbours) {
                cout << neighbour << " ";
            }
            cout << endl;
        }

    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
    g->addedge(1,2);
    g->addedge(1,3);
    g->addedge(1,4);
    g->addedge(1,5);
    g->addedge(2,3);
    g->addedge(2,6);
    g->addedge(4,6);
    g->addedge(4,7);
    g->addedge(4,8);
    g->addedge(5,6);
    g->addedge(5,7);
    g->addedge(5,8);


    //print the graph adjaceny list
    g->print();
}
