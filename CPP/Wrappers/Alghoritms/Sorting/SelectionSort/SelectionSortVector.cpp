#include <utility> // for std::swap
#include <vector> // provides std::vector (also size_t)
#include <cstdlib> // but I'm including it with different header

void SelectionSort(std::vector<int>& arr, bool changeOrder = false) {
    size_t len = arr.size();
    for (size_t shift = 0; shift + 1 < len; ++shift) { // shift + 1 < len is same as shift < len - 1 but safer for size_t (unsigned int)
        size_t bestIndex = shift;

        // find index of the best element (min or max depending on order)
        for (size_t fastPtr = shift + 1; fastPtr < len; ++fastPtr) { // scan the rest of the array to find the best element
            const bool shouldSwap = changeOrder ? 
                arr[fastPtr] > arr[bestIndex] : 
                arr[fastPtr] < arr[bestIndex]; // choose comparison based on sorting order
                
            if (shouldSwap) { bestIndex = fastPtr; }
        }

        // swap if necessary
        if (bestIndex != shift) { std::swap(arr[bestIndex], arr[shift]); }
    }
}
