#include <iostream>
#include <vector>

void BestThreeBlock (const std::vector<int>& vec, int& startIndex, int& endIndex) { // startIndex and endIndex are initialised to zero
    int moduleStarts[3] = { -1, -2, -2 }; // starts for 0, 1, 2 modules. 
    // -1 means we count from the start, because if all the sum from the start devides by 3 we anyways'll not found better solution

    int localMod = 0, bestLength = -1;

    for (int i = 0; i < vec.size(); i++) {
        localMod = (localMod + vec[i]) % 3; // использование свойств модулей

        if (moduleStarts[localMod] == -2) { moduleStarts[localMod] = i; } // ставим колышек что видели этот остаток
        else { // если уже видели такой остаток то счиатем и сравниваем длинну
            int len = i - moduleStarts[localMod];
            if (len > bestLength) {
                bestLength = len;

                // writing to global space (to return two values without struct)
                startIndex = moduleStarts[localMod] + 1; // add 1 to get "human index" (starting from 1)
                endIndex = i + 1;
            }
        }
    }
    
} 
