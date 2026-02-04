#include <clocale>
#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string TO_ENCTRYPT_FILE = "tj.txt";
const std::string ENCRYPTION_KEYS_FILE = "klucze1.txt";

const std::string OUTPUT_FILE = "wynik4a.txt";

const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// =====================================================================

char IndexOf(const std::string& arr, char val) {
    for (char i = 0; i < arr.size(); i++) {
        if (arr[i] == val) { return ++i; }
    }

    return -1;
}

void EncryptWord(std::string& word, const std::string& keys) {
    for (char i = 0; i < word.size(); i++) {
        word[i] += IndexOf(ALPHABET, keys[i % keys.size()]);

        if (word[i] > 90) { word[i] -= 26; }
    }
}


int main() {
    setlocale(LC_ALL, "pl");

    std::ifstream toEncryptFile (TO_ENCTRYPT_FILE), encryptionKeysFile(ENCRYPTION_KEYS_FILE);
    std::ofstream outputFile (OUTPUT_FILE);

    if (!toEncryptFile.is_open() || !encryptionKeysFile.is_open()) {
        std::cout << "Error opening file!";
    }
    
    std::string tempWord, tempKey;

    while (toEncryptFile >> tempWord && encryptionKeysFile >> tempKey) {
        EncryptWord(tempWord, tempKey); 
        std::cout << tempWord << "\n";
        outputFile << tempWord << "\n";
    }

    outputFile.close();
    encryptionKeysFile.close();
    toEncryptFile.close();

    return 0;
}