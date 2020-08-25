
set(ServerSrc
    main.cpp
)

add_subdirectory(common)

add_executable(BearGame ${ServerSrc})

target_link_libraries(BearGame

    common
    base

    # third party
    lua
)