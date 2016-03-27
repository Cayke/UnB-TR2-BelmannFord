/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: igor
 *
 * Created on March 25, 2016, 2:55 AM
 */

#include "GraphFuncs.h"
#include "BellmanFord.h"
#include <cstdlib>
#include <iostream>


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
    //BellmanFord::path(graph, 1, 5);
    BellmanFord::printPath(BellmanFord::path(graph, source, dest));
    printGraph(graph);
    
    return 0;
}

