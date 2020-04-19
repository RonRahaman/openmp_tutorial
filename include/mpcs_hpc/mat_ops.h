#ifndef MPCS_HPC_SRC_MPCS_HPC_MAT_OPS_H
#define MPCS_HPC_SRC_MPCS_HPC_MAT_OPS_H

#include "mpcs_hpc/mat_types.h"

void mat_mul_int(MatInt *A, MatInt *B, MatInt *C);

void mat_mul_float(MatFloat *A, MatFloat *B, MatFloat *C);

void mat_mul_double(MatDouble *A, MatDouble *B, MatDouble *C);

#endif // MPCS_HPC_SRC_MPCS_HPC_MAT_OPS_H
