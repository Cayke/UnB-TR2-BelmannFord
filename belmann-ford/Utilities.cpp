/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utilities.cpp
 * Author: igor
 * 
 * Created on March 25, 2016, 3:19 PM
 */

#include "Utilities.h"

bool Utilities::is_number(const std::string &str, int type)
    {
        if(type == 16){
            return str.find_first_not_of("0123456789ABCDEF") == std::string::npos;
        }else if(type == 10){
            return str.find_first_not_of("0123456789") == std::string::npos;
        }

        return false;
    }

void Utilities::SplitString(const std::string s, const char *delim, std::vector<std::string> *out){

        char *dump = strdup(s.c_str());
        char *token = strtok(dump, delim);
        
        while( token != NULL ){
            out->push_back(std::string(token));
            token = strtok(NULL, delim);
        }
        
        free(dump);
        free(token);
    }