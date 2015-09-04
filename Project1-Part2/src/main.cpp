#include "main.hpp"

int main(int argc, char* argv[]) {
	printf("testing matrix_math!\n");
	CUDA_matrix_math::initialize();
	float *hst_mat_A = (float*)malloc(sizeof(float) * 25);
	float *hst_mat_B = (float*)malloc(sizeof(float) * 25);
	float *hst_mat_C = (float*)malloc(sizeof(float) * 25);

	for (int i = 0; i < 25; i++) {
		hst_mat_A[i] = i + 1;
		hst_mat_B[i] = i + 1;
	}

	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			printf("%f ", hst_mat_A[i + j * 5]);
		}
		printf("\n");
	}

	CUDA_matrix_math::cuda_mat_mul(hst_mat_A, hst_mat_B, hst_mat_C);
	printf("\n");

	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			printf("%f ", hst_mat_C[i + j * 5]);
		}
		printf("\n");
	}
	printf("done!");
}