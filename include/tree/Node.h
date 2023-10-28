/**************************************************************************************************
 * Implementation of the TAD Node
 **************************************************************************************************/

#include "Edge.h"
#include <list>

using namespace std;

// Definição da classe nó

class Node
{

private:
    Node *father;
    Node *topChild;
    Node *leftChild;
    Node *downChild;
    Node *rightChild;

public:
    // Construtor
    Node();

    // Destrutor
    ~Node();

    // Getters
    Node *getFather();
    Node *getTopChild();
    Node *getLeftChild();
    Node *getDownChild();
    Node *getRightChild();

    // Setters
    Node *setFather();
    Node *setTopChild();
    Node *setLeftChild();
    Node *setDownChild();
    Node *setRightChild();
};