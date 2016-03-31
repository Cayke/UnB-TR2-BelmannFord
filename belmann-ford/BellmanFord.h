#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "GraphNode.h"
#include "GraphCon.h"
#include "Structs.h"
#include "Path.h"
#include <list>

class BellmanFord {
public:
    
    /**
    * \brief Printa o caminho para um nó
    * \param[in] vector GraphNode
    * \param[in] Destino
    * \param
    * */
    static void printPath(std::vector<GraphNode> , int, int );
    
    /**
    * \brief Printa a matriz de distâncias
    * \param[in] vector GraphNode
    * */
    static void printMatrix(std::vector<GraphNode> );
    
private:
    
    /**
    * \brief Inicializa o vetor que ira conter o custo para cada nó com infinito
    * \param[in] vector GraphNode
    * \param[in] Destino
    * */
    static std::vector<Path> initializePath(std::vector<GraphNode> , int);
    
    /**
    * \brief CAlcula o custo para cada nó
    * \param[in] Vector GraphNode
    * \param[in] Fonte
    * \param[in] Bool utilizado para printar ou não printar o numéro de interecoes
    * */
    static std::vector<Path> path(std::vector<GraphNode>, int, bool);
    
    /**
    * \brief Monta o caminho da fonte para o destino
    * \param[in] Vector Path
    * \param[in] Fonte
    * \param[in] Destino
    * */
    static std::list<Path> assemblePath(std::vector<Path> path, int , int);
    
};

#endif /* BELLMANFORD_H */

