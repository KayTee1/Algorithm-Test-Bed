#include <iostream>
#include <cstdlib>

int main()
{
    using std::cout, std::cin, std::cerr, std::endl;

    bool isActive{true};
    while (isActive == true)
    {
        int option{};

        cout << "\nWelcome to test bed for search and sorting algorithmns\n";
        cout << "\n1. Run Sequential_search\n";
        cout << "2. Run Binary search\n";
        cout << "3. Run Insertion sort\n";
        cout << "4. Run Quicksort\n";
        cout << "5. Quit the program\n";

        cin >> option;

        switch (option)
        {
        case 1:
        {
            if (system("./sequentialSearch/sequentialSearch") != 0)
            {
                cerr << "Error executing sequentialSearch" << endl;
            }
            break;
        }
        case 2:
        {
            if (system("./binarySearch/binarySearch") != 0)
            {
                cerr << "Error executing binarySearch" << endl;
            }
            break;
        }
        case 3:
        {
            if (system("./inserionSort/inserionSort") != 0)
            {
                cerr << "Error executing inserionSort" << endl;
            }
            break;
        }
        case 4:
        {
            if (system("./quickSort/quickSort") != 0)
            {
                cerr << "Error executing quickSort" << endl;
            }
            break;
        }
        case 5:
        {
            isActive = false;
            break;
        }
        }
    }

    return 0;
}