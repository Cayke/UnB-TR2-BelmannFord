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
#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    string fileName;
    cout << "Digite nome do arquivo de entrada\n";
    cin >> fileName;
    
    std::vector<GraphNode> graph = assembleGraph(fileName);
    printGraph(graph);
    
    return 0;
}

