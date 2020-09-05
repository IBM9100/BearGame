#ifndef BEARGAME_SERVER_COMMON_LOG_COLORFUL
#define BEARGAME_SERVER_COMMON_LOG_COLORFUL

namespace BearGame {

enum class Colorful : uint8_t {
    highlight = 1,
    grey = 30,
    red = 31,
    green = 32,
    yellow = 33,
    blue = 34,
    magenta = 35,
    cyan = 36,
    white = 37,
    onGrey = 40,
    onRed = 41,
    onGreen = 42,
    onYellow = 43,
    onBlue = 44,
    onMagenta = 45,
    onCyan = 46,
    onWhite = 47,
    end = 0,
    transparent,
    reset
};

LogStream& operator<<(LogStream& stream, const Colorful color) {
    if (color == Colorful::reset)
        stream << "\033[m";
    else if (color != Colorful::transparent)
        stream << "\033[" << static_cast<uint32_t>(color) << "m";
    return stream;
}

}

#endif