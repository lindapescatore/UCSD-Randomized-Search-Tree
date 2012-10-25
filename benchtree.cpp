//
//  benchtree.cpp
//  P2
//
//  Created by Alexander Kissinger on 10/24/12.
//  Copyright (c) 2012 Alexander Kissinger. All rights reserved.
//

#include "BST.hpp"
#include "RST.hpp"
#include <std::set>

int main(int argc, char** argv) {
    
    if( argc != 4 )
    {
        throw "Invalid number of arguments";
        return -1;
    }

    if( *argv[1] != "sorted" || *argv[1] != "shuffled" )
    {
        throw "Argument 2 is invalid";
        return -1;
    }
    //last 2 cases
    
    switch ( *argv[0] ) {
        case "bst":
            bstEval( argv[1], argv[2], argv[3] );
            break;
            
        case "rst":
            rstEval( argv[1], argv[2], argv[3] );
            break;
            
        case "set":
            setEval( argv[1], argv[2], argv[3] );
            break;
            
        default:
            throw "Argument 1 must be bst|rst|set. Program is case-sensitive";
            return -1;
    }
}