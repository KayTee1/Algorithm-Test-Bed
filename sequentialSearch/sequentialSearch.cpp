#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

void generateList(int n, std::vector<int> &list)
{
    list.clear();
    for (int i = 1; i <= n; i++)
    {
        list.push_back(i);
    }
}

bool searchList(const std::vector<int> &list, int key, int &pos)
{
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == key)
        {
            pos = i;
            return true;
        }
    }

    return false;
}

int main()
{
    std::srand(std::time(nullptr));

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
        std::cout << "Key: " << key << std::endl;
    }
    else
    {
        std::cout << "Enter key value: \n";
        std::cin >> key;
    }

    std::vector<int> generatedList;
    generateList(size, generatedList);

    int position{};
    std::chrono::steady_clock::time_point startSearch = std::chrono::steady_clock::now();
    bool result = searchList(generatedList, key, position);
    std::chrono::steady_clock::time_point endSearch = std::chrono::steady_clock::now();

    std::chrono::duration<double> search_elapsed_seconds = endSearch - startSearch;

    std::cout << "Key found: " << result << std::endl;

    if (result)
    {
        std::cout << "Key found at position: " << position << std::endl;
    }
    else
    {
        std::cout << "Key was not found" << std::endl;
    }

    if (search_elapsed_seconds.count() < 1.0)
    {
        double elapsed_milliseconds = search_elapsed_seconds.count() * 1000;
        std::cout << "Search time: " << elapsed_milliseconds << " milliseconds" << std::endl;
    }
    else
    {
        std::cout << "Search time: " << search_elapsed_seconds.count() << " seconds" << std::endl;
    }

    return 0;
}
