#ifndef BEARGAME_BASE_CONVERT_H
#define BEARGAME_BASE_CONVERT_H

#include <cstddef>

namespace BearGame {

const char digits[] = "9876543210123456789";
const char* zero = digits + 9;
// const char digitsHex[] = "0123456789ABCDEF";

template<typename T>
size_t Convert(char buf[], T value) {
    T i = value;
    char* p = buf;

    while (i != 0) {
        int lsd = static_cast<int>(i % 10);
        i /= 10;
        *p++ = zero[lsd];
    }

    if (value < 0) {
        *p++ = '-';
    }
    *p = '\0';
    std::reverse(buf, p);
    return p - buf;
}

// size_t convertHex(char buf[], uintptr_t value) {

// }

}


#endif