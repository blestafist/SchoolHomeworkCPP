#include "parser.h"

char HeaderLever(const std::string &header) {
    char i; // 0 means invalid header

    for (i = 0; i < 6; i++) {
        if (header[i] != '#') { i--; break; }
    }

    if (header[i + 1] != ' ') { return 0; }
    return i;
}
