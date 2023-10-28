/**************************************************************************************************
 * Implementation of the TAD Tree
 **************************************************************************************************/

#include "Node.h"
#include <iostream>

using namespace std;

class Tree
{
    // attributes
private:
    Node *firstNode;
    Node *lastNode;
    int nodeIdCounter;

public:
    // Constructor
    Tree();

    // Destructor
    ~Tree();

    // getters
    int getNodeIdCounter();
    Node *getFirstNode();
    Node *getLastNode();

    // Manipulation methods
    Node *insertNode(string tag, string position);
    void insertEdge(Node *sourceNode, Node *targetNode, int direction);

    // Aux methods
    bool searchNode(int id);
    Node *getNodeById(int id);
    void displayTree();

    void generateMaze();
};