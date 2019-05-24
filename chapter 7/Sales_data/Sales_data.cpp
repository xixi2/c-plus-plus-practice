//
// Created by xixi2 on 19-5-24.
//
#include "Sales_data.h"

Sales_data::Sales_data(istream &is) {
    read(is, *this);
}

double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;  // 返回this指针指向的对象的引用
}

istream &read(istream &is, Sales_data &item) {
    // 从给定的流中讲数据督导给定的对象里
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item) {
    //print负责讲给定对象的内容打印到给定的流中
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os; // 返回了对ostream对象的引用，可以作为左侧运算对象
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs); // 为什么这里不用接收返回的对象引用
    return sum;
}