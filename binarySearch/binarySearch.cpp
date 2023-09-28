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
    using std::cout, std::endl;

    cout << endl
         << name << endl;
    for (int i = 0; i < name.length(); i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "Status: " << results << endl;
    cout << "Elapsed per search: " << std::fixed << std::setprecision(6) << elapsedTime << " seconds" << endl;
    cout << "Comparisons per search: " << comparisons << endl;
    cout << "Searches: " << searchCount << endl;
    cout << endl;
}

int main()
{
    using std::cout, std::endl, std::cin;

    srand(time(nullptr));

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
        cout << "Key value: " << key << endl;
    }
    else
    {
        cout << "Enter key value: \n";
        cin >> key;
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
        cout << "Binary Search\n";
        cout << "Time elapsed: " << std::fixed << std::setprecision(6) << search_elapsed_seconds << " seconds\n";
        cout << "Comparisons count: " << count << endl;
    }
    else
    {
        cout << "Error\n";
    }

    return 0;
}
