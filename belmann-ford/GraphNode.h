/* 
 * File:   GraphNode.h
 * Author: igor
 *
 * Created on March 25, 2016, 4:35 AM
 */

#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>
#include "GraphCon.h"

class GraphNode {
public:
    int node;
    std::vector<GraphCon> connec;
};

#endif /* GRAPHNODE_H */

