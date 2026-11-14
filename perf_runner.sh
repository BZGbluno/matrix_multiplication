#!/bin/bash

# perf stat -r 10 -e cycles,instructions,cache-misses,cache-references ./build-O0/cool 



perf stat -r 10 -e \
cycles,instructions,\
L1-dcache-loads,L1-dcache-load-misses,\
l2_cache_accesses_from_dc_misses,\
l2_cache_hits_from_dc_misses,\
l2_cache_misses_from_dc_misses,\
dTLB-loads,dTLB-load-misses,\
cache-misses,cache-references \
./build-O0/cool