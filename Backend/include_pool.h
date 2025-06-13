#pragma once
#include <vector>

template<typename T>
class NodePool {
    std::vector<T*> pool;
public:
    T* acquire();
    void release(T* node);
};
