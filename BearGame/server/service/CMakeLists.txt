set(ServiceSrc
    Service.cpp
    ServiceMgr.cpp
)

add_subdirectory(script)

add_library(service ${ServiceSrc})