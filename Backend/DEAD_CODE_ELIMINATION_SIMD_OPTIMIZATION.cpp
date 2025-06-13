// Dead Code Removal
bool is_dead(Instruction* instr, UsageMap* use_map) {
    return !use_map->is_used(instr->output);
}

// SIMD optimization example
// float4x4 matrix multiplication fused into SIMD intrinsic
__m128 matmul_simd(__m128 row1, __m128 row2, __m128 row3, __m128 row4);
