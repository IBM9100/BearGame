#ifndef BEARGAME_BASE_NONCOPYABLE_H
#define BEARGAME_BASE_NONCOPYABLE_H

namespace BearGame {

class Noncopyable {
public:
    Noncopyable(const Noncopyable&) = delete;
    void operator=(const Noncopyable&) = delete;
protected:
    Noncopyable() = default;
    ~Noncopyable() = default;
};


}

#endif