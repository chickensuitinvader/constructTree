#ifndef IDIJKSTRA_H
#define IDIJKSTRA_H
/* Dijkstra's Algorithm (for itemized edge costs)
 * ----------------------------------------------------------------------------
 * Author:  Shane Saunders
 */

class IHeap;     // Heap
class DGraph;    // Graph

/* --- IDijkstra ---
 * IDijkstra's single-source algorithm.
 */
class IDijkstra {
  public:
    IDijkstra(int n);
    ~IDijkstra();

    void init(const DGraph *g);
    void run(long *d, int s = 0);

  private:
    IHeap *heap;       // pointer: heap
    bool *s;           // array: solution set state of vertices
    bool *f;           // array: frontier set state of vertices

    const DGraph *graph;    // pointer: directed graph    
};

#endif
