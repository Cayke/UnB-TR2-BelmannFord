/**
 * 
 * Igor Fernandes Miranda 11/0013255 
 * Cayke Gabriel dos Santos Prudente 11/0112491
 */

#include "GraphFuncs.h"
#include "BellmanFord.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

int main(int argc, char** argv) {
    
    std::string fileName = "test.txt";
    int source = 1, dest = 4, op = 2;
    
    std::cout << "Digite nome do arquivo de entrada\n";
    std::cin >> fileName;
    std::vector<GraphNode> graph = assembleGraph(fileName);
            
    std::cout << "1->Caminho de fonte ao destino\n";
    std::cout << "2->Matriz custo\n";
    std::cin >> op;
    
    switch(op){
        case 1:
            std::cout << "\nPartida\n";
            std::cin >> source;
            std::cout << "\nDestino\n";
            std::cin >> dest;
            BellmanFord::printPath(graph, source, dest);
            break;
        case 2:
            BellmanFord::printMatrix(graph);
            break;
        default:
            BellmanFord::printMatrix(graph);
    }
    //printGraph(graph);
    
    return 0;
}

