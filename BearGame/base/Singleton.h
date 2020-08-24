#ifndef BEARGAME_BASE_SINGLETON_H
#define BEARGAME_BASE_SINGLETON_H

#include "BearGame/base/Noncopyable.h"

namespace BearGame {


template <typename T>
class Singleton : private Noncopyable {
public:
    Singleton() = delete;
    ~Singleton() = delete;
public:
    static T& Instance() {
        static T t;
        return t;
    }
};


}

#endif