#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    // Открываем файл для записи
    std::ofstream out("C:\\Users\\User\\source\\repos\\STL\\input.txt"); // поток для записи
    if (out.is_open())
    {
        std::vector<int> vec = { 10, 20, 30, 40, 50 };
        // Записываем элементы вектора в файл
        for (int num : vec) {
            out << num << " ";
        }
        out.close();
        std::cout << "File has been written" << std::endl;
    }

    // Организуем чтение из файла целочисленного одномерного вектора
    std::ifstream file("input.txt");
    std::vector<int> vec;
    int num;
    while (file >> num) {
        vec.push_back(num);
    }
    file.close();


    std::vector<int> vec = { 10, 20, 30, 40, 50 };
    int choice;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Reverse vector" << std::endl;
        std::cout << "2. Find and remove minimum element" << std::endl;
        std::cout << "3. Remove even elements" << std::endl;
        std::cout << "4. Sort vector in descending order" << std::endl;
        std::cout << "5. Insert a new element maintaining order" << std::endl;
        std::cout << "6. Find index of an element" << std::endl;
        std::cout << "7. Remove duplicates" << std::endl;
        std::cout << "8. Print vector" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;


       
        switch (choice) {
        case 1:
            std::reverse(vec.begin(), vec.end());
            break;
        case 2:
            vec.erase(std::remove(vec.begin(), vec.end(), *std::min_element(vec.begin(), vec.end())), vec.end());
            break;
        case 3:
            vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());
            break;
        case 4:
            std::sort(vec.begin(), vec.end(), std::greater<int>());
            break;
        case 5:
            int new_element;
            std::cout << "Enter the new element to insert: ";
            std::cin >> new_element;
            vec.insert(std::upper_bound(vec.begin(), vec.end(), new_element, std::greater<int>()), new_element);
            break;
        case 6:
            int element_to_find;
            std::cout << "Enter the element to find: ";
            std::cin >> element_to_find;
            auto it = std::find(vec.begin(), vec.end(), element_to_find);
            if (it != vec.end()) {
                int index = std::distance(vec.begin(), it);
                std::cout << "Index of " << element_to_find << " is: " << index << std::endl;
            }
            else {
                std::cout << element_to_find << " not found in the vector." << std::endl;
            }
            break;
        case 7:
            vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
            break;
        
        case 0:
            std::cout << "Exiting the program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}