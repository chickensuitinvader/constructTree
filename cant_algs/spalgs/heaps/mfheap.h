#ifndef MFHEAP_H
#define FHEAP_H
/* File mfheap.h - Modified Fibonacci Heap
 * ----------------------------------------------------------------------------
 *  Shane Saunders
 */
#include "heap.h"  /* Defines the base class for heaps. */

/* This provides Abuaiadh and Kington's variant of the Fibonacci heap, which
 * suports O(1) delete at the exxpense of O(log n) amortised time
 * for find-min.
 */


/* Option to allow printing of debugging information.  Use 1 for yes, or 0 for
 * no.
 */
#define MFHEAP_DUMP 0


/* --- MFHeapNode ---
 * Fibonacci heap node class.
 *
 * A nodes has the following pointers:
 * parent      - a pointer to the nodes parent node (if any).
 * child       - a pointer to a child node (typically the highest rank child).
 * left, right - sibling pointers which provide a circular doubly linked list
 *               containing all the parents nodes children.
 *
 * The remaining fields are:
 * rank        - the nodes rank, that is, the number of children it has.
 * key         - the nodes key.
 * item        - the number of the item that the node is associated with.
 */
class MFHeapNode {
  public:
    MFHeapNode *parent;
    MFHeapNode *left, *right;
    MFHeapNode *child;
    int rank;
    int marked;
    long key;
    int item;
};

/* --- MFHeap ---
 * Fibonacci heap class.
 *
 * trees - An array of pointers to trees at root level in the heap.  Entry i
 *         in the array points to the root node of a tree that has nodes of
 *         dimension i on the main trunk.
 * nodes - An array of pointers to nodes in the heap.  Nodes are indexed
 *         according to their vertex number.  This array can then be used to
 *         look up the node for corresponding to a vertex number, and is
 *         useful when freeing space taken up by the heap.
 * maxNodes - The maximum number of nodes allowed in the heap.
 * maxTrees - The maximum number of trees allowed in the heap (calculated from
 *             maxNodes).
 * itemCount - The current number of nodes in the heap.
 * treeSum - The binary value represented by trees in the heap.
 *           By maintaining this it is easy to keep track of the maximum rank
 *           tree in the heap.
 * compCount - can be used for experimental purposes when counting the number
 *             of key comparisons.
 */
class MFHeap: public Heap {
  public:
    MFHeap(int n);
    ~MFHeap();
    
    int deleteMin();
    void insert(int item, long k);
    void delete1(int item);
    void decreaseKey(int item, long newValue);
    int nItems() const { return itemCount; }

    long nComps() const { return compCount; }
    void dump() const;

  private:
    MFHeapNode **trees;  // array of pointers to root nodes (indexed by rank)
    MFHeapNode **nodes;  // array of pointers to nodes (indexed by item no)
    MFHeapNode meldListHeader;  // header node for a linked-list of root nodes
                                // of trees to be melded into the heap    
    int maxNodes, maxTrees, itemCount, treeSum;
    long compCount;

    void meld();
    void append(MFHeapNode *treeListHead);
    static void dumpNodes(MFHeapNode *node, int level);
};

/*---------------------------------------------------------------------------*/
#endif
