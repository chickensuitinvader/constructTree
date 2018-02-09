#ifndef DGRAPHP_LIB_H
#define DGRAPHP_LIB_H
#include <iostream>
#include "dgraphp.h"
#include "dgraph_factory.h"
using namespace std;
/* Directed Graph Provider Class Library
 * ----------------------------------------------------------------------------
 * Author:  Shane Saunders
 */

/* --- Description ---
 * A directed graph provider class is used to generate a random graphs of a
 * specific type over a varying range of parameters which can be specified
 * by the user.
 */
 
/*--- Graph Provider Classes (for experiments) ------------------------------*/

/*--- Sparse Graphs --- */
class SparseGraphSizesP: public DGraphProvider {
  public:
    char *description() { return "sparse graphs of varying size"; }
    char *varLabel() { return "n"; }
    void inputParameters() {
        cout << " - vertices (min): ";
        cin >> minVertices;

        cout << " - vertices (max): ";
        cin >> maxVertices;
        
        cout << " - edge factor: ";
        cin >> edgeFactor;
    }    
    DGraph *generateGraph() {
        DGraphFactory *f = DGraphFactory::instancePtr();
        return f->newRandomSparse(nVertices, edgeFactor);
    }
    int currentGraphSize() { return nVertices; }
    
    double varValue() { return nVertices; }        
    void initVar() { nVertices = minVertices; }
    void updateVar() { nVertices += minVertices; }
    bool varLimitReached() { return (nVertices > maxVertices); }
  private:
    int minVertices, maxVertices, nVertices;
    double edgeFactor;
};

/*--- Sparse Graphs --- */
class SparseGraphEdgesP: public DGraphProvider {
  public:
    char *description() { return "sparse graphs of varying number of edges"; }
    char *varLabel() { return "x"; }    
    void inputParameters() {
        cout << " - vertices: ";
        cin >> nVertices;
        
        cout << " - edge addition factor (initial): ";
        cin >> minEdgeAdd;
        
        cout << " - edge addition factor (limit): ";
        cin >> maxEdgeAdd;      
    }
    DGraph *generateGraph() {
        DGraphFactory *f = DGraphFactory::instancePtr();
        return f->newRandomSparse(nVertices, 1.0 + edgeAdd);
    }
    int currentGraphSize() { return nVertices; }
    double varValue() { return edgeAdd; }        
    void initVar() { edgeAdd = minEdgeAdd; }
    void updateVar() { edgeAdd *= 2; }
    bool varLimitReached() { return (edgeAdd > maxEdgeAdd); }
  private:
    int nVertices;
    double edgeAdd, minEdgeAdd, maxEdgeAdd;
};
#endif
