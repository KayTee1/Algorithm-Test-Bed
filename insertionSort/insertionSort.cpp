#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <chrono>

std::chrono::steady_clock::time_point start_timer()
{
    return std::chrono::steady_clock::now();
}

double stop_timer(std::chrono::steady_clock::time_point start)
{
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count();
}

std::vector<int> generateList(int n)
{
    std::vector<int> list(n);
    int range = n * 10000;
    for (int i = 0; i < n; i++)
    {
        list[i] = rand() % range;
    }
    return list;
}

void printVec(const std::vector<int> &vec, int limit)
{
    for (int i = 0; i < limit; i++)
    {
        std::cout << vec[i] << std::endl;
    }
}

void insertionSort(std::vector<int> &list)
{
    int n = list.size();
    for (int i = 1; i < n; i++)
    {
        int key = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > key)
        {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

int main()
{
    using std::cout, std::endl, std::cin;

    srand(time(nullptr));

    std::chrono::steady_clock::time_point start_time = start_timer();

    int dataSize{}, start{};
    cout << "Enter data size: \n";
    cin >> dataSize;

    std::vector<int> generatedList = generateList(dataSize);

    int limit = (dataSize > 20) ? 20 : dataSize;

    cout << "\nList before sort: \n";
    printVec(generatedList, limit);

    double finishedTime = stop_timer(start_time);

    cout << "List after sort: \n";
    insertionSort(generatedList);
    printVec(generatedList, limit);

    cout << "\nElapsed time: " << std::fixed << std::setprecision(6) << finishedTime << " seconds" << endl;

    return 0;
}
