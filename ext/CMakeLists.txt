cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(ext)

add_subdirectory(EmbGenParser)

add_subdirectory(EmbMessenger)

add_subdirectory(sini)

if (NOT TARGET gtest AND EmbCom_ENABLE_TESTING)
    set(gtest_force_shared_crt TRUE CACHE BOOL "")
    add_subdirectory(googletest)
endif()

add_library(nlohmann_json INTERFACE)
target_include_directories(nlohmann_json INTERFACE json/include)

add_subdirectory(sol2)

add_subdirectory(serial)

add_library(linenoise INTERFACE)
target_include_directories(linenoise INTERFACE cpp-linenoise)
