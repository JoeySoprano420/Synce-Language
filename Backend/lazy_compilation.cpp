// Only compiles when first used
IR* get_or_compile(IRCache* cache, const char* path) {
    if (!cache->compiled[path]) {
        cache->compiled[path] = compile_to_ir(path);
        fold_constants(cache->compiled[path]);
        unroll_loops(cache->compiled[path]);
    }
    return cache->compiled[path];
}
