cmake_minimum_required(VERSION 3.16)
project(webview_app LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

include(FetchContent)

# Build only the static WebView library only.
set(WEBVIEW_BUILD_SHARED_LIBRARY OFF CACHE BOOL "" FORCE)
set(WEBVIEW_BUILD_STATIC_LIBRARY ON CACHE BOOL "" FORCE)

FetchContent_Declare(
    webview
    GIT_REPOSITORY https://github.com/webview/webview
    GIT_TAG 0.12.0
)
FetchContent_MakeAvailable(webview)

FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/latest/download/json.tar.xz
)
set(JSON_BuildTests OFF CACHE INTERNAL "")
set(JSON_Install OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(json)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.c" "src/*.cpp")

add_executable(webview_app WIN32)
target_sources(webview_app PRIVATE ${SOURCES})
target_link_libraries(webview_app PRIVATE webview::core nlohmann_json::nlohmann_json)
