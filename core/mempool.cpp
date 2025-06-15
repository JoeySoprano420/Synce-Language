#include "mempool.h"

template<typename T>
MemoryPool<T>::MemoryPool(size_t capacity) {
    for (size_t i = 0; i < capacity; ++i) {
        T* block = new T();
        pool.push_back(block);
        freeStack.push(block);
    }
}

template<typename T>
T* MemoryPool<T>::allocate() {
    if (freeStack.empty()) return new T();
    T* block = freeStack.top();
    freeStack.pop();
    return block;
}

template<typename T>
void MemoryPool<T>::deallocate(T* ptr) {
    freeStack.push(ptr);
}
