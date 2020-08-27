set(ConfigSrc
    config/Config.cpp
)

set(ServiceSrc
    service/ServiceMgr.cpp
)

set(LogSrc
    log/Logging.cpp
    log/LogStream.cpp
)

set(CommonSrc
    ${ConfigSrc}
    ${ServiceSrc}
    ${LogSrc}
)

add_library(common ${CommonSrc})