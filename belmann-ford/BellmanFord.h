#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "GraphNode.h"
#include "GraphCon.h"
#include "Structs.h"
#include "Path.h"
#include <list>

class BellmanFord {
public:
    
    static void printPath(std::vector<GraphNode> , int, int );
    static void printMatrix(std::vector<GraphNode> );
    
private:
    
    static std::vector<Path> initializePath(std::vector<GraphNode> , int);
    static std::vector<Path> path(std::vector<GraphNode>, int, bool);
    static std::list<Path> assemblePath(std::vector<Path> path, int , int);
    
};

#endif /* BELLMANFORD_H */

