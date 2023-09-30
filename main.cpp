#include <iostream>
#include "Graph.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Graph *graph = new Graph();

    graph->insertNode("cima");
    graph->insertNode("cima");
    graph->insertNode("cima");

    Node *node = graph->getFirstNode();

    cout << node->getId() << endl;
    
    
    return 0;
}
