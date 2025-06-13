ThreadPool pool;

void execute_task(IRNode* task) {
    if (needs_jit(task)) {
        compile_jit(task); // compile just-in-time
    }
    execute(task);
}
