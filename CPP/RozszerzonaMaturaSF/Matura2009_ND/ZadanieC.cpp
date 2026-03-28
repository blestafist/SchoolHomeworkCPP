#include <iostream>
#include <fstream>
#include <string>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE = "dane.txt";
const std::string OUTPUT_FILE = "zad_5.txt";

// =====================================================================

bool Match(const std::string& s1, const std::string& s2, int offset) {
    for (int i = 0; offset + i < s1.size() && i < s2.size(); ++i) {
        if (s1[offset + i] != s2[i]) return false;
    }
    return true;
}


int main() {
    std::ifstream inputFile(INPUT_FILE);
    std::ofstream outputFile(OUTPUT_FILE, std::ios::app);
    
    std::string a, b;
    int concatenationOnlyCount = 0;
    
    while (inputFile >> a >> b) {
        bool hasAnyOverlap = false;

        for (int i = 0; i < a.size(); i++) {
            if (Match(a, b, i)) { hasAnyOverlap = true; }
        }

        for (int i = 1; i < b.size(); i++) {
            if (Match(b, a, i)) { hasAnyOverlap = true; }
        }

        if (!hasAnyOverlap) { concatenationOnlyCount++;  }
    }
    
    outputFile << "c) " << concatenationOnlyCount << "\n";
    
    return 0;
}
