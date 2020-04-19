#include "mpcs_hpc/mat_blas.h"
#include "cblas_openblas.h"

void mat_blas_sgemm(MatFloat *A, MatFloat *B, MatFloat *C) {

#if defined(__INTEL_COMPILER)
  float *A_dat = A->data;
  float *B_dat = C->data;
  float *C_dat = C->data;
  __assume_aligned(A_dat, 64);
  __assume_aligned(B_dat, 64);
  __assume_aligned(C_dat, 64);
#elif defined(__GNUC__) || defined(__clang__)
  float *A_dat, *B_dat, *C_dat;
  A_dat = (float *)__builtin_assume_aligned((void *)A->data, 64);
  B_dat = (float *)__builtin_assume_aligned((void *)B->data, 64);
  C_dat = (float *)__builtin_assume_aligned((void *)C->data, 64);
#endif

  cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, A->m, B->n, A->n, 1.0,
              A_dat, A->n, B_dat, B->n, 0.0, C_dat, C->n);
}

void mat_blas_dgemm(MatDouble *A, MatDouble *B, MatDouble *C) {

#if defined(__INTEL_COMPILER)
  double *A_dat = A->data;
  double *B_dat = C->data;
  double *C_dat = C->data;
  __assume_aligned(A_dat, 64);
  __assume_aligned(B_dat, 64);
  __assume_aligned(C_dat, 64);
#elif defined(__GNUC__) || defined(__clang__)
  double *A_dat, *B_dat, *C_dat;
  A_dat = (double *)__builtin_assume_aligned((void *)A->data, 64);
  B_dat = (double *)__builtin_assume_aligned((void *)B->data, 64);
  C_dat = (double *)__builtin_assume_aligned((void *)C->data, 64);
#endif

  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, A->m, B->n, A->n, 1.0,
              A_dat, A->n, B_dat, B->n, 0.0, C_dat, C->n);
}
