#include <iostream>
#include <fstream>
#include <string>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE = "dane.txt";
const std::string OUTPUT_FILE = "zad_5.txt";

// =====================================================================

bool ContainsSubstring(const std::string& a, const std::string& b) {
    if (b.size() > a.size()) { return false; }
    
    size_t maxStartPos = a.size() - b.size() + 1;
    
    for (size_t i = 0; i < maxStartPos; i++) {
        bool found = true;
        for (size_t j = 0; j < b.size(); j++) {
            if (a[i + j] != b[j]) { found = false; break; }
        }
        if (found) { return true; }
    }
    
    return false;
}

int main() {
    std::ifstream inputFile(INPUT_FILE);
    std::ofstream outputFile(OUTPUT_FILE, std::ios::app);
    
    std::string a, b;
    int containsCount = 0;
    
    while (inputFile >> a >> b) {
        if (ContainsSubstring(a, b)) { containsCount++; }
    }
    
    outputFile << "b) " << containsCount << "\n";
    
    return 0;
}
