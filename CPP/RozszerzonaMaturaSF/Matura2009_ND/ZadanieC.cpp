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

bool HasOverlap(const std::string& a, const std::string& b) {
    // Check if suffix of A matches prefix of B
    for (int i = 1; i < (int)a.size(); i++) {
        bool matches = true;
        size_t overlapLen = a.size() - i;
        
        if (overlapLen > b.size()) { continue; }
        
        for (size_t j = 0; j < overlapLen; j++) {
            if (a[i + j] != b[j]) { matches = false; break; }
        }
        
        if (matches) { return true; }
    }
    
    // Check if suffix of B matches prefix of A
    for (int i = 1; i < (int)b.size(); i++) {
        bool matches = true;
        size_t overlapLen = b.size() - i;
        
        if (overlapLen > a.size()) { continue; }
        
        for (size_t j = 0; j < overlapLen; j++) {
            if (b[i + j] != a[j]) { matches = false; break; }
        }
        
        if (matches) { return true; }
    }
    
    return false;
}

int main() {
    std::ifstream inputFile(INPUT_FILE);
    std::ofstream outputFile(OUTPUT_FILE, std::ios::app);
    
    std::string a, b;
    int concatenationOnlyCount = 0;
    
    while (inputFile >> a >> b) {
        if (!ContainsSubstring(a, b) && !HasOverlap(a, b)) {
            concatenationOnlyCount++;
        }
    }
    
    outputFile << "c) " << concatenationOnlyCount << "\n";
    
    return 0;
}
