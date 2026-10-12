#define TITLE "WebView App"
#define FACTOR (80)
#define WIDTH (16 * FACTOR)
#define HEIGHT (9 * FACTOR)

#include "html.h"
#include <nlohmann/json.hpp>
#include <webview/webview.h>

#include <iostream>
#include <fstream>
#include <sstream>
using json = nlohmann::json;

std::string read_file(const std::string& path) {
    std::cout << "read_file() \n Path:\n" << path << std::endl;
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file: " + path);

    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE /*hInst*/, HINSTANCE /*hPrevInst*/, LPSTR /*lpCmdLine*/,
                   int /*nCmdShow*/) {
#else
int main() {
#endif
  try {
    webview::webview w(false, nullptr);
    w.set_title(TITLE);
    w.set_size(WIDTH, HEIGHT, WEBVIEW_HINT_NONE);
    w.bind("readFile", [&](const std::string& args_str) -> std::string {
        json args = json::parse(args_str);
        std::string file_path = args[0].get<std::string>();
        std::string file_contents = read_file(file_path);
        json result = file_contents;
        return result.dump();
    });
    w.set_html(HTML);
    w.run();
  } catch (const webview::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }

  return 0;
}
