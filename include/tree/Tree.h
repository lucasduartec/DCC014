/**************************************************************************************************
 * Implementation of the TAD Tree
 **************************************************************************************************/

#include "TreeNode.h"
#include "Graph.h"
#include <iostream>

using namespace std;

class Tree
{
    // attributes
private:
    TreeNode *root;

public:
    // Constructor
    Tree();

    // Destructor
    ~Tree();

    void insert(TreeNode *node);
    void remove(TreeNode *node);
    void backtrackingSearch(Graph *maze);
    boolean backtrackingSearchAux(Node *currentMazeNode, TreeNode *currentState);
    void clearTree();
};

// Construtor
Tree::Tree()
{
    this->root = nullptr;
}

// Destrutor
Tree::~Tree()
{
    this->root = nullptr;
}

void Tree::clearTree()
{
    this->root = nullptr;
}

boolean Tree::backtrackingSearchAux(Node *currentMazeNode, TreeNode *currentState)
{
    if(currentMazeNode->getTag == 0){
        return;
    }

    Edge *edge = currentMazeNode->getFirstEdge();

    while (edge != nullptr)
    {
        // esq
        if (edge->getDirection() == 0)
        {
            TreeNode *newNode = new TreeNode(edge->getTargetId());
            //TODO INSERIR NÓ NA ARVORE
            // this->insert(newNode);

            return backtrackingSearchAux(currentMazeNode, currentState);
        }
        edge = edge->getNextEdge();
    }

    edge = currentMazeNode->getFirstEdge();

    while (edge != nullptr)
    {
        if (edge->getDirection() == 1)
        {
            //faz algo
        }
        edge = edge->getNextEdge();
    }

    edge = currentMazeNode->getFirstEdge();

    while (edge != nullptr)
    {
        if (edge->getDirection() == 2)
        {
            //faz algo
        }
        edge = edge->getNextEdge();
    }

    edge = currentMazeNode->getFirstEdge();

    while (edge != nullptr)
    {
        if (edge->getDirection() == 3)
        {
            //faz algo
        }
        edge = edge->getNextEdge();
    }

}

void Tree::backtrackingSearch(Graph *maze)
{

    if (maze->getFirstNode() == nullptr)
    {
        return;
    }

    // pega id do primeiro nó do labirinto == estado inicial
    Node *currentMazeNode = maze->getFirstNode();
    TreeNode *currentState = new TreeNode(currentMazeNode->getId());
    this->root = currentState;

    backtrackingSearchAux(currentMazeNode, currentState)

   
    // currentState = currentState->getFather();
}