
set(ServerSrc
    main.cpp
)

add_subdirectory(common)
add_subdirectory(service)

add_executable(BearGame ${ServerSrc})

target_link_libraries(BearGame
    common
    service
    base
    
    # scriptservice 依赖于 service
    scriptservice
    
    # third party
    lua
)