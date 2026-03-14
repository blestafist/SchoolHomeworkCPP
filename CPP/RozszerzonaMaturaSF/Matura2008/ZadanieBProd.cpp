#include <iostream>
#include <fstream>

// ============================================ CONFIGURATION ============================================

const std::string INPUT_FILE_NAME = "slowa.txt";
const std::string PASS_FILE_NAME = "hasla_b.txt";
const std::string ANSWERS_FILE_NAME = "slowa_b.txt";

// =======================================================================================================

bool IsPalidrome(const std::string& str, int len) {
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) { return false; }
    }

    return true;
}


std::string ComposeW2(const std::string& origin) {
    int w1Len = 1;

    for (int i = origin.size(); i >= 1; i--) {
        if (IsPalidrome(origin, i)) { w1Len = i; break; }
    }

    std::string result = "";
    for (int i = origin.size() - 1; i >= w1Len; i--) {
        result += origin[i];
    }

    return result;
}


int main() {

}