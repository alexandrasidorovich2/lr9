#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/processing.h"
#include <vector>
#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace unittestproject
{
    //������� ������ ������ ���������
    Product* build_prod(double price_, int quantity_, std::string category_, std::string name_) {
        Product* prod = new Product;
        prod->price = price_;
        prod->quantity = quantity_;
        prod->category = category_;
        prod->name = name_;
        return prod;
    };
    //������� ������ �������� ���������
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
            products.push_back(build_prod(2.4, 6, "����������", "��������"));
            products.push_back(build_prod(1.2, 7, "�����", "������"));
            products.push_back(build_prod(3.7, 3, "����������", "����"));
            Assert::AreEqual(25.5, process(products, "����������"), 0.001);
            delete_prod(products);
        };
        TEST_METHOD(TestMethod2)
        {
            vector<Product*> products;
            products.push_back(build_prod(2.6, 3, "����������", "��������"));
            products.push_back(build_prod(1.2, 12, "�����", "������"));
            products.push_back(build_prod(4.8, 7, "����������", "����"));
            Assert::AreEqual(41.4, process(products, "����������"), 0.001);
            delete_prod(products);
        };
        TEST_METHOD(TestMethod3)
        {
            vector<Product*> products;
            products.push_back(build_prod(1.2, 5, "����������", "��������"));
            products.push_back(build_prod(0.9, 12, "�����", "������"));
            products.push_back(build_prod(6.2, 9, "����������", "����"));
            Assert::AreEqual(61.8, process(products, "����������"), 0.001);
            delete_prod(products);
        };
    };
}
