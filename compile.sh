#!/bin/bash

# No optimization
# cmake -S . -B build-O0 -DCMAKE_BUILD_TYPE=Debug \
#   -DCMAKE_CXX_FLAGS_DEBUG="-O0 -g"

# # O2 optimization
# cmake -S . -B build-O2 -DCMAKE_BUILD_TYPE=Release \
#   -DCMAKE_CXX_FLAGS_RELEASE="-O2 -DNDEBUG"

# O3 optimization
cmake -S . -B build-O0 -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_CXX_FLAGS_RELEASE="-O3 -DNDEBUG"
cmake -S . -B build-no-O0 \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_CXX_FLAGS_RELEASE="-O3 -DNDEBUG -march=native -fno-tree-vectorize --verbose"

cmake --build build-O0