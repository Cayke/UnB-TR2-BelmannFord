//
//  BellmanFord.cpp
//  Projeto TR2 Bellman-Ford
//
//  Created by Cayke Prudente on 26/03/16.
//  Copyright © 2016 Cayke Prudente. All rights reserved.
//

#include <stdio.h>
#include <limits>
#include <iostream>
#include "BellmanFord.h"
#include "BellmanFordDistance.h"
#include "ErrorCode.h"

int distanceForNode(int node, std::vector<BFDistance *> d);
void updateBFDistance(int node, int beforeNode, int distance, std::vector<BFDistance *> d);
void printDistanceTable(std::vector<BFDistance *> d);

void bellman_ford(std::vector<GraphNode> graph, int sourceID)
{
    std::vector<BFDistance *> d;
    
    //init
    for (std::vector<GraphNode>::iterator node = graph.begin(); node != graph.end(); ++node)
    {
        BFDistance *element = new BFDistance();
        element->nodeID = node->node;
        element->beforeNode = -1;
        if (element->nodeID == sourceID)
        {
            element->distance = 0;
        }
        else
        {
            element->distance = std::numeric_limits<int>::max();
        }
        
        d.push_back(element);
    }
    
    //apagar
//    std::cout << "\nAntes do relaxamento\n";
//    printDistanceTable(d);
    
    //relaxamento
    for (int completeLaps = 0; completeLaps < d.size() -1; completeLaps++)
    {
        for (int i = 0; i < d.size(); i++)
        {
            GraphNode node = graph.at(i);
            int origem = node.node;
            for (std::vector<GraphCon>::iterator aresta = node.connec.begin(); aresta != node.connec.end(); ++aresta)
            {
                int destino = aresta->node;
                if (aresta->cost == std::numeric_limits<int>::max() || distanceForNode(origem, d)== std::numeric_limits<int>::max())
                {
                    //nao faz nada
                }
                else
                {
                    if (distanceForNode(origem, d) + aresta->cost < distanceForNode(destino, d))
                    {
                        updateBFDistance(destino, origem, distanceForNode(origem, d) + aresta->cost, d);
                    }
                }
            }
            
            //apagar
//            std::cout << "Iteracao " << completeLaps << " Node " << origem << "\n";
//            printDistanceTable(d);
        }
    }
    
    //check negative cicles
    for (int i = 0; i < d.size(); i++)
    {
        GraphNode node = graph.at(i);
        int origem = node.node;
        for (std::vector<GraphCon>::iterator aresta = node.connec.begin(); aresta != node.connec.end(); ++aresta)
        {
            int destino = aresta->node;
            if (distanceForNode(origem, d) + aresta->cost < distanceForNode(destino, d))
            {
                std::cout << "Erro ciclo negativo";
                exit(negativeCicle);
            }
        }
    }
    
    std::cout << "\n\n\n---------------------------------\nTabela de distancias Final\n";
    printDistanceTable(d);
}

int distanceForNode(int node, std::vector<BFDistance *> d)
{
    for (int i = 0; i < d.size(); i++)
    {
        BFDistance *element = d.at(i);
        if (element->nodeID == node)
        {
            if (element->distance < 0) {
                
            }
            return element->distance;
        }
    }
    exit(bfElementNotFound);
}

void updateBFDistance(int node, int beforeNode, int distance, std::vector<BFDistance *> d)
{
    for (int i = 0; i < d.size(); i++)
    {
        BFDistance *element = d.at(i);
        if (element->nodeID == node)
        {
            element->beforeNode = beforeNode;
            element->distance = distance;
            break;
        }
    }
}

void printDistanceTable(std::vector<BFDistance *> d)
{
    for (int i = 0; i < d.size(); i++)
    {
        BFDistance *element = d.at(i);
        std::cout << element->nodeID << ' ' << element->distance << ' ' << element->beforeNode << '\n';
    }

}