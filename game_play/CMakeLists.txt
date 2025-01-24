# COPYRIGHT

project(game_play)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME}
    STATIC
        board.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        snake_lib
)
