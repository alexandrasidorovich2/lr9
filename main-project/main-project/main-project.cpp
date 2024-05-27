#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <Windows.h>


using namespace std;

struct Product {
    std::string name;
    std::string category;
    double price;
    int quantity;
};




void selectionSort(std::vector<Product>& products) {
    for (int i = 0; i < products.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < products.size(); j++) {
            if (products[j].quantity > products[minIndex].quantity) {
                minIndex = j;
            }
        }
        std::swap(products[i], products[minIndex]);
    }
}

void merge(std::vector<Product>& products, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Product> leftArray(n1);
    std::vector<Product> rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = products[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = products[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i].category <= rightArray[j].category) {
            products[k] = leftArray[i];
            i++;
        }
        else {
            products[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        products[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        products[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Product>& products, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(products, left, mid);
        mergeSort(products, mid + 1, right);

        merge(products, left, mid, right);
    }
} 


int main()
{   
    setlocale(LC_ALL, "ru_RU.UTF-8");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Laboratory work #9. GIT";
    cout << "Variant #10. Каталог товаров\n";
    cout << "Author: Сидорович Александра\n";

    std::vector<Product> products;

    std::ifstream file("data.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            Product product;
            iss >> product.price >> product.quantity >> product.category >> product.name;
            products.push_back(product);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file data.txt" << std::endl;
        return 1;
    }


std::cout << "Товары стоимостью больше 100 рублей:" << std::endl;
for (const auto& product : products) {
    if (product.price > 100.0) {
        std::cout << product.name << " (" << product.category << "): " << product.price << " руб., количество: " << product.quantity << std::endl;
    }
}

// Вывод товаров из категории "Промтовары"
std::cout << "\nТовары из категории 'Промтовары':" << std::endl;
for (const auto& product : products) {
    if (product.category == "Промтовары") {
        std::cout << product.name << " (" << product.category << "): " << product.price << " руб., количество: " << product.quantity << std::endl;
    }
}

// Сортировка выбором по убыванию количества товаров на складе
selectionSort(products);

std::cout << "\nОтсортированные товары (сортировка выбором):" << std::endl;
for (const auto& product : products) {
    std::cout << product.name << " (" << product.category << "): " << product.price << " руб., количество: " << product.quantity << std::endl;
}

// Сортировка слиянием по возрастанию категории товара, а в рамках одной категории по убыванию стоимости
mergeSort(products, 0, products.size() - 1);

std::cout << "\nОтсортированные товары (сортировка слиянием):" << std::endl;
for (const auto& product : products) {
    std::cout << product.name << " (" << product.category << "): " << product.price << " руб., количество: " << product.quantity << std::endl;
}
    return 0;
}
