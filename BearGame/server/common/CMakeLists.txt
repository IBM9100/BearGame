set(ConfigSrc
    config/Config.cpp
)


set(LogSrc
    log/Logging.cpp
    log/LogStream.cpp
    log/LogFile.cpp
)

set(CommonSrc
    ${ConfigSrc}
    ${LogSrc}
)

add_library(common ${CommonSrc})