#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "zad_5.txt";

// =====================================================================

bool ContainsSubstring(const std::string& a, const std::string& b) {
    if (b.size() > a.size()) { return false; }
    int maxLen = a.size() - b.size() + 1;

    for (size_t i = 0; i < maxLen; i++) {
        bool match = true;

        for (size_t j = 0; j < b.size(); j++) {
            if (a[i + j] != b[j]) { match = false; break; }
        }

        if (match) { return true; }
    }

    return false;
}

bool ContainsSubstringShort(const std::string& a, const std::string& b) {
    return a.find(b) != std::string::npos;
}

int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    std::ofstream outputFile(OUTPUT_FILE_NAME, std::ios::app);
    
    std::string a, b;
    int containsCount = 0;
    
    while (inputFile >> a >> b) {
        if (ContainsSubstringShort(a, b)) { containsCount++; }
    }
    
    std::cout << "b) " << containsCount << "\n";
    outputFile << "b) " << containsCount << "\n";
    
    return 0;
}
