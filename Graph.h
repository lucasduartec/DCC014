/**************************************************************************************************
 * Implementation of the TAD Graph
 **************************************************************************************************/

#include "Node.h"
#include <iostream>

using namespace std;

class Graph
{
    // attributes
private:
    Node *firstNode;
    Node *lastNode;
    int nodeIdCounter;

public:
    // Constructor
    Graph(int order, bool directed, bool weightedEdge, bool weightedNode);

    // Destructor
    ~Graph();

    // getters
    int getNodeIdCounter();
    Node *getFirstNode();
    Node *getLastNode();

    // Manipulation methods
    Node *insertNode();
    void insertEdge(Node *sourceNode, Node *targetNode, string direction);

    // Aux methods
    bool searchNode(int id);
    Node *getNodeById(int id);
};