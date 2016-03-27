/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BellmanFord.cpp
 * Author: igor
 * 
 * Created on March 26, 2016, 8:00 PM
 */

#include "BellmanFord.h"
#include "ErrorCode.h"
#include <algorithm>
#include <iostream>

std::list<Path> BellmanFord::path(std::vector<GraphNode> graph, int source, int dest) {
    
    std::vector<Path> path = initializePath(graph, source);
    std::list<Path> pathRet;
    bool change = false;
    
    for(int i = 0; i <= graph.size(); i++){
        for(int j = 0; j < graph.size(); j++){
            
            std::vector<Path>::iterator itCN = std::find_if(path.begin(), path.end(), [=](Path item) {//lambda
                return item.node == graph.at(j).node;
            });
            
            int locateCurrentNode = std::distance( path.begin(), itCN);
            if(path.at(locateCurrentNode).cost != INF){
                for(int k = 0; k < graph.at(j).connec.size(); k++){
                    std::vector<Path>::iterator itNN =  std::find_if(path.begin(), path.end(), [=](Path item) {//lambda
                        return item.node == graph.at(j).connec.at(k).node;
                    });
                    int locateNextNode = std::distance( path.begin(), itNN);
                    if(path.at(locateCurrentNode).cost + graph.at(j).connec.at(k).cost < path.at(locateNextNode).cost){
                        path.at(locateNextNode).cost = path.at(locateCurrentNode).cost + graph.at(j).connec.at(k).cost;
                        path.at(locateNextNode).from = graph.at(j).node;
                        change = true;
                    } 
                }               
            }            
        }
        if(i == graph.size() && change){
            std::cout << "Negative Cicle\n";
            exit(negativeCicle);
        }else{
            change = false;
        }
    }
    
    std::vector<Path>::iterator it =  std::find_if(path.begin(), path.end(), [=](Path item) {//lambda
                        return item.node == dest;
    });
    int icurrent = std::distance( path.begin(), it);
    
    it =  std::find_if(path.begin(), path.end(), [=](Path item) {//lambda
                        return item.node == source;
    });
    int isource = std::distance( path.begin(), it);
    
    while(icurrent != isource){
        pathRet.push_front(path.at(icurrent));
        it =  std::find_if(path.begin(), path.end(), [=](Path item) {//lambda
                        return item.node == path.at(icurrent).from;
        });
        icurrent = std::distance( path.begin(), it);
    }
    it =  std::find_if(path.begin(), path.end(), [=](Path item) {//lambda
                        return item.node == source;
    });
    
    pathRet.push_front(path.at(icurrent));
    return pathRet;
}

void BellmanFord::printPath(std::list<Path> path){
    
    while(!path.empty()){
        std::cout << path.front().node;
        path.pop_front();
        if(!path.empty()){
            std::cout << " -> ";
        }else{
            std::cout << "\n";
        }
    }
}


std::vector<Path> BellmanFord::initializePath(std::vector<GraphNode> graph, int source){
    
    std::vector<Path> path;
    
    for(int i = 0; i < graph.size(); i++){
        Path p;
        if(i + 1 == source){
            p.cost = 0;
        }else{
            p.cost = INF;
        }
        
        p.node = graph.at(i).node;
        p.from = -1;
        
        path.push_back(p);
    }
    
    return path;
}
