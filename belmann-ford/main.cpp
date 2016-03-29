#include "GraphFuncs.h"
#include "BellmanFord.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

int main(int argc, char** argv) {
    
    std::string fileName;
    int source, dest;
    std::cout << "Digite nome do arquivo de entrada\n";
    std::cin >> fileName;
    std::cout << "\nPartida\n";
    std::cin >> source;
    std::cout << "\nDestino\n";
    std::cin >> dest;
    
    std::vector<GraphNode> graph = assembleGraph(fileName);
   
    if(source == dest){
        BellmanFord::printMatrix(graph);
    }else{
        BellmanFord::printPath(graph, source, dest);
    }
    //printGraph(graph);
    
    return 0;
}

