#include "Graph.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <cfloat>
using namespace std;

/****************
 * Funcao    : string formatFloat(float value, int precision, int totalLength)  	                *
 * Descricao : Converte float para string com parâmteros especificados                              *
 * Parametros: value - valor em float a ser formatado                                               *
 *             precision - precisão das casas decimais                                              *
 *             totalLength - comprimento total da string retornada                                  *
 * Retorno   : string formatada.                                                                    *
 ***************/
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

/****************
 * Funcao    : string exportGraphToDotFormat(Graph *graph, bool isPERT) 	                        *
 * Descricao : Cria string com a descrição de um grafo no formato .DOT                              *
 * Parametros: graph - objeto do tipo Graph, de que as informações serão extraídas                  *
 *             isPERT - define se o grafo pode ser utilizado para Rede PERT, ou seja, é multiaresta *
 * Retorno   : descrição no formato .DOT.                                                           *
 ***************/
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
    while (nextNode != nullptr)
    {
        dot += "  " + to_string(nextNode->getId()) +
               " [weight = " + formatFloat(nextNode->getId(), 2, 5) + "]";
        // if (weightedNode)
        //     dot += " [xlabel = " + formatFloat(nextNode->getWeight(), 0, 5) + "]";
        dot += ";\n";
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

int main(int argc, char const *argv[])
{
    Graph *graph = new Graph();

    Node *node0 = graph->insertNode("inicial");
    Node *node1 = graph->insertNode("intermediario");
    Node *node2 = graph->insertNode("intermediario");
    Node *node3 = graph->insertNode("final");

    graph->insertEdge(node0, node1, "cima");
    graph->insertEdge(node0, node2, "baixo");
    graph->insertEdge(node1, node2, "baixo");
    graph->insertEdge(node2, node3, "baixo");

    cout << exportGraphToDotFormat(graph);

    return 0;
}
