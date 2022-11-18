/*
 * File: simplegraph.h
 * -------------------
 * This file defines a low-level, structure-based representation for
 * graphs along with basic functions for reading and writing graphs.
 */

#ifndef _simplegraph_h
#define _simplegraph_h

#include <string>
#include "graphtypes.h"
#include "map.h"
#include "set.h"
#include <iostream>
using namespace std;
/*
 * Function: readGraph
 * Usage: readGraph(g, infile);
 * ----------------------------
 * Reads in a simple description of a graph from the input stream.
 */

void readGraph(SimpleGraph & g, std::istream & infile);

/*
 * Function: writeGraph
 * Usage: writeGraph(g, outfile);
 * ------------------------------
 * Writes out a simple description of the graph g to the output stream.
 */

void writeGraph(const SimpleGraph & g, std::ostream & outfile);

#endif
