#include <windows.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <ranges>
#include <algorithm>

#include "CrossView.h"
#include "CrossViewNoop.h"
#include "CrossViewWin32.h"

#if defined(_CONSOLE) // Define this in your console build configuration
int main(int argc, char* argv[]) {
    try {
        auto args = std::vector<std::string>(argv + 1, argv + argc);
        bool headless = std::ranges::any_of(args, [](const std::string& arg) {
            return arg == "--headless";
            });

        if (headless) {
            std::cout << "Running in headless mode.\n";

            std::string input;
            while (true) {
                std::cout << "Enter a command (type 'exit' to quit): ";
                std::getline(std::cin, input);

                if (input == "exit") {
                    break;
                }
                else if (input == "status") {
                    std::cout << "Application is running in headless mode.\n";
                }
                else {
                    std::cout << "Unknown command: " << input << '\n';
                }
            }
        }
        else {
            std::cerr << "No headless mode flag provided. Exiting.\n";
            return -1;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << '\n';
        return -1;
    }

    return 0;
}

#else // Default to WinMain for desktop application
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    try {
        std::string cmdLine(lpCmdLine);
        bool headless = cmdLine.find("--headless") != std::string::npos;

        if (headless) {
            // Allocate a new console only once
            if (AllocConsole()) {
                FILE* fp;
                freopen_s(&fp, "CONOUT$", "w", stdout); // Redirect stdout to the new console
                freopen_s(&fp, "CONOUT$", "w", stderr); // Redirect stderr to the new console
                freopen_s(&fp, "CONIN$", "r", stdin);   // Redirect stdin to the new console

                std::cout << "Running in headless mode.\n";

                std::string input;
                while (true) {
                    std::cout << "Enter a command (type 'exit' to quit): ";
                    std::getline(std::cin, input);

                    if (input == "exit") {
                        break;
                    }
                    else if (input == "status") {
                        std::cout << "Application is running in headless mode.\n";
                    }
                    else {
                        std::cout << "Unknown command: " << input << '\n';
                    }
                }

                FreeConsole(); // Release the console
            }
        }
        else {
            // Regular GUI mode
            auto crossView = CrossViewer::CrossView::createCrossView();
            if (!crossView) {
                throw std::runtime_error("Failed to create CrossView instance.");
            }

            crossView->createWindow(L"Sample Window", 800, 600);
            crossView->mainLoop();
            crossView->shutdown();
        }

    }
    catch (const std::exception& e) {
        MessageBoxA(nullptr, e.what(), "Error", MB_OK | MB_ICONERROR);
        return -1;
    }

    return 0;
}
#endif
