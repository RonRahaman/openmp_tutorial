#include "mpcs_hpc/mat_types.h"
#include "mpcs_hpc/tick.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  size_t n = 1024;

  MatFloat A = mat_malloc_float(n, n);
  MatFloat B = mat_malloc_float(n, n);
  MatFloat C = mat_malloc_float(n, n);

  timespec_t start = tick();
#pragma omp parallel for collapse(2)
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        C.at[i][j] += A.at[i][k] * B.at[k][j];
      }
    }
  }
  timespec_t end = tick();

  printf("Time: %g s\n", tick_diff(start, end) / 1e9);
}
