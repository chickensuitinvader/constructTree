#ifndef MDIJKSTRA_H
#define MDIJKSTRA_H
/* Modified Dijkstra's Algorithm for Nearly Acyclic Graphs
 * ----------------------------------------------------------------------------
 * Author:  Shane Saunders
 */

/* This is an implementation of Abuaiadh and Kingston's modified version of
 * Dijkstra's algorithm, which gives improved performance on nearly acyclic
 * graphs.
 */

class MFHeap;    // Heap
class DGraph;    // Graph

/* --- Dijkstra ---
 * Dijkstra's single-source algorithm.
 */
class MDijkstra {
  public:
    MDijkstra(int n);
    ~MDijkstra();

    void init(const DGraph *g);
    void run(long *d, int s = 0);

  private:
    MFHeap *heap;      // pointer: heap
    bool *s;           // array: solution set state of vertices
    bool *f;           // array: frontier set state of vertices
    int *inCount;      // array: count of number of untraversed incomming edges
    int *queue;        // array: queue for 'unlocked' vertices
    
    const DGraph *graph;    // pointer: directed graph    
};

#endif
