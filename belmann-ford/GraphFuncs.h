/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphFuncs.h
 * Author: igor
 *
 * Created on March 25, 2016, 4:56 AM
 */

#ifndef GRAPHFUNCS_H
#define GRAPHFUNCS_H

#include <vector>
#include <string>
#include "GraphNode.h"

std::vector<GraphNode> assembleGraph(std::string fileName);

void printGraph(std::vector<GraphNode>);


#endif /* GRAPHFUNCS_H */

