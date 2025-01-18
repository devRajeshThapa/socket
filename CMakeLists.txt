cmake_minimum_required(VERSION 3.28.3)

project(socket LANGUAGES C CXX)

set(CMAKE_CXX_STANDARDS 14)

include_directories(include)

add_executable(server src/server.cpp)
add_executable(client  src/client.cpp)

install(TARGETS server RUNTIME DESTINATION bin)
install(TARGETS client RUNTIME DESTINATION bin)
install(FILES LICENSE DESTINATION docs)
install(FILES docs/README_DIST.md DESTINATION docs RENAME README.md)
