/**************************************************************************************************
 * Implementation of the TAD Tree
 **************************************************************************************************/
#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include "Graph.h"
#include <iostream>
#include <stack>

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
    stack<TreeNode *> backtrackingSearch(Graph *maze);
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

Edge **getAvailableRules(Node *currentMazeNode, Edge *usedRule, TreeNode *currentState)
{
    // Vetor de regras possíveis aplicáveis
    Edge **availableRules = new Edge *[4];

    // Se o nó do labirinto não foi visitado ainda, é necessário setar as suas regras disponiveis
    if (!(currentMazeNode->getVisited()))
    {
        for (int i = 0; i < 4; i++)
        {
            availableRules[i] = nullptr;
        }

        Edge *edge = currentMazeNode->getFirstEdge();

        int index = 0;

        // Preenche vetor de regras com as arestas que saem daquele nó
        while (edge != nullptr && index < 4)
        {
            if (usedRule != nullptr)
            {
                // evita que um nó possua uma aresta para onde veio
                if (!((edge->getDirection() == 0 && usedRule->getDirection() == 2) || ((edge->getDirection() == 1 && usedRule->getDirection() == 3)) || ((edge->getDirection() == 2 && usedRule->getDirection() == 0)) || ((edge->getDirection() == 3 && usedRule->getDirection() == 1))))
                {
                    availableRules[index] = edge;
                }
            }
            else
                availableRules[index] = edge;

            index++;
            edge = edge->getNextEdge();
        }

        // Ordena vetor de regras em ordem crescente (você deve implementar a função de ordenação)
        sortArray(availableRules, 4);
    }
    else
    {
        // Se o nó ja foi visitado, ele precisa apenas puxar de suas propriedades as regras disponiveis.
        availableRules = currentState->getAvailableRules();
    }
    return availableRules;
}

stack<TreeNode *> Tree::backtrackingSearch(Graph *maze)
{
    stack<TreeNode *> pilha;

    if (maze->getFirstNode() != nullptr)
    {
        // pega id do primeiro nó do labirinto == estado inicial
        Node *currentMazeNode = maze->getFirstNode();

        TreeNode *currentState = new TreeNode(currentMazeNode->getId());

        insertRoot(currentState);

        Edge *chosenEdge = nullptr;

        while (currentMazeNode->getTag() != "final")
        {
            Edge **availableRules = getAvailableRules(currentMazeNode, chosenEdge, currentState);

            currentState->setAvailableRules(availableRules);

            // nó puxou as regras, logo foi visitado
            currentMazeNode->setVisited();

            // // Teste de impressão: direções das arestas do nó atual
            // cout << "Antes de usar a regra: " << endl;
            // cout << "Id do nó: " << currentMazeNode->getId() << endl;

            // for (int i = 0; i < 4; i++)
            // {
            //     if (availableRules[i] != nullptr)
            //         cout << availableRules[i]->getDirection() << " ";
            // }
            // cout << endl;

            // contador para verificar se todas as regras são nulas, pois se forem é necessário retornar para o pai
            int count = 0;

            for (int i = 0; i < 4; i++)
            {
                if (availableRules[i] != nullptr)
                {
                    chosenEdge = availableRules[i];

                    // Cria novo nó cujo id é o nó destino daquela aresta no grafo
                    TreeNode *newTreeNode = new TreeNode(chosenEdge->getTargetId());

                    // Insere novo nó na árvore
                    this->insert(currentState, newTreeNode, chosenEdge);

                    // Remove aquela regra da lista de possíveis
                    availableRules[i] = nullptr;

                    // Seta regras disponíveis daquele novo nó
                    currentState->setAvailableRules(availableRules);

                    // Marca a aresta utilizada para chegar até o novo nó
                    newTreeNode->setUsedEdge(chosenEdge);

                    // cout << "Depois de usar a regra: " << endl;
                    // cout << "Id do nó: " << currentMazeNode->getId() << endl;

                    // for (int i = 0; i < 4; i++)
                    // {
                    //     if (availableRules[i] != nullptr)
                    //         cout << availableRules[i]->getDirection() << " ";
                    // }
                    // cout << endl;

                    // Troca nó atual do grafo de acordo com a aresta tomada
                    currentMazeNode = maze->getNodeById(chosenEdge->getTargetId());

                    // Troca nó atual da árvore
                    currentState = newTreeNode;

                    // Pŕoxima iteração
                    break;
                }
                else
                    count++;
            }
            // Se contador == 4 quer dizer que não existe regra disponivel, logo é nescessário dar rollback
            if (count == 4)
            {
                currentState = currentState->getFather();
                currentMazeNode = maze->getNodeById(currentState->getId());
            }
        }

        // coloca todos os nós da busca solução em uma pilha
        while (currentState != this->root)
        {
            pilha.push(currentState);
            currentState = currentState->getFather();
        }
        // add nó inicial
        pilha.push(currentState);
    }

    return pilha;
}

#endif // TREE_H
