
//
//  benchtree.cpp
//  P2
//
//  Created by Alexander Kissinger on 10/24/12.
//  Copyright (c) 2012 Alexander Kissinger. All rights reserved.
//

#include "BST.hpp"
#include "RST.hpp"
#include "countint.hpp"
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

double processBST( std::vector<countint> v, double N )
{
    BST<countint> s = BST<countint>();
    
    /* Insert keys into instantiated data struct */
    std::vector<countint>::iterator vit = v.begin();
    std::vector<countint>::iterator ven = v.end();
    
    for(vit = v.begin(); vit != ven; ++vit) {
        s.insert(*vit);
    }
    
    /* Calc num of comparisons */
    countint::clearcount();
    for(vit = v.begin(); vit != ven; ++vit) {
        s.find(*vit);
    }
    return countint::getcount()/N;
}

double processRST( std::vector<countint> v, double N )
{
    RST<countint> s = RST<countint>();
    
    /* Insert keys into instantiated data struct */
    std::vector<countint>::iterator vit = v.begin();
    std::vector<countint>::iterator ven = v.end();
    
    for(vit = v.begin(); vit != ven; ++vit) {
        s.insert(*vit);
    }
    
    /* Calc num of comparisons */
    countint::clearcount();
    for(vit = v.begin(); vit != ven; ++vit) {
        s.find(*vit);
    }
    double avg = countint::getcount()/N;
    return avg;
}

double processSET( std::vector<countint> v, double N )
{
    set<countint> s = set<countint>();
    
    /* Insert keys into instantiated data struct */
    std::vector<countint>::iterator vit = v.begin();
    std::vector<countint>::iterator ven = v.end();
    
    for(vit = v.begin(); vit != ven; ++vit) {
        s.insert(*vit);
    }
    
    /* Calc num of comparisons */
    countint::clearcount();
    for(vit = v.begin(); vit != ven; ++vit) {
        s.find(*vit);
    }
    return countint::getcount()/N;
}

int main(int argc, char** argv) {
    
    /* Check for invalid num of args */
    if( argc != 5 )
    {
        cout << "Invalid number of arguments\n";
        throw "Invalid number of arguments";
        return -1;
    }

    /* Check for valid 2nd arg */
    if( strcmp( argv[2], "sorted" ) != 0
       && strcmp( argv[2], "shuffled" ) != 0 )
    {
        cout << argv[2]<< " is an invalid argument.\n";
        throw "Argument 2 is invalid";
        return -1;
    }
    
    /* If those pass, then make some locals */
    int nodes = atof( argv[3] );
    double trials = atof( argv[4] );
    double avgComp = 0;
    double avgCompSq = 0;
    
    /* If initial checks pass, print HEADER */
    cout << "# Benchmarking average number of comparisons "
        << "for successful find\n";
    cout << "# Data structure: " << argv[1] << endl;
    cout << "# Data: " << argv[2] << endl;
    cout << "# N is powers of 2, minus 1, from 1 to " << nodes << endl;
    cout << "# Averaging over " << trials << " runs for each N\n";
    cout<< "#\n# N 	 avgcomps 	 stdev\n";
    
    /* Start tests j=1, k=2^j, until k>=trials */
    double j = 1;
    double k = pow( 2, j );
    int done = 0;
    
    while( !done )
    {
        /* Last case */
        if( k-1 > nodes || k-1 == nodes )
            break;
        
        /* Prep counint vectors as counters */
        std::vector<countint> v;
        v.clear();
        for(int i=0; i<(int)k-1; ++i) {
            v.push_back(i);
        }
        
        /* Instantiate struct to be tested */
        double ti = 0;
        if ( strcmp( argv[1], "bst" ) == 0 )
            for( int i = 0; i<trials; i++ )
            {
                /* Randomize the inputs */
                if( strcmp( argv[2], "shuffled" ) == 0 )
                    std::random_shuffle(v.begin(),v.end());
                ti = processBST( v, (int)k-1 );
                avgComp += ti;
                avgCompSq += ti * ti;
            }
        else if ( strcmp( argv[1], "rst" ) == 0 )
            for( int i = 0; i<trials; i++ )
            {
                /* Randomize the inputs */
                if( strcmp( argv[2], "shuffled" ) == 0 )
                    std::random_shuffle(v.begin(),v.end());
                ti = processRST( v, (int)k-1 );
                avgComp += ti;
                avgCompSq += ti * ti;
            }
        else if ( strcmp( argv[1], "set" ) == 0 )
            for( int i = 0; i<trials; i++ )
            {
                /* Randomize the inputs */
                if( strcmp( argv[2], "shuffled" ) == 0 )
                    std::random_shuffle(v.begin(),v.end());
                ti = processSET( v, (int)k-1 );
                avgComp += ti;
                avgCompSq += ti * ti;
            }
        else
        {
            cout << "Argument 1 must be bst|rst|set. Program is case-sensitive\n";
            throw "Argument 1 must be bst|rst|set. Program is case-sensitive";
            return -1;
        }
        
        /*Calc STD-DEV */
        avgComp = avgComp/trials;
        avgCompSq = avgCompSq/trials;
        double stdDev = sqrt( abs( avgCompSq - ( avgComp * avgComp ) ) );

        /* Print Output */
        printf( "%6i\t " , (int)k-1 );
        printf( "%-6f\t ", avgComp );
        printf( "%-7.6f\n", stdDev );
        
        j++;
        k = pow( 2, j );
        
    }

    
    return 0;
}