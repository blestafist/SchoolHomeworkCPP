#include "renderer.h"

void PrintDivider(char flag, const std::string &style) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    std::cout << style;

    for (short i = 0; i < w.ws_col; i++) {
        std::cout << flag;
    }

    std::cout << Style::RESET << "\n\n";
}

