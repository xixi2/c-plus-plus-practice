//
// Created by xixi2 on 19-5-24.
//
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>

using namespace std;

#ifndef INC_1_SALES_DATA_H
#define INC_1_SALES_DATA_H

class Sales_data {
public:
    // 非成员接口函数的友元声明
    friend Sales_data add(const Sales_data &, const Sales_data &);

    friend ostream &print(ostream &, const Sales_data &);

    friend istream &read(istream &, Sales_data &);

    // 不接受任何实参的默认构造函数
    Sales_data() = default;

    // units_sold和revenue以与默认构造函数相同的方式隐式初始化：这里采用类内初始值初始化
    Sales_data(const string &s) : bookNo(s) {}

    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}

    Sales_data(istream &is);

    string isbn() const {
        return bookNo;
    }

    Sales_data &combine(const Sales_data &);

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    double avg_price() const;

};

// 友元函数在类的外部声明
Sales_data add(const Sales_data &, const Sales_data &);

ostream &print(ostream &, const Sales_data &);

istream &read(istream &, Sales_data &);

#endif //INC_1_SALES_DATA_H
