#include "Graph.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <string.h>
#include <cfloat>
using namespace std;

// Variável global para armazenar um caminho

// std::string pathGlobal = "/home/rodrigosoares/codigos/Faculdade/5 Periodo/IA/maze";

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

void writeGraphOnOutputFile(Graph *graph)
{
    // Especifique o caminho completo para a pasta onde deseja salvar o arquivo "output.dot"
    std::string outputPath = pathGlobal + "/output.dot"; // Substitua pelo caminho desejado

    // Abra o arquivo "output.dot" no caminho especificado e apague o conteúdo antigo
    std::ofstream outputFile(outputPath, std::ios::trunc);

    if (outputFile.is_open())
    {
        // Chame a função exportGraphToDotFormat e escreva o resultado no arquivo
        outputFile << exportGraphToDotFormat(graph);

        // Feche o arquivo
        outputFile.close();
    }
    else
    {
        std::cerr << "Erro ao abrir o arquivo 'output.dot'." << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    Graph *graph = new Graph();
    graph->generateMaze();

    writeGraphOnOutputFile(graph);

    delete graph;

    return 0;
}
