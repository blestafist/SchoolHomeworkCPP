#include <utility>
// ! QuickSort for Legacy Arrays (C)

int PartitionQuickSort(int (&arr)[], int first, int last) {
    int pivot = arr[last];
    int fence = first - 1;

    for (int i = first; i < last; i++) {
        if (arr[i] <= pivot) {
            ++fence;
            std::swap(arr[fence], arr[i]);
        }
    }

    ++fence;

    std::swap(arr[fence], arr[last]);
    return fence;
}