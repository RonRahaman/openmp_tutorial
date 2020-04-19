#include "mpcs_hpc/mat_ops.h"
#include <assert.h>

void mat_mul_int(MatInt *A, MatInt *B, MatInt *C) {
  assert(A->m == C->m);
  assert(A->n == B->m);
  assert(B->n == C->n);

  for (size_t i = 0; i < C->m * C->n; ++i) {
    C->data[i] = 0;
  }

  for (size_t k = 0; k < A->n; ++k) {
    for (size_t i = 0; i < A->m; ++i) {
      for (size_t j = 0; j < B->n; ++j) {
        C->at[i][j] += A->at[i][k] * B->at[k][j];
      }
    }
  }
}

void mat_mul_float(MatFloat *A, MatFloat *B, MatFloat *C) {
  assert(A->m == C->m);
  assert(A->n == B->m);
  assert(B->n == C->n);

  for (size_t i = 0; i < C->m * C->n; ++i) {
    C->data[i] = 0;
  }

  for (size_t k = 0; k < A->n; ++k) {
    for (size_t i = 0; i < A->m; ++i) {
      for (size_t j = 0; j < B->n; ++j) {
        C->at[i][j] += A->at[i][k] * B->at[k][j];
      }
    }
  }
}

void mat_mul_double(MatDouble *A, MatDouble *B, MatDouble *C) {
  assert(A->m == C->m);
  assert(A->n == B->m);
  assert(B->n == C->n);

  for (size_t i = 0; i < C->m * C->n; ++i) {
    C->data[i] = 0;
  }

  for (size_t k = 0; k < A->n; ++k) {
    for (size_t i = 0; i < A->m; ++i) {
      for (size_t j = 0; j < B->n; ++j) {
        C->at[i][j] += A->at[i][k] * B->at[k][j];
      }
    }
  }
}
