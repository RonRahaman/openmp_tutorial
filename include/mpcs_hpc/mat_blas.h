#ifndef MPCS_HPC_SRC_MPCS_HPC_MAT_BLAS_H
#define MPCS_HPC_SRC_MPCS_HPC_MAT_BLAS_H

#include "mpcs_hpc/mat_types.h"

void mat_blas_sgemm(MatFloat *A, MatFloat *B, MatFloat *C);

void mat_blas_dgemm(MatDouble *A, MatDouble *B, MatDouble *C);

#endif // MPCS_HPC_SRC_MPCS_HPC_MAT_BLAS_H
