#include <iostream>
#include <utility> // for std::swap

template<typename T, size_t len> // using template for type of array and len of array
void SelectionSort(T (&arr)[len], bool changeOrder = false) {
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

int main() {
    int arr[10] = { 10, 2, 4, 1, 7, 3, 2, 5, 0, 14 };
    SelectionSort(arr, true);

    for(auto i : arr) {
        std::cout << i << ' ';
    }

    return 0;
}
