#include "include/maze/Graph.h"
#include "include/tree/Tree.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <string.h>
#include <cfloat>
using namespace std;

string formatFloat(float value, int precision, int totalLength)
{
    string returnString = "";
    if (value == FLT_MAX)
        returnString = "&";
    else
    {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(precision) << value;
        returnString = stream.str();
    }
    int missingSpaces = totalLength - returnString.length();
    if (missingSpaces > 0)
        returnString.insert(0, missingSpaces, ' ');
    return returnString;
}

string exportGraphToDotFormat(Graph *graph)
{ // dot -Tpng output.dot -o graph1.png
    if (graph == nullptr)
        return "";

    Node *nextNode = graph->getFirstNode();
    string dot = "", connector;
    // bool weightedNode = graph->getWeightedNode();
    // bool weightedEdge = graph->getWeightedEdge();

    dot += "strict ";

    if (false)
    {
        connector = " -> ";
        dot += "di";
    }
    else
        connector = " -- ";

    dot += "graph grafo {\n";
    char aspasDuplas = '"';
    while (nextNode != nullptr)
    {
        dot += "  " + to_string(nextNode->getId()) +
               " [weight = " + formatFloat(nextNode->getId(), 2, 5) +
               ", pos = " + aspasDuplas + nextNode->getPosition() + "!" + aspasDuplas;

        if (nextNode->getTag() == "inicial")
            dot += ", color = red";

        if (nextNode->getTag() == "final")
            dot += ", color = green";

        dot += "];\n";

        nextNode = nextNode->getNextNode();
    }
    nextNode = graph->getFirstNode();
    while (nextNode != nullptr)
    {
        Edge *nextEdge = nextNode->getFirstEdge();
        while ((nextEdge != nullptr))
        {
            if ((nextNode->getId() != graph->getNodeById(nextEdge->getTargetId())->getId()))
            {
                dot += "\n  " + to_string(nextNode->getId()) + connector +
                       to_string(graph->getNodeById(nextEdge->getTargetId())->getId());
                // if (weightedEdge)
                // {
                //     dot += " [weight = " + formatFloat(nextEdge->getWeight(), 2, 5) +
                //            "] [label = " + formatFloat(nextEdge->getWeight(), 2, 5) + "];";
                // }
            }
            nextEdge = nextEdge->getNextEdge();
        }
        nextNode = nextNode->getNextNode();
    }
    dot += "\n}\n";

    return dot;
}

string exportTreeToDotFormat(Tree *tree)
{
    if (tree == nullptr || tree->getRoot() == nullptr)
        return "";

    TreeNode *rootNode = tree->getRoot();
    string dot = "strict digraph tree {\nrankdir=TB;\n";

    // Traverse the tree and add nodes
    tree->traverseAndPrint(rootNode, dot);

    // Close the graph
    dot += "}\n";

    return dot;
}

void writeOutputFile(Graph *graph, Tree *searchTree, int option)
{
    // Especifique o caminho completo para a pasta onde deseja salvar o arquivo "output.dot"
    std::string outputPath;

    if (option == 0)
        outputPath = "../graph.dot";
    else
        outputPath = "../tree.dot";

    // Abra o arquivo "output.dot" no caminho especificado e apague o conteúdo antigo
    std::ofstream outputFile(outputPath, std::ios::trunc);

    if (outputFile.is_open())
    {
        // Chame a função exportGraphToDotFormat e escreva o resultado no arquivo
        if (option == 0)
            outputFile << exportGraphToDotFormat(graph);
        else
            outputFile << exportTreeToDotFormat(searchTree);

        // Feche o arquivo
        outputFile.close();
    }
    else
    {
        std::cerr << "Erro ao abrir o arquivo 'output.dot'." << std::endl;
    }
}

void printSolution(stack<TreeNode *> pilha, string search)
{

    cout << search << " Search solution :" << endl;

    while (!pilha.empty())
    {
        TreeNode *node = pilha.top();
        pilha.pop();

        if (pilha.size() != 0)
        {
            cout << node->getId() << " -> ";
        }
        else
            cout << node->getId() << " ";
    }
}

int main(int argc, char const *argv[])
{
    Graph *maze = new Graph();
    maze->generateMaze();

    Tree *searchTree = new Tree();
    stack<TreeNode *> solution = searchTree->backtrackingSearch(maze);

    writeOutputFile(maze, searchTree, 0);
    writeOutputFile(maze, searchTree, 1);

    printSolution(solution, "breadthFirstSearch");

    // searchTree->traverseAndPrint();

    delete maze;
    delete searchTree;

    return 0;
}
