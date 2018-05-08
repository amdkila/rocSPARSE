/* ************************************************************************
 * Copyright 2018 Advanced Micro Devices, Inc.
 *
 * ************************************************************************ */

/*!\file
 * \brief rocsparse-functions.h provides Sparse Linear Algebra Subprograms
 *  of Level 1, 2 and 3, using HIP optimized for AMD HCC-based GPU hardware.
 *  This library can also run on CUDA-based NVIDIA GPUs.
*/

#pragma once
#ifndef _ROCSPARSE_FUNCTIONS_H_
#define _ROCSPARSE_FUNCTIONS_H_

#include "rocsparse-types.h"
#include "rocsparse-export.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ===========================================================================
 *    level 1 SPARSE
 * ===========================================================================
 */

 /*! \brief SPARSE Level 1 API

     \details

     @param[in]


    ********************************************************************/
ROCSPARSE_EXPORT
rocsparse_status rocsparse_saxpyi(rocsparse_handle handle,
                                  rocsparse_int nnz,
                                  const float *alpha,
                                  const float *x_val,
                                  const rocsparse_int *x_ind,
                                  float *y,
                                  rocsparse_index_base idx_base);

ROCSPARSE_EXPORT
rocsparse_status rocsparse_daxpyi(rocsparse_handle handle,
                                  rocsparse_int nnz,
                                  const double *alpha,
                                  const double *x_val,
                                  const rocsparse_int *x_ind,
                                  double *y,
                                  rocsparse_index_base idx_base);
/*
ROCSPARSE_EXPORT
rocsparse_status rocsparse_caxpyi(rocsparse_handle handle,
                                  rocsparse_int nnz,
                                  const rocsparse_float_complex *alpha,
                                  const rocsparse_float_complex *x_val,
                                  const rocsparse_int *x_ind,
                                  rocsparse_float_complex *y,
                                  rocsparse_index_base idx_base);

ROCSPARSE_EXPORT
rocsparse_status rocsparse_zaxpyi(rocsparse_handle handle,
                                  rocsparse_int nnz,
                                  const rocsparse_double_complex *alpha,
                                  const rocsparse_double_complex *x_val,
                                  const rocsparse_int *x_ind,
                                  rocsparse_double_complex *y,
                                  rocsparse_index_base idx_base);
*/

/*
 * ===========================================================================
 *    level 2 SPARSE
 * ===========================================================================
 */

/*! \brief SPARSE Level 2 API

    \details
    csrmv  multiplies the dense vector x[i] with scalar alpha and sparse m x n
    matrix A that is defined in CSR storage format and add the result to y[i]
    that is multiplied by beta, for  i = 1 , … , n

        y := alpha * op(A) * x + beta * y,

    @param[in]
    handle      rocsparse_handle.
                handle to the rocsparse library context queue.
    @param[in]
    trans       operation type of A.
    @param[in]
    m           number of rows of A.
    @param[in]
    n           number of columns of A.
    @param[in]
    nnz         number of non-zero entries of A.
    @param[in]
    alpha       scalar alpha.
    @param[in]
    descr       descriptor of A.
    @param[in]
    csr_val     array of nnz elements of A.
    @param[in]
    csr_row_ptr array of m+1 elements that point to the start
                of every row of A.
    @param[in]
    csr_col_ind array of nnz elements containing the column indices of A.
    @param[in]
    x           array of n elements (op(A) = A) or m elements (op(A) = A^T or
                op(A) = A^H).
    @param[in]
    beta        scalar beta.
    @param[inout]
    y           array of m elements (op(A) = A) or n elements (op(A) = A^T or
                op(A) = A^H).

    ********************************************************************/
ROCSPARSE_EXPORT
rocsparse_status rocsparse_scsrmv(rocsparse_handle handle,
                                  rocsparse_operation trans, 
                                  rocsparse_int m,
                                  rocsparse_int n,
                                  rocsparse_int nnz,
                                  const float *alpha,
                                  const rocsparse_mat_descr descr,
                                  const float *csr_val,
                                  const rocsparse_int *csr_row_ptr,
                                  const rocsparse_int *csr_col_ind,
                                  const float *x,
                                  const float *beta,
                                  float *y);

ROCSPARSE_EXPORT
rocsparse_status rocsparse_dcsrmv(rocsparse_handle handle,
                                  rocsparse_operation trans, 
                                  rocsparse_int m,
                                  rocsparse_int n,
                                  rocsparse_int nnz,
                                  const double *alpha,
                                  const rocsparse_mat_descr descr,
                                  const double *csr_val,
                                  const rocsparse_int *csr_row_ptr,
                                  const rocsparse_int *csr_col_ind,
                                  const double *x,
                                  const double *beta,
                                  double *y);
/*
ROCSPARSE_EXPORT
rocsparse_status rocsparse_ccsrmv(rocsparse_handle handle,
                                  rocsparse_operation trans, 
                                  rocsparse_int m,
                                  rocsparse_int n,
                                  rocsparse_int nnz,
                                  const rocsparse_float_complex *alpha,
                                  const rocsparse_mat_descr descr,
                                  const rocsparse_float_complex *csr_val,
                                  const rocsparse_int *csr_row_ptr,
                                  const rocsparse_int *csr_col_ind,
                                  const rocsparse_float_complex *x,
                                  const rocsparse_float_complex *beta,
                                  rocsparse_float_complex *y);

ROCSPARSE_EXPORT
rocsparse_status rocsparse_zcsrmv(rocsparse_handle handle,
                                  rocsparse_operation trans, 
                                  rocsparse_int m,
                                  rocsparse_int n,
                                  rocsparse_int nnz,
                                  const rocsparse_double_complex *alpha,
                                  const rocsparse_mat_descr descr,
                                  const rocsparse_double_complex *csr_val,
                                  const rocsparse_int *csr_row_ptr,
                                  const rocsparse_int *csr_col_ind,
                                  const rocsparse_double_complex *x,
                                  const rocsparse_double_complex *beta,
                                  rocsparse_double_complex *y);
*/

// TODO
ROCSPARSE_EXPORT
rocsparse_status rocsparse_shybmv(rocsparse_handle handle,
                                  rocsparse_operation trans,
                                  const float *alpha,
                                  const rocsparse_mat_descr descr,
                                  const rocsparse_hyb_mat hyb,
                                  const float *x,
                                  const float *beta,
                                  float *y);

// TODO
ROCSPARSE_EXPORT
rocsparse_status rocsparse_dhybmv(rocsparse_handle handle,
                                  rocsparse_operation trans,
                                  const double *alpha,
                                  const rocsparse_mat_descr descr,
                                  const rocsparse_hyb_mat hyb,
                                  const double *x,
                                  const double *beta,
                                  double *y);

/*
 * ===========================================================================
 *    level 3 SPARSE
 * ===========================================================================
 */







/*
 * ===========================================================================
 *    Sparse format conversions
 * ===========================================================================
 */

// TODO
ROCSPARSE_EXPORT
rocsparse_status rocsparse_csr2coo(rocsparse_handle handle,
                                   const rocsparse_int *csr_row_ptr,
                                   rocsparse_int nnz,
                                   rocsparse_int m,
                                   rocsparse_int *coo_row_ind,
                                   rocsparse_index_base idx_base);

// TODO
ROCSPARSE_EXPORT
rocsparse_status rocsparse_coo2csr(rocsparse_handle handle,
                                   const rocsparse_int *coo_row_ind,
                                   rocsparse_int nnz,
                                   rocsparse_int m,
                                   rocsparse_int *csr_row_ptr,
                                   rocsparse_index_base idx_base);

// TODO
ROCSPARSE_EXPORT
rocsparse_status rocsparse_scsr2hyb(rocsparse_handle handle,
                                    rocsparse_int m,
                                    rocsparse_int n,
                                    const rocsparse_mat_descr descr,
                                    const float *csr_val,
                                    const rocsparse_int *csr_row_ptr,
                                    const rocsparse_int *csr_col_ind,
                                    rocsparse_hyb_mat hyb,
                                    rocsparse_int user_ell_width,
                                    rocsparse_hyb_partition partition_type);

// TODO
ROCSPARSE_EXPORT
rocsparse_status rocsparse_dcsr2hyb(rocsparse_handle handle,
                                    rocsparse_int m,
                                    rocsparse_int n,
                                    const rocsparse_mat_descr descr,
                                    const double *csr_val,
                                    const rocsparse_int *csr_row_ptr,
                                    const rocsparse_int *csr_col_ind,
                                    rocsparse_hyb_mat hyb,
                                    rocsparse_int user_ell_width,
                                    rocsparse_hyb_partition partition_type);


#ifdef __cplusplus
}
#endif

#endif // _ROCSPARSE_FUNCTIONS_H_
