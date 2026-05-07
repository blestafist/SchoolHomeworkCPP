#include <clocale>
#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string TO_DECTRYPT_FILE = "sz.txt";
const std::string DECRYPTION_KEYS_FILE = "klucze2.txt";

const std::string OUTPUT_FILE = "wynik4b.txt";

const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// =====================================================================

char IndexOf(const std::string& arr, char val) {
    for (char i = 0; i < arr.size(); i++) {
        if (arr[i] == val) { return ++i; }
    }

    return -1;
}

void DecryptWord(std::string& word, const std::string& keys) {
    for (char i = 0; i < word.size(); i++) {
        word[i] -= IndexOf(ALPHABET, keys[i % keys.size()]);

        if (word[i] < 65) { word[i] += 26; }
    }
}


int main() {
    setlocale(LC_ALL, "pl");

    std::ifstream toEncryptFile (TO_DECTRYPT_FILE), encryptionKeysFile(DECRYPTION_KEYS_FILE);
    std::ofstream outputFile (OUTPUT_FILE);

    if (!toEncryptFile.is_open() || !encryptionKeysFile.is_open()) {
        std::cout << "Error opening file!";
    }
    
    std::string tempWord, tempKey;

    while (toEncryptFile >> tempWord && encryptionKeysFile >> tempKey) {
        DecryptWord(tempWord, tempKey); 
        std::cout << tempWord << "\n";
        outputFile << tempWord << "\n";
    }

    outputFile.close();
    encryptionKeysFile.close();
    toEncryptFile.close();

    return 0;
}