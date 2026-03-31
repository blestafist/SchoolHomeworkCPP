#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "zad_5.txt";

// =====================================================================

bool Match(const std::string& a, const std::string& b, int offset) {
    for (int i = 0; i + offset < a.size() && i < b.size(); i++) {
        if (a[i + offset] != b[i]) { return false; }
    }

    return true;
}

int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    std::ofstream outputFile(OUTPUT_FILE_NAME, std::ios::app);
    
    std::string a, b;
    int concatenationOnlyCount = 0;
    
    while (inputFile >> a >> b) {
        bool hasAnyOverlap = false;
        for (int i = 0; i < a.size() && !hasAnyOverlap; i++) {
            if (Match(a, b, i)) { hasAnyOverlap = true; }
        }

        for (int i = 1; i < b.size() && !hasAnyOverlap; i++) {
            if (Match(b, a, i)) { hasAnyOverlap = true; }
        }

        if (!hasAnyOverlap) { concatenationOnlyCount++; }
    }
    
    std::cout << "c) " << concatenationOnlyCount << "\n";
    outputFile << "c) " << concatenationOnlyCount << "\n";
    
    return 0;
}
