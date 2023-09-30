/**************************************************************************************************
 * Implementation of the TAD Node
 **************************************************************************************************/

#include "Edge.h"
#include <list>

using namespace std;

// Definição da classe nó

class Node
{
    // attributes
private:
    Edge *firstEdge;
    Edge *lastEdge;
    int id;
    Node *nextNode;
    unsigned int degree;
    string tag;

public:
    // Constructor
    Node(int id, string tag);

    // Destructor
    ~Node();

    // Getters
    Edge *getFirstEdge();
    Edge *getLastEdge();
    int getId() const;
    int getDegree();
    Node *getNextNode();
    string getTag();

    // Setters
    void setNextNode(Node *node);

    // Other methods
    void incrementDegree();

    // Manipulation methods
    void insertEdge(int sourceId, int targetId, string direction);
};