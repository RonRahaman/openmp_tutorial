#include "mpcs_hpc/rand.h"

double lcg_rand_double(uint64_t *seed) {
  const uint64_t m = 9223372036854775808ULL; // 2ˆ63
  const uint64_t a = 2806196910506780709ULL;
  const uint64_t c = 1ULL;

  *seed = (a * (*seed) + c) %m;
  return (double) (*seed) / (double) m;
}
