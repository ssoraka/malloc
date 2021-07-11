#!/bin/sh
export MALLOC_STEPS_DEBUG=1
export MALLOC_MEMORY_DUMP=1
export MALLOC_TEST=1
export MALLOC_MARK_MEMORY=1
export MALLOC_COLORS=1
export DYLD_LIBRARY_PATH=.
export DYLD_INSERT_LIBRARIES=libft_malloc.so
export DYLD_FORCE_FLAT_NAMESPACE=1 
$@
