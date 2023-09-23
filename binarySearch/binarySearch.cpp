#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>

void generateList(int n, std::vector<int> &list)
{
    list.clear();
    for (int i = 1; i <= n * 2 - 1; i += 2)
    {
        list.push_back(i);
    }
}

bool binarySearch(const std::vector<int> &list, int key, int &count)
{
    int left = 0, right = list.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (list[mid] == key)
        {
            return true;
        }
        else if (list[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        count++;
    }
    return false;
}

void printResults(std::string name, bool results, double elapsedTime, int comparisons, int searchCount)
{
    std::cout << std::endl
              << name << std::endl;
    for (int i = 0; i < name.length(); i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;

    std::cout << "Status: " << results << std::endl;
    std::cout << "Elapsed per search: " << std::fixed << std::setprecision(6) << elapsedTime << " seconds" << std::endl;
    std::cout << "Comparisons per search: " << comparisons << std::endl;
    std::cout << "Searches: " << searchCount << std::endl;
    std::cout << std::endl;
}

int main()
{
    srand(time(nullptr));

    int size{};
    std::cout << "Enter data size: \n";
    std::cin >> size;

    char option;
    std::cout << "Randomize key value? (y/n)\n";
    std::cin >> option;

    int key{};

    if (option == 'y')
    {
        key = rand() % size + 1;
        std::cout << "Key value: " << key << std::endl;
    }
    else
    {
        std::cout << "Enter key value: \n";
        std::cin >> key;
    }

    std::vector<int> generatedList;
    generateList(size, generatedList);

    int count{};

    auto start = std::chrono::steady_clock::now();
    bool resultBinary = binarySearch(generatedList, key, count);
    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double> search_elapsed_seconds = end - start;

    if (resultBinary)
    {
        std::cout << "Binary Search\n";
        std::cout << "Time elapsed: " << std::fixed << std::setprecision(6) << search_elapsed_seconds << " seconds\n";
        std::cout << "Comparisons count: " << count << std::endl;
    }
    else{
        std::cout << "Error\n";
    }

    return 0;
}
