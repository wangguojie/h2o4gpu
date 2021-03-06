#pragma once

#ifdef WIN32
#define tsvd_export __declspec(dllexport)
#else
#define tsvd_export
#endif

#include "../data/matrix.cuh"

namespace tsvd


{

	extern "C"
	{
		struct params
		{
			int X_n;
			int X_m;
			int k;
			const char* algorithm;
			int n_iter;
			int random_state;
			float tol;
			int verbose;
			int gpu_id;
		};

		/**
		 *
		 * \param 		  	_X
		 * \param [in,out]	_Q
		 * \param [in,out]	_w
		 * \param [in,out]  _U
		 * \param 		  	_param
		 */

		tsvd_export void truncated_svd_float(const float *_X, float *_Q, float *_w, float *_U, params _param);
		tsvd_export void truncated_svd_double(const double *_X, double *_Q, double *_w, double *_U, params _param);
		tsvd_export void truncated_svd(const double *_X, double *_Q, double *_w, double *_U, params _param);

	}

	template<typename T, typename S>
	void cusolver_tsvd(Matrix<T> &X, S _Q, S _w, S _U, params _param);

	template<typename T, typename S>
	void power_tsvd(Matrix<T> &X, S _Q, S _w, S _U, params _param);

	template<typename T, typename S>
	tsvd_export void truncated_svd_matrix(Matrix<T> &X, S _Q, S _w, S _U, params _param);

	void outer_product(Matrix<float>& A, float eigen_value, const Matrix<float>& eigen_vector, const Matrix<float>& eigen_vector_transpose, DeviceContext& context);
	void outer_product(Matrix<double>& A, float eigen_value, const Matrix<double>& eigen_vector, const Matrix<double>& eigen_vector_transpose, DeviceContext& context);

}
