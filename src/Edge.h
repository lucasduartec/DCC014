/**************************************************************************************************
 * Implementation of the TAD Edge
 **************************************************************************************************/

#include <string>

using namespace std;

// Definição da classe Edge (Aresta)
class Edge
{
private:
    //attributes 
    int sourceId;
    int targetId;
    string direction; 
    Edge *nextEdge;

public:
    // Construtor
    Edge(int sourceId, int targetId);

    // Destrutor
    ~Edge();

    // Getters
    int getSourceId();
    int getTargetId();
    Edge *getNextEdge();
    string getDirection();

    // Setters
    void setNextEdge(Edge *edge);
    void setDirection(string direction);
};