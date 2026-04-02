#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "slowa.txt";

// =====================================================================

bool ContainsSubstring(const std::string& a, const std::string& b) {
    return a.find(b) != std::string::npos;
}

std::string MergeWithOverlap(const std::string& first, const std::string& second) {
    int maxOverlap = 0;
    
    for (int i = 1; i <= first.size() && i <= second.size(); i++) {
        bool matches = true;
        
        for (int j = 0; j < i; j++) {
            if (first[first.size() - i + j] != second[j]) {
                matches = false;
                break;
            }
        }
        
        if (matches) { maxOverlap = i; }
    }
    
    std::string result = first;
    for (size_t i = maxOverlap; i < second.size(); i++) {
        result += second[i];
    }
    
    return result;
}

std::string FindShortestWord(const std::string& a, const std::string& b) {
    if (ContainsSubstring(a, b)) { return a; }
    
    std::string mergeAB = MergeWithOverlap(a, b);
    std::string mergeBA = MergeWithOverlap(b, a);
    
    if (mergeAB.size() <= mergeBA.size()) { return mergeAB; }
    else { return mergeBA; }
}

int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    std::ofstream outputFile(OUTPUT_FILE_NAME);
    
    std::string a, b;
    
    while (inputFile >> a >> b) {
        std::string c = FindShortestWord(a, b);
        outputFile << c << "\n";
    }
    
    return 0;
}
