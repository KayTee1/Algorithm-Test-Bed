#include <iostream>
#include <cstdlib>

int main(){

    bool isActive{true};
    while (isActive == true){
        int option{};

        std::cout << "\nWelcome to test bed for search and sorting algorithmns\n";
        std::cout << "\n1. Run Sequential_search\n";
        std::cout << "2. Run Binary search\n";
        std::cout << "3. Run Insertion sort\n";
        std::cout << "4. Run Quicksort\n";
        std::cout << "5. Quit the program\n";

        std::cin >> option;

        switch(option){
            case 1:{
                if (system("./sequentialSearch/sequentialSearch") != 0) {
                    std::cerr << "Error executing sequentialSearch" << std::endl;
                }
                break;
            }
            case 2:{
                if (system("./binarySearch/binarySearch") != 0) {
                    std::cerr << "Error executing binarySearch" << std::endl;
                }
                break;
            }
            case 3:{
                if (system("./inserionSort/inserionSort") != 0) {
                    std::cerr << "Error executing inserionSort" << std::endl;
                }
                break;
            }
            case 4:{
                if (system("./quickSort/quickSort") != 0) {
                    std::cerr << "Error executing quickSort" << std::endl;
                }
                break;
            }
            case 5:{
                isActive = false;
                break;
            }
        }

    }

    return 0;
}