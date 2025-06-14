#include "asm_math.h"

int AsmMath::fastMul(int a, int b) {
    int result;
    asm volatile (
        "imull %[b], %[a]\\n\\t"
        : [a] "+r" (a)
        : [b] "r" (b)
    );
    result = a;
    return result;
}

int AsmMath::fastAdd(int a, int b) {
    asm volatile (
        "addl %[b], %[a]"
        : [a] "+r" (a)
        : [b] "r" (b)
    );
    return a;
}

float AsmMath::inverseRoot(float value) {
    float result;
    asm volatile (
        "rsqrtss %[val], %[res]"
        : [res] "=x" (result)
        : [val] "x" (value)
    );
    return result;
}
