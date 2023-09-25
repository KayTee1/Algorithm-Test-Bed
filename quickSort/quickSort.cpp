#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <chrono>

int partition(std::vector<int>& list, int low, int high) {
    int pivot = list[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (list[j] < pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }

    std::swap(list[i + 1], list[high]);
    return i + 1;
}

void quickSort(std::vector<int>& list, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(list, low, high);
        quickSort(list, low, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, high);
    }
}

std::vector<int> generateList(int n) {
    std::vector<int> list(n);
    int range = n * 10000;
    for (int i = 0; i < n; i++) {
        list[i] = rand() % range;
    }
    return list;
}

void printVec(const std::vector<int>& vec, int dataSize) {
    for (int i = 0; i < dataSize; i++) {
        std::cout << vec[i] << std::endl;
    }
}

int main() {
    srand(time(nullptr));

    int dataSize{}, start{};
    std::cout << "Enter data size: \n";
    std::cin >> dataSize;

    std::vector<int> generatedList = generateList(dataSize);

    int limit = (dataSize > 20) ? 20 : dataSize;

    std::cout << "\nList before sort: \n";
    printVec(generatedList, dataSize);

    auto start_time = std::chrono::steady_clock::now();

    quickSort(generatedList, 0, dataSize - 1);

    auto end_time = std::chrono::steady_clock::now();
    double elapsed_time = std::chrono::duration<double>(end_time - start_time).count();

    std::cout << "List after sort: \n";
    printVec(generatedList, dataSize);

    std::cout << "\nElapsed time: " << std::fixed << std::setprecision(6) << elapsed_time << " seconds" << std::endl;

    return 0;
}
