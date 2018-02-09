#ifndef SP_EXP_H
#define SP_EXP_H
/* Experiment Class for Measuring the Performance of Different Dijkstra's
 * Algorithm Implementations
 * ----------------------------------------------------------------------------
 * Author:  Shane Saunders
 */
 
/* default number of run samples */
const int RUN_SAMPLES = 5;

class DijkstraDesc;  // Dijkstra's algorithm descriptor class
class DGraphProvider;  // directed graph provider class

/* --- SSAlgSpec ---
 * Class for specifying Dijkstra's algorithm variants in an experiment.  The
 * 'name' field is used for specifying a name associated with the algorithm
 * referred to by the descriptor 'algDesc'.
 */
class SpAlgSpec {
  public:
    char *name;
    DijkstraDesc *algDesc;
};

/* --- Experiment ---
 * This experiment class allows the performance of different Dijkstra's
 * algorithm implementations to be compared under specific graph types and
 * parameters.
 */
class SpExperiment {
  public:
    SpExperiment(): runSamples(RUN_SAMPLES) { }
    void setRunSamples(int n) { runSamples = n; }
    void run(
      DGraphProvider *graphP, SpAlgSpec *algSpecs, int nAlgs);
  
  private:
    int runSamples;    
    
    void printDistances(long *d, int n);
    void copyDistances(long *dest, long *src, int n);
    void initSingleSourceDistances(long *d, int n);
    void verifyDistances(long *distArrays[], int nArrays, int n);
};

#endif
