#pragma once
#include <vector>
#include <cstring>
using namespace std;
struct Product {
    double price;
    int quantity;
    string category;
    string name;
};
double process(vector<Product*> products, const string& category);