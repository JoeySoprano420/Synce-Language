#pragma once
#include <immintrin.h>

class IntrinsicRegisters {
public:
    static __m256 vecAdd(__m256 a, __m256 b);
    static __m256 vecMul(__m256 a, __m256 b);
};
