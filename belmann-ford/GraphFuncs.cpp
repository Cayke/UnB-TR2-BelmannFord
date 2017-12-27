#include "GraphFuncs.h"
#include "GraphCon.h"
#include "ErrorCode.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

std::vector<GraphNode> assembleGraph(std::string fileName){
    
    std::ifstream graphFile;
    std::string str;
    GraphNode n;
    GraphCon gc;
    std::vector<GraphNode> Nodes;
    
    try{
        graphFile.open(fileName.c_str(), std::ifstream::in);
    }catch(const std::ios_base::failure& e){
        std::cerr << e.what() << '\n';
        std::cout << "Erro ao abrir arquivo\n";
        exit(openfileError);
    }
    
    while(!graphFile.eof()){
        
        std::vector<std::string> *out = new std::vector<std::string>();
        std::vector<std::string> *outaux = new std::vector<std::string>();
        n.connec.clear();
        out->clear();
        outaux->clear();
        
        try{
            getline(graphFile, str);
        }catch(const std::ios_base::failure& e){
            free(out);
            free(outaux);
            std::cerr << e.what() << '\n';
            exit(inconsistencyFile);
        }
        
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        std::size_t found = str.find("-"); 
        if(found == std::string::npos){
            std::cout << "Inconsistency file: Missing '-' separator";
            exit(inconsistencyFile);
        }
        str.replace(found, 1, "@");
        Utilities::SplitString(str, "@", out);
                
        try{
            if(!Utilities::is_number(out->at(0), 10)){
                std::cout << "Inconsistency file:" << out->at(0) << "not a number";
                exit(inconsistencyFile);
            }
        }catch(const std::out_of_range& e){
            free(out);
            free(outaux);
            std::cerr << e.what() << '\n';
            exit(stringError);
        }
        
        n.node = std::stoi(out->at(0));
                
        Utilities::SplitString(out->at(1), ";", outaux);
        out->clear();
        
        for(unsigned int i = 0; i < outaux->size(); i++){
            Utilities::SplitString(outaux->at(i), "[", out);         
            gc.node = std::stoi(out->at(0));           
            out->at(1).erase(remove(out->at(1).begin(), out->at(1).end(), ']'), out->at(1).end());
            gc.cost = std::stoi(out->at(1));
            n.connec.push_back(gc);
            out->clear();
        }
        
        free(out);
        free(outaux);
        Nodes.push_back(n);
    }
    
    return Nodes;
}

void printNode(GraphNode node){
    
    std::cout << node.node << '-'; 
    
    for(std::vector<GraphCon>::iterator gc = node.connec.begin(); gc != node.connec.end(); ++gc){
        std::cout << gc->node << '[' << gc->cost << ']' << ';';
    }
    
    std::cout << '\n';
}

