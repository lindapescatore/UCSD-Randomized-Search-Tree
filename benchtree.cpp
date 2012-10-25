//
//  benchtree.cpp
//  P2
//
//  Created by Alexander Kissinger on 10/24/12.
//  Copyright (c) 2012 Alexander Kissinger. All rights reserved.
//

#include "BST.hpp"
#include "RST.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <string.h>
#include <set>

using namespace std;

void bstEval( char* order, double numOfNodes, double numOfTests ){
    //Add Code
}

void rstEval( char* order, double numOfNodes, double numOfTests ){
    //Add Code
}

void setEval( char* order, double numOfNodes, double numOfTests ){
    //Add Code
}

int main(int argc, char** argv) {
    
    if( argc != 5 )
    {
        cout << "Invalid number of arguments\n";
        throw "Invalid number of arguments";
        return -1;
    }

    if( strcmp( argv[2], "sorted" ) != 0 && strcmp( argv[2], "shuffled" ) != 0 )
    {
        cout << argv[2]<< " is an invalid argument.\n";
        throw "Argument 2 is invalid";
        return -1;
    }
    
    double nodes = atof( argv[3] );
    double trials = atof( argv[4] );
    
    if( fmod( sqrt( nodes + 1.0 ), 1.0 ) != 0.0 )
    {
        cout << "Argument 3 must be of root2(n-1)\n";
        throw "Argument 3 must be of root2(n-1)\n";
        return -1;
    }
    if ( strcmp( argv[1], "bst" ) == 0 ) {
        //bstEval( argv[1], nodes, trials );
        cout << "bst\n";
    }
    else if ( strcmp( argv[1], "rst" ) == 0 ) {
        //rstEval( argv[1], nodes, trials );
        cout << "rst\n";
    }
    else if ( strcmp( argv[1], "set" ) == 0 ) {
        //setEval( argv[1], nodes, trials );
        cout << "set\n";
    }
    else
    {
        cout << "Argument 1 must be bst|rst|set. Program is case-sensitive\n";
        throw "Argument 1 must be bst|rst|set. Program is case-sensitive";
        return -1;
    }
    
    return 0;
}