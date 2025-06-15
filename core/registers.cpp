#include "registers.h"

__m256 IntrinsicRegisters::vecAdd(__m256 a, __m256 b) {
    return _mm256_add_ps(a, b);
}

__m256 IntrinsicRegisters::vecMul(__m256 a, __m256 b) {
    return _mm256_mul_ps(a, b);
}
