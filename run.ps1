cmake -G Ninja -B build -S . -D CMAKE_BUILD_TYPE=Release -D CMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
.\build\bin\webview_app.exe
