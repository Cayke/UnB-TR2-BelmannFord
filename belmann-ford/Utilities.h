/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utilities.h
 * Author: igor
 *
 * Created on March 25, 2016, 3:19 PM
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>
#include <cstring>
#include <stdlib.h>

class Utilities {

public:
    static bool is_number(const std::string &str, int type);
    
    static void SplitString(const std::string s, const char *delim, std::vector<std::string> *out);
    
};

#endif /* UTILITIES_H */

