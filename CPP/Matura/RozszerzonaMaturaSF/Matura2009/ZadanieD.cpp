#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "slowa.txt";

// =====================================================================

bool ContainsSubstring(const std::string& a, const std::string& b) {
    return a.find(b) != std::string::npos;
}

bool ContainsSubstringFull(const std::string& str1, const std::string& str2) {
    if (str1.size() < str2.size()) { return false; }
    size_t maxLen = str1.size() - str2.size() + 1;

    for (size_t shift = 0; shift < maxLen; shift++) {
        bool match = true;
        for (size_t i = 0; i < str2.size(); i++) {
            if (str1[shift + i] != str2[i]) { match = false; break; }
        }

        if (match) { return true; }
    }

    return false; 
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

    return mergeAB.size() <= mergeBA.size() ? mergeAB : mergeBA;
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
