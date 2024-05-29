#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/processing.h"
#include <vector>
#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace unittestproject
{
    //создает объект данной структуры
    Product* build_prod(double price_, int quantity_, std::string category_, std::string name_) {
        Product* prod = new Product;
        prod->price = price_;
        prod->quantity = quantity_;
        prod->category = category_;
        prod->name = name_;
        return prod;
    };
    //очищает вектор объектов структуры
    void delete_prod(vector<Product*>& array) {
        for (auto prod : array) {
            delete prod;
        }
        array.clear();
    };

    TEST_CLASS(unittestproject)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            vector<Product*> products;
            products.push_back(build_prod(2.4, 6, "промтовары", "салфЁтки"));
            products.push_back(build_prod(1.2, 7, "обувь", "сапоги"));
            products.push_back(build_prod(3.7, 3, "промтовары", "мыло"));
            Assert::AreEqual(25.5, process(products, "промтовары"), 0.001);
            delete_prod(products);
        };
        TEST_METHOD(TestMethod2)
        {
            vector<Product*> products;
            products.push_back(build_prod(2.6, 3, "промтовары", "салфЁтки"));
            products.push_back(build_prod(1.2, 12, "обувь", "сапоги"));
            products.push_back(build_prod(4.8, 7, "промтовары", "мыло"));
            Assert::AreEqual(41.4, process(products, "промтовары"), 0.001);
            delete_prod(products);
        };
        TEST_METHOD(TestMethod3)
        {
            vector<Product*> products;
            products.push_back(build_prod(1.2, 5, "промтовары", "салфЁтки"));
            products.push_back(build_prod(0.9, 12, "обувь", "сапоги"));
            products.push_back(build_prod(6.2, 9, "промтовары", "мыло"));
            Assert::AreEqual(61.8, process(products, "промтовары"), 0.001);
            delete_prod(products);
        };
    };
}
