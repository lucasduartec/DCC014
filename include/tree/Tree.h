/**************************************************************************************************
 * Implementation of the TAD Tree
 **************************************************************************************************/
#ifndef TREE_H
#define TREE_H

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
    bool backtrackingSearchAux(Node *currentMazeNode, TreeNode *currentState);
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

void sortArray(Edge *edges[], int numEdges)
{
    // Bubble sort
    for (int i = 0; i < numEdges - 1; i++)
    {
        for (int j = 0; j < numEdges - i - 1; j++)
        {
            if (edges[j] != nullptr && edges[j + 1] != nullptr &&
                edges[j]->getDirection() > edges[j + 1]->getDirection())
            {
                Edge *temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

bool Tree::backtrackingSearchAux(Node *currentMazeNode, TreeNode *currentState)
{
    if (currentMazeNode->getTag() == "final")
    {
        return true;
    }

    Edge *availableRules[4] = {nullptr, nullptr, nullptr, nullptr};
    int index = 0;

    Edge *edge = currentMazeNode->getFirstEdge();

    while (edge != nullptr && index < 4)
    {
        availableRules[index] = edge;
        index++;
        edge = edge->getNextEdge();
    }

    sortArray(availableRules, 4);

    // Direções das arestas do nó atual
    // cout << currentMazeNode->getId() << endl;
    // for (int i = 0; i < 4; i++)
    //{
    //    if (availableRules[i] != nullptr)
    //        cout << availableRules[i]->getDirection() << " ";
    //}

    for (int i = 0; i < 4; i++)
    {
        if (availableRules[i] != nullptr)
        {
            TreeNode *newTreeNode = new TreeNode(availableRules[i]->getDirection());
        }
    }

    return false;
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

    backtrackingSearchAux(currentMazeNode, currentState);

    // currentState = currentState->getFather();
}

#endif // TREE_H
