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

    void insert(TreeNode *currentState, TreeNode *newTreeNode, Edge *chosenEdge);
    void insertRoot(TreeNode *rootNode);
    void remove(TreeNode *node);
    void backtrackingSearch(Graph *maze);
    void backtrackingSearchAux(Node *currentMazeNode, TreeNode *currentState, Graph *maze);
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

void Tree::insertRoot(TreeNode *rootNode)
{
    this->root = rootNode;
}

void Tree::insert(TreeNode *currentState, TreeNode *newTreeNode, Edge *chosenEdge)
{

    // Seta pai
    newTreeNode->setFather(currentState);

    // Seta filho de acordo com a regra usada
    int directionTaken = chosenEdge->getDirection();
    switch (directionTaken)
    {

    case 0:
        currentState->setTopChild(newTreeNode);
        break;

    case 1:
        currentState->setLeftChild(newTreeNode);
        break;

    case 2:
        currentState->setDownChild(newTreeNode);
        break;

    case 3:
        currentState->setRightChild(newTreeNode);
        break;
    }

    newTreeNode->setUsedEdge(chosenEdge);
}

void Tree::remove(TreeNode *node)
{
    int rule = node->getUsedEdge()->getDirection();

    switch (rule)
    {
    case 0:
        node->getFather()->setTopChild(nullptr);
        break;

    case 1:
        node->getFather()->setLeftChild(nullptr);
        break;

    case 2:
        node->getFather()->setDownChild(nullptr);
        break;

    case 3:
        node->getFather()->setRightChild(nullptr);
        break;
    }

    node = nullptr;
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

void Tree::backtrackingSearch(Graph *maze)
{
    if (maze->getFirstNode() == nullptr)
    {
        return;
    }

    // pega id do primeiro nó do labirinto == estado inicial
    Node *currentMazeNode = maze->getFirstNode();

    TreeNode *currentState = new TreeNode(currentMazeNode->getId());

    insertRoot(currentState);

    while (currentMazeNode->getTag() != "final")
    {

        // Vetor de regras possíveis aplicáveis
        Edge *availableRules[4] = {nullptr, nullptr, nullptr, nullptr};

        Edge *edge = currentMazeNode->getFirstEdge();

        int index = 0;

        // Preenche vetor de regras com as arestas que saem daquele nó
        while (edge != nullptr && index < 4)
        {
            availableRules[index] = edge;
            index++;
            edge = edge->getNextEdge();
        }

        // Ordena vetor de regras em ordem crescente
        sortArray(availableRules, 4);

        currentState->setAvailableRules(availableRules);

        // Teste de impressão: direções das arestas do nó atual
        cout << "Antes de usar a regra: " << endl;
        cout << "Id do nó: " << currentMazeNode->getId() << endl;
        for (int i = 0; i < 4; i++)
        {
            if (availableRules[i] != nullptr)
                cout << availableRules[i]->getDirection() << " ";
        }
        cout << endl;

        for (int i = 0; i < 4; i++)
        {
            if (availableRules[i] != nullptr)
            {
                Edge *chosenEdge = availableRules[i];

                // Cria novo nó cujo id é o nó destino daquela aresta no grafo
                TreeNode *newTreeNode = new TreeNode(chosenEdge->getTargetId());

                // Insere novo nó na árvore
                this->insert(currentState, newTreeNode, chosenEdge);

                // Remove aquela regra da lista de possíveis
                availableRules[i] = nullptr;

                // Seta regras disponíveis daquele novo nó
                newTreeNode->setAvailableRules(availableRules);

                cout << "Depois de usar a regra: " << endl;
                cout << "Id do nó: " << currentMazeNode->getId() << endl;
                for (int i = 0; i < 4; i++)
                {
                    if (availableRules[i] != nullptr)
                        cout << availableRules[i]->getDirection() << " ";
                }
                cout << endl;

                currentMazeNode = maze->getNodeById(chosenEdge->getTargetId());
                
            }
        }
    }
}

#endif // TREE_H
