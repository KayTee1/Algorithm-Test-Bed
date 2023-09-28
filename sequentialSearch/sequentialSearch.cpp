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
    using std::cout, std::endl, std::cin;

    std::srand(std::time(nullptr));

    int size{};
    cout << "Enter data size: \n";
    cin >> size;

    char option;
    cout << "Randomize key value? (y/n)\n";
    cin >> option;

    int key{};

    if (option == 'y')
    {
        key = rand() % size + 1;
        cout << "Key: " << key << endl;
    }
    else
    {
        cout << "Enter key value: \n";
        cin >> key;
    }

    std::vector<int> generatedList;
    generateList(size, generatedList);

    int position{};
    std::chrono::steady_clock::time_point startSearch = std::chrono::steady_clock::now();
    bool result = searchList(generatedList, key, position);
    std::chrono::steady_clock::time_point endSearch = std::chrono::steady_clock::now();

    std::chrono::duration<double> search_elapsed_seconds = endSearch - startSearch;

    cout << "Key found: " << result << endl;

    if (result)
    {
        cout << "Key found at position: " << position << endl;
    }
    else
    {
        cout << "Key was not found" << endl;
    }

    if (search_elapsed_seconds.count() < 1.0)
    {
        double elapsed_milliseconds = search_elapsed_seconds.count() * 1000;
        cout << "Search time: " << elapsed_milliseconds << " milliseconds" << endl;
    }
    else
    {
        cout << "Search time: " << search_elapsed_seconds.count() << " seconds" << endl;
    }

    return 0;
}
