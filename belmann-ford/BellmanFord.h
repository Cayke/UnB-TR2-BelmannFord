/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BellmanFord.h
 * Author: igor
 *
 * Created on March 26, 2016, 8:00 PM
 */

#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "GraphNode.h"
#include "GraphCon.h"
#include "Structs.h"
#include "Path.h"
#include <list>

class BellmanFord {
public:
    
    static std::list<Path> path(std::vector<GraphNode>, int, int);
    static void printPath(std::list<Path>);
private:
    
    static std::vector<Path> initializePath(std::vector<GraphNode> , int);
    
};

#endif /* BELLMANFORD_H */

