//#define IHEAP_DEBUG

class MFHeap;  // for upper heap

class IHeapNode {
  public:    
    int item;
    int hkey;
    int bucket;
    IHeapNode *prev, *next;
};

class IHeap {
  public:
    IHeap(int n);
    ~IHeap();
    
    int deleteMin();
    void insert(int item, long hkey, long lkey);
    void decreaseKey(int item, long hkey, long lkey);
    int nItems() const { return itemCount; }

    long nComps() const { return compCount; }
    void dump() const;

  private:
    void insertNode(IHeapNode *node, int i);
    void removeNode(IHeapNode *node);
    static const int MaxKey = 500000;

    IHeapNode *bucketHeaders;  // array of bucket header nodes
    IHeapNode **nodes;  // array of pointers to nodes (indexed by item no)
    MFHeap *upperHeap;
    
    int maxNodes, maxTrees, itemCount, treeSum;
    long compCount;
};
