#include "BellmanFord.h"
#include "ErrorCode.h"
#include <algorithm>
#include <iostream>

std::vector<Path> BellmanFord::path(std::vector<GraphNode> graph, int source, bool printInte = false) {
    
    std::vector<Path> path = initializePath(graph, source);
    
    bool change = false;
    
    for(unsigned int i = 0; i <= graph.size(); i++){
        for(unsigned int j = 0; j < graph.size(); j++){
            
            std::vector<Path>::iterator itCN = std::find_if(path.begin(), path.end(), [=](Path item) {//lambda
                return item.node == graph.at(j).node;
            });
            
            int locateCurrentNode = std::distance( path.begin(), itCN);
            if(path.at(locateCurrentNode).cost != INF){
                for(unsigned int k = 0; k < graph.at(j).connec.size(); k++){
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
            std::cout << "\nNegative Cicle\n";
            exit(negativeCicle);
        }if(!change){
            if(printInte)std::cout << i << " interacoes de " << graph.size() - 1 << "\n";
            break;
        }else{
            change = false;
        }
        
        
    }
    
    return path;
}

std::list<Path> BellmanFord::assemblePath(std::vector<Path> path, int source, int dest){
    
    std::list<Path> pathRet;
    
    //Montando caminho para retorno
    std::vector<Path>::iterator it =  std::find_if(path.begin(), path.end(), [=](Path item) {//lambda
                        return item.node == dest;
    });
    int icurrent = std::distance( path.begin(), it);
    
    if(path.at(icurrent).cost == INF){
        return pathRet;
    }
    
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

void BellmanFord::printPath(std::vector<GraphNode> graph, int source, int dest){
    
    std::list<Path> path = BellmanFord::assemblePath(BellmanFord::path(graph, source, true), source, dest);
    
    if(path.empty()){
        std::cout << "\nSem caminho\n";
        return;
    }
    
    while(!path.empty()){
        std::cout << path.front().node << "[" << path.front().cost << "]";
        path.pop_front();
        if(!path.empty()){
            std::cout << " -> ";
        }else{
            std::cout << "\n";
        }
    }
}

void BellmanFord::printMatrix(std::vector<GraphNode> graph){
    
    
        std::cout << "\n|___|";
        for(unsigned int i = 0; i < graph.size(); i++){
            if(graph.at(i).node < 10){
                std::cout << " " << graph.at(i).node << " |";      
            }else if(graph.at(i).node < 100){
                std::cout << graph.at(i).node << " |"; 
            }else{
                std::cout << graph.at(i).node << "|"; 
            }  
        }
        std::cout << "\n";
                
        for(unsigned int i = 0; i < graph.size(); i++){
            
            if(graph.at(i).node < 10){
                std::cout << "| ";
                std::cout << graph.at(i).node << " |";
            }else if(graph.at(i).node <100){
                std::cout << "|";
                std::cout << graph.at(i).node << " |";
            }else{
                std::cout << "|";
                std::cout << graph.at(i).node << "|";
            }
            
            for(unsigned int j = 0; j < graph.size(); j++){
                std::list<Path> path = BellmanFord::assemblePath(BellmanFord::path(graph, graph.at(i).node), graph.at(i).node, graph.at(j).node);
                if(path.empty()){
                    std::cout << " I |"; 
                }else{
                    if(path.back().cost < 0){
                        std::cout << path.back().cost << " |";
                    }
                    else if(path.back().cost < 10){
                        std::cout << " " << path.back().cost << " |";      
                    }else if(path.back().cost < 100){
                        std::cout << path.back().cost << " |"; 
                    }else{
                        std::cout << path.back().cost << "|"; 
                    }    
                }
            }
            std::cout << "\n";
        }
}

std::vector<Path> BellmanFord::initializePath(std::vector<GraphNode> graph, int source){
    
    std::vector<Path> path;
    
    for(int i = 0; i < graph.size(); i++){
        Path p;
        if(graph.at(i).node == source){
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
