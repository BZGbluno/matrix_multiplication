#!/bin/bash

perf stat -r 10 -e cycles,instructions,cache-misses,cache-references ./build-O0/cool 