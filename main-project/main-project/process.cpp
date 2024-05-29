#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include "processing.h"
using namespace std;
// Функция для нахождения общей стоимости всех товаров в указанной категории
double process(vector<Product*> products, const string& category) {
    double totalCost = 0.0;
    for (const auto& product : products) {
        if (product->category == category) {
            totalCost += product->price * product->quantity;
        }
    }
    return totalCost;
}
