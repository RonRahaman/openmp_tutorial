CC ?= gcc
CFLAGS ?= -O3 -Iinclude

all: dgemm_serial dgemm_omp

dgemm_serial: src/dgemm.c src/mpcs_hpc/tick.c src/mpcs_hpc/mat_types.c
	$(CC) $(CFLAGS) $^ -o $@

dgemm_omp: src/dgemm.c src/mpcs_hpc/tick.c src/mpcs_hpc/mat_types.c
	$(CC) $(CFLAGS) -fopenmp $^ -o $@
