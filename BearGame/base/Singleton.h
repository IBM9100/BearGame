#ifndef BEARGAME_BASE_SINGLETON_H
#define BEARGAME_BASE_SINGLETON_H

#include "base/Noncopyable.h"

namespace BearGame {


template <typename T>
class Singleton : private Noncopyable {
public:
    static T& instance() {
        static T t;
        return t;
    }
protected:
    Singleton() {}
    virtual ~Singleton() {}
};


}

#endif