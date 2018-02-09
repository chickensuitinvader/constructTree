#
# Makefile for Heaps
#
CXXFLAGS = -Wall -O

#--- Overall Compilations ---#

# All compilations done by this makefile.
all: bheap.o fheap.o mfheap.o heap23.o triheap.o triheap_ext.o heap23_2.o radixheap.o iheap.o

#--- Individual Heaps ---#

# Compile
bheap.o: bheap.cpp bheap.h heap.h
fheap.o: fheap.cpp fheap.h heap.h
mfheap.o: mfheap.cpp mfheap.h heap.h
heap23.o: heap23.cpp heap23.h heap.h
triheap.o: triheap.cpp triheap.h heap.h
triheap_ext.o: triheap_ext.cpp triheap_ext.h heap.h
heap23_2.o: heap23_2.cpp heap23_2.h heap.h
radixheap.o: radixheap.cpp radixheap.h heap.h
iheap.o: iheap.cpp iheap.h mfheap.h

#--- Cleaning ---#

clean:
	rm -f *.o
