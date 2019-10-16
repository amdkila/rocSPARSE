/* ************************************************************************
 * Copyright (c) 2019 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * ************************************************************************ */

#include "rocsparse.hpp"

#include <complex>
#include <rocsparse.h>

/*
 * ===========================================================================
 *    level 1 SPARSE
 * ===========================================================================
 */
// axpyi
template <>
rocsparse_status rocsparse_axpyi(rocsparse_handle     handle,
                                 rocsparse_int        nnz,
                                 const float*         alpha,
                                 const float*         x_val,
                                 const rocsparse_int* x_ind,
                                 float*               y,
                                 rocsparse_index_base idx_base)
{
    return rocsparse_saxpyi(handle, nnz, alpha, x_val, x_ind, y, idx_base);
}

template <>
rocsparse_status rocsparse_axpyi(rocsparse_handle     handle,
                                 rocsparse_int        nnz,
                                 const double*        alpha,
                                 const double*        x_val,
                                 const rocsparse_int* x_ind,
                                 double*              y,
                                 rocsparse_index_base idx_base)
{
    return rocsparse_daxpyi(handle, nnz, alpha, x_val, x_ind, y, idx_base);
}

template <>
rocsparse_status rocsparse_axpyi(rocsparse_handle           handle,
                                 rocsparse_int              nnz,
                                 const std::complex<float>* alpha,
                                 const std::complex<float>* x_val,
                                 const rocsparse_int*       x_ind,
                                 std::complex<float>*       y,
                                 rocsparse_index_base       idx_base)
{
    return rocsparse_caxpyi(handle,
                            nnz,
                            (const rocsparse_float_complex*)alpha,
                            (const rocsparse_float_complex*)x_val,
                            x_ind,
                            (rocsparse_float_complex*)y,
                            idx_base);
}

template <>
rocsparse_status rocsparse_axpyi(rocsparse_handle            handle,
                                 rocsparse_int               nnz,
                                 const std::complex<double>* alpha,
                                 const std::complex<double>* x_val,
                                 const rocsparse_int*        x_ind,
                                 std::complex<double>*       y,
                                 rocsparse_index_base        idx_base)
{
    return rocsparse_zaxpyi(handle,
                            nnz,
                            (const rocsparse_double_complex*)alpha,
                            (const rocsparse_double_complex*)x_val,
                            x_ind,
                            (rocsparse_double_complex*)y,
                            idx_base);
}

// doti
template <>
rocsparse_status rocsparse_doti(rocsparse_handle     handle,
                                rocsparse_int        nnz,
                                const float*         x_val,
                                const rocsparse_int* x_ind,
                                const float*         y,
                                float*               result,
                                rocsparse_index_base idx_base)
{
    return rocsparse_sdoti(handle, nnz, x_val, x_ind, y, result, idx_base);
}

template <>
rocsparse_status rocsparse_doti(rocsparse_handle     handle,
                                rocsparse_int        nnz,
                                const double*        x_val,
                                const rocsparse_int* x_ind,
                                const double*        y,
                                double*              result,
                                rocsparse_index_base idx_base)
{
    return rocsparse_ddoti(handle, nnz, x_val, x_ind, y, result, idx_base);
}

template <>
rocsparse_status rocsparse_doti(rocsparse_handle           handle,
                                rocsparse_int              nnz,
                                const std::complex<float>* x_val,
                                const rocsparse_int*       x_ind,
                                const std::complex<float>* y,
                                std::complex<float>*       result,
                                rocsparse_index_base       idx_base)
{
    return rocsparse_cdoti(handle,
                           nnz,
                           (const rocsparse_float_complex*)x_val,
                           x_ind,
                           (const rocsparse_float_complex*)y,
                           (rocsparse_float_complex*)result,
                           idx_base);
}

template <>
rocsparse_status rocsparse_doti(rocsparse_handle            handle,
                                rocsparse_int               nnz,
                                const std::complex<double>* x_val,
                                const rocsparse_int*        x_ind,
                                const std::complex<double>* y,
                                std::complex<double>*       result,
                                rocsparse_index_base        idx_base)
{
    return rocsparse_zdoti(handle,
                           nnz,
                           (const rocsparse_double_complex*)x_val,
                           x_ind,
                           (const rocsparse_double_complex*)y,
                           (rocsparse_double_complex*)result,
                           idx_base);
}

// dotci
template <>
rocsparse_status rocsparse_dotci(rocsparse_handle           handle,
                                 rocsparse_int              nnz,
                                 const std::complex<float>* x_val,
                                 const rocsparse_int*       x_ind,
                                 const std::complex<float>* y,
                                 std::complex<float>*       result,
                                 rocsparse_index_base       idx_base)
{
    return rocsparse_cdotci(handle,
                            nnz,
                            (const rocsparse_float_complex*)x_val,
                            x_ind,
                            (const rocsparse_float_complex*)y,
                            (rocsparse_float_complex*)result,
                            idx_base);
}

template <>
rocsparse_status rocsparse_dotci(rocsparse_handle            handle,
                                 rocsparse_int               nnz,
                                 const std::complex<double>* x_val,
                                 const rocsparse_int*        x_ind,
                                 const std::complex<double>* y,
                                 std::complex<double>*       result,
                                 rocsparse_index_base        idx_base)
{
    return rocsparse_zdotci(handle,
                            nnz,
                            (const rocsparse_double_complex*)x_val,
                            x_ind,
                            (const rocsparse_double_complex*)y,
                            (rocsparse_double_complex*)result,
                            idx_base);
}

// gthr
template <>
rocsparse_status rocsparse_gthr(rocsparse_handle     handle,
                                rocsparse_int        nnz,
                                const float*         y,
                                float*               x_val,
                                const rocsparse_int* x_ind,
                                rocsparse_index_base idx_base)
{
    return rocsparse_sgthr(handle, nnz, y, x_val, x_ind, idx_base);
}

template <>
rocsparse_status rocsparse_gthr(rocsparse_handle     handle,
                                rocsparse_int        nnz,
                                const double*        y,
                                double*              x_val,
                                const rocsparse_int* x_ind,
                                rocsparse_index_base idx_base)
{
    return rocsparse_dgthr(handle, nnz, y, x_val, x_ind, idx_base);
}

template <>
rocsparse_status rocsparse_gthr(rocsparse_handle           handle,
                                rocsparse_int              nnz,
                                const std::complex<float>* y,
                                std::complex<float>*       x_val,
                                const rocsparse_int*       x_ind,
                                rocsparse_index_base       idx_base)
{
    return rocsparse_cgthr(handle,
                           nnz,
                           (const rocsparse_float_complex*)y,
                           (rocsparse_float_complex*)x_val,
                           x_ind,
                           idx_base);
}

template <>
rocsparse_status rocsparse_gthr(rocsparse_handle            handle,
                                rocsparse_int               nnz,
                                const std::complex<double>* y,
                                std::complex<double>*       x_val,
                                const rocsparse_int*        x_ind,
                                rocsparse_index_base        idx_base)
{
    return rocsparse_zgthr(handle,
                           nnz,
                           (const rocsparse_double_complex*)y,
                           (rocsparse_double_complex*)x_val,
                           x_ind,
                           idx_base);
}

// gthrz
template <>
rocsparse_status rocsparse_gthrz(rocsparse_handle     handle,
                                 rocsparse_int        nnz,
                                 float*               y,
                                 float*               x_val,
                                 const rocsparse_int* x_ind,
                                 rocsparse_index_base idx_base)
{
    return rocsparse_sgthrz(handle, nnz, y, x_val, x_ind, idx_base);
}

template <>
rocsparse_status rocsparse_gthrz(rocsparse_handle     handle,
                                 rocsparse_int        nnz,
                                 double*              y,
                                 double*              x_val,
                                 const rocsparse_int* x_ind,
                                 rocsparse_index_base idx_base)
{
    return rocsparse_dgthrz(handle, nnz, y, x_val, x_ind, idx_base);
}

template <>
rocsparse_status rocsparse_gthrz(rocsparse_handle     handle,
                                 rocsparse_int        nnz,
                                 std::complex<float>* y,
                                 std::complex<float>* x_val,
                                 const rocsparse_int* x_ind,
                                 rocsparse_index_base idx_base)
{
    return rocsparse_cgthrz(
        handle, nnz, (rocsparse_float_complex*)y, (rocsparse_float_complex*)x_val, x_ind, idx_base);
}

template <>
rocsparse_status rocsparse_gthrz(rocsparse_handle      handle,
                                 rocsparse_int         nnz,
                                 std::complex<double>* y,
                                 std::complex<double>* x_val,
                                 const rocsparse_int*  x_ind,
                                 rocsparse_index_base  idx_base)
{
    return rocsparse_zgthrz(handle,
                            nnz,
                            (rocsparse_double_complex*)y,
                            (rocsparse_double_complex*)x_val,
                            x_ind,
                            idx_base);
}

// sctr
template <>
rocsparse_status rocsparse_sctr(rocsparse_handle     handle,
                                rocsparse_int        nnz,
                                const float*         x_val,
                                const rocsparse_int* x_ind,
                                float*               y,
                                rocsparse_index_base idx_base)
{
    return rocsparse_ssctr(handle, nnz, x_val, x_ind, y, idx_base);
}

template <>
rocsparse_status rocsparse_sctr(rocsparse_handle     handle,
                                rocsparse_int        nnz,
                                const double*        x_val,
                                const rocsparse_int* x_ind,
                                double*              y,
                                rocsparse_index_base idx_base)
{
    return rocsparse_dsctr(handle, nnz, x_val, x_ind, y, idx_base);
}

template <>
rocsparse_status rocsparse_sctr(rocsparse_handle           handle,
                                rocsparse_int              nnz,
                                const std::complex<float>* x_val,
                                const rocsparse_int*       x_ind,
                                std::complex<float>*       y,
                                rocsparse_index_base       idx_base)
{
    return rocsparse_csctr(handle,
                           nnz,
                           (const rocsparse_float_complex*)x_val,
                           x_ind,
                           (rocsparse_float_complex*)y,
                           idx_base);
}

template <>
rocsparse_status rocsparse_sctr(rocsparse_handle            handle,
                                rocsparse_int               nnz,
                                const std::complex<double>* x_val,
                                const rocsparse_int*        x_ind,
                                std::complex<double>*       y,
                                rocsparse_index_base        idx_base)
{
    return rocsparse_zsctr(handle,
                           nnz,
                           (const rocsparse_double_complex*)x_val,
                           x_ind,
                           (rocsparse_double_complex*)y,
                           idx_base);
}

/*
 * ===========================================================================
 *    level 2 SPARSE
 * ===========================================================================
 */
// coomv
template <>
rocsparse_status rocsparse_coomv(rocsparse_handle          handle,
                                 rocsparse_operation       trans,
                                 rocsparse_int             m,
                                 rocsparse_int             n,
                                 rocsparse_int             nnz,
                                 const float*              alpha,
                                 const rocsparse_mat_descr descr,
                                 const float*              coo_val,
                                 const rocsparse_int*      coo_row_ind,
                                 const rocsparse_int*      coo_col_ind,
                                 const float*              x,
                                 const float*              beta,
                                 float*                    y)
{
    return rocsparse_scoomv(
        handle, trans, m, n, nnz, alpha, descr, coo_val, coo_row_ind, coo_col_ind, x, beta, y);
}

template <>
rocsparse_status rocsparse_coomv(rocsparse_handle          handle,
                                 rocsparse_operation       trans,
                                 rocsparse_int             m,
                                 rocsparse_int             n,
                                 rocsparse_int             nnz,
                                 const double*             alpha,
                                 const rocsparse_mat_descr descr,
                                 const double*             coo_val,
                                 const rocsparse_int*      coo_row_ind,
                                 const rocsparse_int*      coo_col_ind,
                                 const double*             x,
                                 const double*             beta,
                                 double*                   y)
{
    return rocsparse_dcoomv(
        handle, trans, m, n, nnz, alpha, descr, coo_val, coo_row_ind, coo_col_ind, x, beta, y);
}

template <>
rocsparse_status rocsparse_coomv(rocsparse_handle           handle,
                                 rocsparse_operation        trans,
                                 rocsparse_int              m,
                                 rocsparse_int              n,
                                 rocsparse_int              nnz,
                                 const std::complex<float>* alpha,
                                 const rocsparse_mat_descr  descr,
                                 const std::complex<float>* coo_val,
                                 const rocsparse_int*       coo_row_ind,
                                 const rocsparse_int*       coo_col_ind,
                                 const std::complex<float>* x,
                                 const std::complex<float>* beta,
                                 std::complex<float>*       y)
{
    return rocsparse_ccoomv(handle,
                            trans,
                            m,
                            n,
                            nnz,
                            (const rocsparse_float_complex*)alpha,
                            descr,
                            (const rocsparse_float_complex*)coo_val,
                            coo_row_ind,
                            coo_col_ind,
                            (const rocsparse_float_complex*)x,
                            (const rocsparse_float_complex*)beta,
                            (rocsparse_float_complex*)y);
}

template <>
rocsparse_status rocsparse_coomv(rocsparse_handle            handle,
                                 rocsparse_operation         trans,
                                 rocsparse_int               m,
                                 rocsparse_int               n,
                                 rocsparse_int               nnz,
                                 const std::complex<double>* alpha,
                                 const rocsparse_mat_descr   descr,
                                 const std::complex<double>* coo_val,
                                 const rocsparse_int*        coo_row_ind,
                                 const rocsparse_int*        coo_col_ind,
                                 const std::complex<double>* x,
                                 const std::complex<double>* beta,
                                 std::complex<double>*       y)
{
    return rocsparse_zcoomv(handle,
                            trans,
                            m,
                            n,
                            nnz,
                            (const rocsparse_double_complex*)alpha,
                            descr,
                            (const rocsparse_double_complex*)coo_val,
                            coo_row_ind,
                            coo_col_ind,
                            (const rocsparse_double_complex*)x,
                            (const rocsparse_double_complex*)beta,
                            (rocsparse_double_complex*)y);
}

// csrmv
template <>
rocsparse_status rocsparse_csrmv_analysis(rocsparse_handle          handle,
                                          rocsparse_operation       trans,
                                          rocsparse_int             m,
                                          rocsparse_int             n,
                                          rocsparse_int             nnz,
                                          const rocsparse_mat_descr descr,
                                          const float*              csr_val,
                                          const rocsparse_int*      csr_row_ptr,
                                          const rocsparse_int*      csr_col_ind,
                                          rocsparse_mat_info        info)
{
    return rocsparse_scsrmv_analysis(
        handle, trans, m, n, nnz, descr, csr_val, csr_row_ptr, csr_col_ind, info);
}

template <>
rocsparse_status rocsparse_csrmv_analysis(rocsparse_handle          handle,
                                          rocsparse_operation       trans,
                                          rocsparse_int             m,
                                          rocsparse_int             n,
                                          rocsparse_int             nnz,
                                          const rocsparse_mat_descr descr,
                                          const double*             csr_val,
                                          const rocsparse_int*      csr_row_ptr,
                                          const rocsparse_int*      csr_col_ind,
                                          rocsparse_mat_info        info)
{
    return rocsparse_dcsrmv_analysis(
        handle, trans, m, n, nnz, descr, csr_val, csr_row_ptr, csr_col_ind, info);
}

template <>
rocsparse_status rocsparse_csrmv_analysis(rocsparse_handle           handle,
                                          rocsparse_operation        trans,
                                          rocsparse_int              m,
                                          rocsparse_int              n,
                                          rocsparse_int              nnz,
                                          const rocsparse_mat_descr  descr,
                                          const std::complex<float>* csr_val,
                                          const rocsparse_int*       csr_row_ptr,
                                          const rocsparse_int*       csr_col_ind,
                                          rocsparse_mat_info         info)
{
    return rocsparse_ccsrmv_analysis(handle,
                                     trans,
                                     m,
                                     n,
                                     nnz,
                                     descr,
                                     (const rocsparse_float_complex*)csr_val,
                                     csr_row_ptr,
                                     csr_col_ind,
                                     info);
}

template <>
rocsparse_status rocsparse_csrmv_analysis(rocsparse_handle            handle,
                                          rocsparse_operation         trans,
                                          rocsparse_int               m,
                                          rocsparse_int               n,
                                          rocsparse_int               nnz,
                                          const rocsparse_mat_descr   descr,
                                          const std::complex<double>* csr_val,
                                          const rocsparse_int*        csr_row_ptr,
                                          const rocsparse_int*        csr_col_ind,
                                          rocsparse_mat_info          info)
{
    return rocsparse_zcsrmv_analysis(handle,
                                     trans,
                                     m,
                                     n,
                                     nnz,
                                     descr,
                                     (const rocsparse_double_complex*)csr_val,
                                     csr_row_ptr,
                                     csr_col_ind,
                                     info);
}

template <>
rocsparse_status rocsparse_csrmv(rocsparse_handle          handle,
                                 rocsparse_operation       trans,
                                 rocsparse_int             m,
                                 rocsparse_int             n,
                                 rocsparse_int             nnz,
                                 const float*              alpha,
                                 const rocsparse_mat_descr descr,
                                 const float*              csr_val,
                                 const rocsparse_int*      csr_row_ptr,
                                 const rocsparse_int*      csr_col_ind,
                                 rocsparse_mat_info        info,
                                 const float*              x,
                                 const float*              beta,
                                 float*                    y)
{
    return rocsparse_scsrmv(handle,
                            trans,
                            m,
                            n,
                            nnz,
                            alpha,
                            descr,
                            csr_val,
                            csr_row_ptr,
                            csr_col_ind,
                            info,
                            x,
                            beta,
                            y);
}

template <>
rocsparse_status rocsparse_csrmv(rocsparse_handle          handle,
                                 rocsparse_operation       trans,
                                 rocsparse_int             m,
                                 rocsparse_int             n,
                                 rocsparse_int             nnz,
                                 const double*             alpha,
                                 const rocsparse_mat_descr descr,
                                 const double*             csr_val,
                                 const rocsparse_int*      csr_row_ptr,
                                 const rocsparse_int*      csr_col_ind,
                                 rocsparse_mat_info        info,
                                 const double*             x,
                                 const double*             beta,
                                 double*                   y)
{
    return rocsparse_dcsrmv(handle,
                            trans,
                            m,
                            n,
                            nnz,
                            alpha,
                            descr,
                            csr_val,
                            csr_row_ptr,
                            csr_col_ind,
                            info,
                            x,
                            beta,
                            y);
}

template <>
rocsparse_status rocsparse_csrmv(rocsparse_handle           handle,
                                 rocsparse_operation        trans,
                                 rocsparse_int              m,
                                 rocsparse_int              n,
                                 rocsparse_int              nnz,
                                 const std::complex<float>* alpha,
                                 const rocsparse_mat_descr  descr,
                                 const std::complex<float>* csr_val,
                                 const rocsparse_int*       csr_row_ptr,
                                 const rocsparse_int*       csr_col_ind,
                                 rocsparse_mat_info         info,
                                 const std::complex<float>* x,
                                 const std::complex<float>* beta,
                                 std::complex<float>*       y)
{
    return rocsparse_ccsrmv(handle,
                            trans,
                            m,
                            n,
                            nnz,
                            (const rocsparse_float_complex*)alpha,
                            descr,
                            (const rocsparse_float_complex*)csr_val,
                            csr_row_ptr,
                            csr_col_ind,
                            info,
                            (const rocsparse_float_complex*)x,
                            (const rocsparse_float_complex*)beta,
                            (rocsparse_float_complex*)y);
}

template <>
rocsparse_status rocsparse_csrmv(rocsparse_handle            handle,
                                 rocsparse_operation         trans,
                                 rocsparse_int               m,
                                 rocsparse_int               n,
                                 rocsparse_int               nnz,
                                 const std::complex<double>* alpha,
                                 const rocsparse_mat_descr   descr,
                                 const std::complex<double>* csr_val,
                                 const rocsparse_int*        csr_row_ptr,
                                 const rocsparse_int*        csr_col_ind,
                                 rocsparse_mat_info          info,
                                 const std::complex<double>* x,
                                 const std::complex<double>* beta,
                                 std::complex<double>*       y)
{
    return rocsparse_zcsrmv(handle,
                            trans,
                            m,
                            n,
                            nnz,
                            (const rocsparse_double_complex*)alpha,
                            descr,
                            (const rocsparse_double_complex*)csr_val,
                            csr_row_ptr,
                            csr_col_ind,
                            info,
                            (const rocsparse_double_complex*)x,
                            (const rocsparse_double_complex*)beta,
                            (rocsparse_double_complex*)y);
}

// ellmv
template <>
rocsparse_status rocsparse_ellmv(rocsparse_handle          handle,
                                 rocsparse_operation       trans,
                                 rocsparse_int             m,
                                 rocsparse_int             n,
                                 const float*              alpha,
                                 const rocsparse_mat_descr descr,
                                 const float*              ell_val,
                                 const rocsparse_int*      ell_col_ind,
                                 rocsparse_int             ell_width,
                                 const float*              x,
                                 const float*              beta,
                                 float*                    y)
{
    return rocsparse_sellmv(
        handle, trans, m, n, alpha, descr, ell_val, ell_col_ind, ell_width, x, beta, y);
}

template <>
rocsparse_status rocsparse_ellmv(rocsparse_handle          handle,
                                 rocsparse_operation       trans,
                                 rocsparse_int             m,
                                 rocsparse_int             n,
                                 const double*             alpha,
                                 const rocsparse_mat_descr descr,
                                 const double*             ell_val,
                                 const rocsparse_int*      ell_col_ind,
                                 rocsparse_int             ell_width,
                                 const double*             x,
                                 const double*             beta,
                                 double*                   y)
{
    return rocsparse_dellmv(
        handle, trans, m, n, alpha, descr, ell_val, ell_col_ind, ell_width, x, beta, y);
}

template <>
rocsparse_status rocsparse_ellmv(rocsparse_handle           handle,
                                 rocsparse_operation        trans,
                                 rocsparse_int              m,
                                 rocsparse_int              n,
                                 const std::complex<float>* alpha,
                                 const rocsparse_mat_descr  descr,
                                 const std::complex<float>* ell_val,
                                 const rocsparse_int*       ell_col_ind,
                                 rocsparse_int              ell_width,
                                 const std::complex<float>* x,
                                 const std::complex<float>* beta,
                                 std::complex<float>*       y)
{
    return rocsparse_cellmv(handle,
                            trans,
                            m,
                            n,
                            (const rocsparse_float_complex*)alpha,
                            descr,
                            (const rocsparse_float_complex*)ell_val,
                            ell_col_ind,
                            ell_width,
                            (const rocsparse_float_complex*)x,
                            (const rocsparse_float_complex*)beta,
                            (rocsparse_float_complex*)y);
}

template <>
rocsparse_status rocsparse_ellmv(rocsparse_handle            handle,
                                 rocsparse_operation         trans,
                                 rocsparse_int               m,
                                 rocsparse_int               n,
                                 const std::complex<double>* alpha,
                                 const rocsparse_mat_descr   descr,
                                 const std::complex<double>* ell_val,
                                 const rocsparse_int*        ell_col_ind,
                                 rocsparse_int               ell_width,
                                 const std::complex<double>* x,
                                 const std::complex<double>* beta,
                                 std::complex<double>*       y)
{
    return rocsparse_zellmv(handle,
                            trans,
                            m,
                            n,
                            (const rocsparse_double_complex*)alpha,
                            descr,
                            (const rocsparse_double_complex*)ell_val,
                            ell_col_ind,
                            ell_width,
                            (const rocsparse_double_complex*)x,
                            (const rocsparse_double_complex*)beta,
                            (rocsparse_double_complex*)y);
}

/*
 * ===========================================================================
 *    level 3 SPARSE
 * ===========================================================================
 */
// csrmm
template <>
rocsparse_status rocsparse_csrmm(rocsparse_handle          handle,
                                 rocsparse_operation       trans_A,
                                 rocsparse_operation       trans_B,
                                 rocsparse_int             m,
                                 rocsparse_int             n,
                                 rocsparse_int             k,
                                 rocsparse_int             nnz,
                                 const float*              alpha,
                                 const rocsparse_mat_descr descr,
                                 const float*              csr_val,
                                 const rocsparse_int*      csr_row_ptr,
                                 const rocsparse_int*      csr_col_ind,
                                 const float*              B,
                                 rocsparse_int             ldb,
                                 const float*              beta,
                                 float*                    C,
                                 rocsparse_int             ldc)
{
    return rocsparse_scsrmm(handle,
                            trans_A,
                            trans_B,
                            m,
                            n,
                            k,
                            nnz,
                            alpha,
                            descr,
                            csr_val,
                            csr_row_ptr,
                            csr_col_ind,
                            B,
                            ldb,
                            beta,
                            C,
                            ldc);
}

template <>
rocsparse_status rocsparse_csrmm(rocsparse_handle          handle,
                                 rocsparse_operation       trans_A,
                                 rocsparse_operation       trans_B,
                                 rocsparse_int             m,
                                 rocsparse_int             n,
                                 rocsparse_int             k,
                                 rocsparse_int             nnz,
                                 const double*             alpha,
                                 const rocsparse_mat_descr descr,
                                 const double*             csr_val,
                                 const rocsparse_int*      csr_row_ptr,
                                 const rocsparse_int*      csr_col_ind,
                                 const double*             B,
                                 rocsparse_int             ldb,
                                 const double*             beta,
                                 double*                   C,
                                 rocsparse_int             ldc)
{
    return rocsparse_dcsrmm(handle,
                            trans_A,
                            trans_B,
                            m,
                            n,
                            k,
                            nnz,
                            alpha,
                            descr,
                            csr_val,
                            csr_row_ptr,
                            csr_col_ind,
                            B,
                            ldb,
                            beta,
                            C,
                            ldc);
}

template <>
rocsparse_status rocsparse_csrmm(rocsparse_handle           handle,
                                 rocsparse_operation        trans_A,
                                 rocsparse_operation        trans_B,
                                 rocsparse_int              m,
                                 rocsparse_int              n,
                                 rocsparse_int              k,
                                 rocsparse_int              nnz,
                                 const std::complex<float>* alpha,
                                 const rocsparse_mat_descr  descr,
                                 const std::complex<float>* csr_val,
                                 const rocsparse_int*       csr_row_ptr,
                                 const rocsparse_int*       csr_col_ind,
                                 const std::complex<float>* B,
                                 rocsparse_int              ldb,
                                 const std::complex<float>* beta,
                                 std::complex<float>*       C,
                                 rocsparse_int              ldc)
{
    return rocsparse_ccsrmm(handle,
                            trans_A,
                            trans_B,
                            m,
                            n,
                            k,
                            nnz,
                            (const rocsparse_float_complex*)alpha,
                            descr,
                            (const rocsparse_float_complex*)csr_val,
                            csr_row_ptr,
                            csr_col_ind,
                            (const rocsparse_float_complex*)B,
                            ldb,
                            (const rocsparse_float_complex*)beta,
                            (rocsparse_float_complex*)C,
                            ldc);
}

template <>
rocsparse_status rocsparse_csrmm(rocsparse_handle            handle,
                                 rocsparse_operation         trans_A,
                                 rocsparse_operation         trans_B,
                                 rocsparse_int               m,
                                 rocsparse_int               n,
                                 rocsparse_int               k,
                                 rocsparse_int               nnz,
                                 const std::complex<double>* alpha,
                                 const rocsparse_mat_descr   descr,
                                 const std::complex<double>* csr_val,
                                 const rocsparse_int*        csr_row_ptr,
                                 const rocsparse_int*        csr_col_ind,
                                 const std::complex<double>* B,
                                 rocsparse_int               ldb,
                                 const std::complex<double>* beta,
                                 std::complex<double>*       C,
                                 rocsparse_int               ldc)
{
    return rocsparse_zcsrmm(handle,
                            trans_A,
                            trans_B,
                            m,
                            n,
                            k,
                            nnz,
                            (const rocsparse_double_complex*)alpha,
                            descr,
                            (const rocsparse_double_complex*)csr_val,
                            csr_row_ptr,
                            csr_col_ind,
                            (const rocsparse_double_complex*)B,
                            ldb,
                            (const rocsparse_double_complex*)beta,
                            (rocsparse_double_complex*)C,
                            ldc);
}

/*
 * ===========================================================================
 *    conversion SPARSE
 * ===========================================================================
 */
// csr2csc
template <>
rocsparse_status rocsparse_csr2csc(rocsparse_handle     handle,
                                   rocsparse_int        m,
                                   rocsparse_int        n,
                                   rocsparse_int        nnz,
                                   const float*         csr_val,
                                   const rocsparse_int* csr_row_ptr,
                                   const rocsparse_int* csr_col_ind,
                                   float*               csc_val,
                                   rocsparse_int*       csc_row_ind,
                                   rocsparse_int*       csc_col_ptr,
                                   rocsparse_action     copy_values,
                                   rocsparse_index_base idx_base,
                                   void*                temp_buffer)
{
    return rocsparse_scsr2csc(handle,
                              m,
                              n,
                              nnz,
                              csr_val,
                              csr_row_ptr,
                              csr_col_ind,
                              csc_val,
                              csc_row_ind,
                              csc_col_ptr,
                              copy_values,
                              idx_base,
                              temp_buffer);
}

template <>
rocsparse_status rocsparse_csr2csc(rocsparse_handle     handle,
                                   rocsparse_int        m,
                                   rocsparse_int        n,
                                   rocsparse_int        nnz,
                                   const double*        csr_val,
                                   const rocsparse_int* csr_row_ptr,
                                   const rocsparse_int* csr_col_ind,
                                   double*              csc_val,
                                   rocsparse_int*       csc_row_ind,
                                   rocsparse_int*       csc_col_ptr,
                                   rocsparse_action     copy_values,
                                   rocsparse_index_base idx_base,
                                   void*                temp_buffer)
{
    return rocsparse_dcsr2csc(handle,
                              m,
                              n,
                              nnz,
                              csr_val,
                              csr_row_ptr,
                              csr_col_ind,
                              csc_val,
                              csc_row_ind,
                              csc_col_ptr,
                              copy_values,
                              idx_base,
                              temp_buffer);
}

template <>
rocsparse_status rocsparse_csr2csc(rocsparse_handle           handle,
                                   rocsparse_int              m,
                                   rocsparse_int              n,
                                   rocsparse_int              nnz,
                                   const std::complex<float>* csr_val,
                                   const rocsparse_int*       csr_row_ptr,
                                   const rocsparse_int*       csr_col_ind,
                                   std::complex<float>*       csc_val,
                                   rocsparse_int*             csc_row_ind,
                                   rocsparse_int*             csc_col_ptr,
                                   rocsparse_action           copy_values,
                                   rocsparse_index_base       idx_base,
                                   void*                      temp_buffer)
{
    return rocsparse_ccsr2csc(handle,
                              m,
                              n,
                              nnz,
                              (const rocsparse_float_complex*)csr_val,
                              csr_row_ptr,
                              csr_col_ind,
                              (rocsparse_float_complex*)csc_val,
                              csc_row_ind,
                              csc_col_ptr,
                              copy_values,
                              idx_base,
                              temp_buffer);
}

template <>
rocsparse_status rocsparse_csr2csc(rocsparse_handle            handle,
                                   rocsparse_int               m,
                                   rocsparse_int               n,
                                   rocsparse_int               nnz,
                                   const std::complex<double>* csr_val,
                                   const rocsparse_int*        csr_row_ptr,
                                   const rocsparse_int*        csr_col_ind,
                                   std::complex<double>*       csc_val,
                                   rocsparse_int*              csc_row_ind,
                                   rocsparse_int*              csc_col_ptr,
                                   rocsparse_action            copy_values,
                                   rocsparse_index_base        idx_base,
                                   void*                       temp_buffer)
{
    return rocsparse_zcsr2csc(handle,
                              m,
                              n,
                              nnz,
                              (const rocsparse_double_complex*)csr_val,
                              csr_row_ptr,
                              csr_col_ind,
                              (rocsparse_double_complex*)csc_val,
                              csc_row_ind,
                              csc_col_ptr,
                              copy_values,
                              idx_base,
                              temp_buffer);
}

// csr2ell
template <>
rocsparse_status rocsparse_csr2ell(rocsparse_handle          handle,
                                   rocsparse_int             m,
                                   const rocsparse_mat_descr csr_descr,
                                   const float*              csr_val,
                                   const rocsparse_int*      csr_row_ptr,
                                   const rocsparse_int*      csr_col_ind,
                                   const rocsparse_mat_descr ell_descr,
                                   rocsparse_int             ell_width,
                                   float*                    ell_val,
                                   rocsparse_int*            ell_col_ind)
{
    return rocsparse_scsr2ell(handle,
                              m,
                              csr_descr,
                              csr_val,
                              csr_row_ptr,
                              csr_col_ind,
                              ell_descr,
                              ell_width,
                              ell_val,
                              ell_col_ind);
}

template <>
rocsparse_status rocsparse_csr2ell(rocsparse_handle          handle,
                                   rocsparse_int             m,
                                   const rocsparse_mat_descr csr_descr,
                                   const double*             csr_val,
                                   const rocsparse_int*      csr_row_ptr,
                                   const rocsparse_int*      csr_col_ind,
                                   const rocsparse_mat_descr ell_descr,
                                   rocsparse_int             ell_width,
                                   double*                   ell_val,
                                   rocsparse_int*            ell_col_ind)
{
    return rocsparse_dcsr2ell(handle,
                              m,
                              csr_descr,
                              csr_val,
                              csr_row_ptr,
                              csr_col_ind,
                              ell_descr,
                              ell_width,
                              ell_val,
                              ell_col_ind);
}

template <>
rocsparse_status rocsparse_csr2ell(rocsparse_handle           handle,
                                   rocsparse_int              m,
                                   const rocsparse_mat_descr  csr_descr,
                                   const std::complex<float>* csr_val,
                                   const rocsparse_int*       csr_row_ptr,
                                   const rocsparse_int*       csr_col_ind,
                                   const rocsparse_mat_descr  ell_descr,
                                   rocsparse_int              ell_width,
                                   std::complex<float>*       ell_val,
                                   rocsparse_int*             ell_col_ind)
{
    return rocsparse_ccsr2ell(handle,
                              m,
                              csr_descr,
                              (const rocsparse_float_complex*)csr_val,
                              csr_row_ptr,
                              csr_col_ind,
                              ell_descr,
                              ell_width,
                              (rocsparse_float_complex*)ell_val,
                              ell_col_ind);
}

template <>
rocsparse_status rocsparse_csr2ell(rocsparse_handle            handle,
                                   rocsparse_int               m,
                                   const rocsparse_mat_descr   csr_descr,
                                   const std::complex<double>* csr_val,
                                   const rocsparse_int*        csr_row_ptr,
                                   const rocsparse_int*        csr_col_ind,
                                   const rocsparse_mat_descr   ell_descr,
                                   rocsparse_int               ell_width,
                                   std::complex<double>*       ell_val,
                                   rocsparse_int*              ell_col_ind)
{
    return rocsparse_zcsr2ell(handle,
                              m,
                              csr_descr,
                              (const rocsparse_double_complex*)csr_val,
                              csr_row_ptr,
                              csr_col_ind,
                              ell_descr,
                              ell_width,
                              (rocsparse_double_complex*)ell_val,
                              ell_col_ind);
}

// ell2csr
template <>
rocsparse_status rocsparse_ell2csr(rocsparse_handle          handle,
                                   rocsparse_int             m,
                                   rocsparse_int             n,
                                   const rocsparse_mat_descr ell_descr,
                                   rocsparse_int             ell_width,
                                   const float*              ell_val,
                                   const rocsparse_int*      ell_col_ind,
                                   const rocsparse_mat_descr csr_descr,
                                   float*                    csr_val,
                                   const rocsparse_int*      csr_row_ptr,
                                   rocsparse_int*            csr_col_ind)
{
    return rocsparse_sell2csr(handle,
                              m,
                              n,
                              ell_descr,
                              ell_width,
                              ell_val,
                              ell_col_ind,
                              csr_descr,
                              csr_val,
                              csr_row_ptr,
                              csr_col_ind);
}

template <>
rocsparse_status rocsparse_ell2csr(rocsparse_handle          handle,
                                   rocsparse_int             m,
                                   rocsparse_int             n,
                                   const rocsparse_mat_descr ell_descr,
                                   rocsparse_int             ell_width,
                                   const double*             ell_val,
                                   const rocsparse_int*      ell_col_ind,
                                   const rocsparse_mat_descr csr_descr,
                                   double*                   csr_val,
                                   const rocsparse_int*      csr_row_ptr,
                                   rocsparse_int*            csr_col_ind)
{
    return rocsparse_dell2csr(handle,
                              m,
                              n,
                              ell_descr,
                              ell_width,
                              ell_val,
                              ell_col_ind,
                              csr_descr,
                              csr_val,
                              csr_row_ptr,
                              csr_col_ind);
}

template <>
rocsparse_status rocsparse_ell2csr(rocsparse_handle           handle,
                                   rocsparse_int              m,
                                   rocsparse_int              n,
                                   const rocsparse_mat_descr  ell_descr,
                                   rocsparse_int              ell_width,
                                   const std::complex<float>* ell_val,
                                   const rocsparse_int*       ell_col_ind,
                                   const rocsparse_mat_descr  csr_descr,
                                   std::complex<float>*       csr_val,
                                   const rocsparse_int*       csr_row_ptr,
                                   rocsparse_int*             csr_col_ind)
{
    return rocsparse_cell2csr(handle,
                              m,
                              n,
                              ell_descr,
                              ell_width,
                              (const rocsparse_float_complex*)ell_val,
                              ell_col_ind,
                              csr_descr,
                              (rocsparse_float_complex*)csr_val,
                              csr_row_ptr,
                              csr_col_ind);
}

template <>
rocsparse_status rocsparse_ell2csr(rocsparse_handle            handle,
                                   rocsparse_int               m,
                                   rocsparse_int               n,
                                   const rocsparse_mat_descr   ell_descr,
                                   rocsparse_int               ell_width,
                                   const std::complex<double>* ell_val,
                                   const rocsparse_int*        ell_col_ind,
                                   const rocsparse_mat_descr   csr_descr,
                                   std::complex<double>*       csr_val,
                                   const rocsparse_int*        csr_row_ptr,
                                   rocsparse_int*              csr_col_ind)
{
    return rocsparse_zell2csr(handle,
                              m,
                              n,
                              ell_descr,
                              ell_width,
                              (const rocsparse_double_complex*)ell_val,
                              ell_col_ind,
                              csr_descr,
                              (rocsparse_double_complex*)csr_val,
                              csr_row_ptr,
                              csr_col_ind);
}
