# Makefile for Algorithms
# -----------------------------------------------------------------------------
# Author:  Shane Saunders
#
CXXFLAGS = -Wall -O
export CXXFLAGS

#--- target programs ---------------------------------------------------------#

TARGETS = run_exp run_dijkstra run_mdijkstra run_idijkstra

#--- object file groups ------------------------------------------------------#

exp_sp_OBJ    = exp_sp.o dgraph.o dgraph_factory.o timing.o

heap_OBJ      = heaps/bheap.o heaps/fheap.o heaps/mfheap.o heaps/heap23.o heaps/triheap.o \
                heaps/triheap_ext.o heaps/radixheap.o

run_exp_OBJ        = run_exp.o dijkstra.o $(exp_sp_OBJ) $(heap_OBJ)
run_dijkstra_OBJ  = run_dijkstra.o dijkstra.o dgraph.o dgraph_factory.o timing.o $(heap_OBJ) 

run_mdijkstra_OBJ  = run_mdijkstra.o mdijkstra.o dgraph.o dgraph_factory.o timing.o heaps/mfheap.o

run_idijkstra_OBJ  = run_idijkstra.o idijkstra.o dgraph.o dgraph_factory.o timing.o heaps/iheap.o heaps/mfheap.o

#--- overall compilations ----------------------------------------------------#

# list of all compilations performed by this makefile
all: heaplib $(TARGETS)

# separate compilation of heap library
heaplib:
	cd heaps && $(MAKE) -e

run_exp: $(run_exp_OBJ)
	$(LINK.cc)  -o run_exp $(run_exp_OBJ) -lm

run_dijkstra: $(run_dijkstra_OBJ)
	$(LINK.cc) -o run_dijkstra $(run_dijkstra_OBJ) -lm

run_mdijkstra: $(run_mdijkstra_OBJ)
	$(LINK.cc) -o run_mdijkstra $(run_mdijkstra_OBJ) -lm

run_idijkstra: $(run_idijkstra_OBJ)
	$(LINK.cc) -o run_idijkstra $(run_idijkstra_OBJ) -lm

include Makefile.d


depend:
	$(CC) -MM *.cpp > Makefile.d


#--- cleaning ----------------------------------------------------------------#

clean:
	cd heaps && rm -f *.o
	rm -f *.o

cleanbin:
	rm -f $(TARGETS)

#-----------------------------------------------------------------------------#
# DO NOT DELETE
