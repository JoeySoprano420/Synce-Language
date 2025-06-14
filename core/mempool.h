#pragma once
#include <cstdint>
#include <vector>
#include <stack>

template<typename T>
class MemoryPool {
public:
    MemoryPool(size_t capacity);
    T* allocate();
    void deallocate(T* ptr);

private:
    std::vector<T*> pool;
    std::stack<T*> freeStack;
};
