#include <iostream>
#include <fstream>

// ============================================ CONFIGURATION ============================================

const std::string INPUT_FILE_NAME = "bloki1.txt";
const std::string OUTPUT_FILE_NAME = "wyniki.txt";

const int MOD_BLOCK = 3; // блок модулей (в этом задании *троичный* блок)

// =======================================================================================================


int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME);

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    short tempNum;
    int i = 0,
    localMod = 0, // local mod used to count the current mod in loop
    bestLength = 0, // best length found
    startIndexes[3] = { -1, -2, -2 }, // так называемые колышки, индексы начала массива с определенным остатком
    startIndex = 0, // индекс начала для лучшей длинны
    endIndex = 0; // индекс конца для лучшей длинны


    while (inputFile >> tempNum) { // читаем из файла
        localMod = (localMod + tempNum) % MOD_BLOCK; // локальный модуль, абьюзим свойства модулей по максимуму (остаток суммы = остаток суммы остатков)
        // (A + B) (mod C) = (A (mod C) + B (mod C)) (mod C)

        if (startIndexes[localMod] == -2) { // если не было колышка
            startIndexes[localMod] = i;  // присваиваем
        }

        else { // если колышек уже воткнут
            int len = i - startIndexes[localMod]; // рассчитываем длинну от текущей позиции до колышка
            if (len > bestLength) { // сравниваем длинну с лучшей
                bestLength = len;
                startIndex = startIndexes[localMod] + 2; // + 2 для того чтобы получить человеческие индексы (от единицы),
                // тк нам надо компенсировать идексы от 0 + еще не включая сам колышек (так как сумму мы считаем не включая колышек)
                endIndex = i + 1; // + 1 для компенсации только нулевого индекса, так как последний колышек мы включаем
            }
        }

        i++; // сдвигаем позиционный счетчик
    }

    Print("Najdłuższy blok trójkowy w pliku: ", INPUT_FILE_NAME); // записываем все в файлик
    Print(bestLength);
    Print("W przedziale: ", startIndex, " → ", endIndex);

    return 0;
}
