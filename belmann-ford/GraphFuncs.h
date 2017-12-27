#ifndef GRAPHFUNCS_H
#define GRAPHFUNCS_H

#include <vector>
#include <string>
#include "GraphNode.h"

/**
 * \brif Faz a leitura do arquivo e monta o grafo em memória
 * \param[in] fileName -> nome do arquivo
 * */
std::vector<GraphNode> assembleGraph(std::string fileName);

/**
 * \Para teste
 * */
void printGraph(std::vector<GraphNode>);


#endif /* GRAPHFUNCS_H */

