#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include "processing.h"
using namespace std;
// ������� ��� ���������� ����� ��������� ���� ������� � ��������� ���������
double process(vector<Product*> products, const string& category) {
    double totalCost = 0.0;
    for (const auto& product : products) {
        if (product->category == category) {
            totalCost += product->price * product->quantity;
        }
    }
    return totalCost;
}
