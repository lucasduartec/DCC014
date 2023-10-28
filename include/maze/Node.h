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
    unsigned int degree; //verificar se ele já tem o maximo de filhos (4)
    string tag; //inicial ou final 
    string position; //posição para o graphviz

public:
    // Constructor
    Node(int id, string tag, string position);

    // Destructor
    ~Node();

    // Getters
    Edge *getFirstEdge();
    Edge *getLastEdge();
    int getId() const;
    int getDegree();
    Node *getNextNode();
    string getTag();
    string getPosition();

    // Setters
    void setNextNode(Node *node);

    // Other methods
    void incrementDegree();

    // Manipulation methods
    void insertEdge(int sourceId, int targetId, int direction);
};