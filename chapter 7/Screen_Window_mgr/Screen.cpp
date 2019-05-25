//
// Created by xixi2 on 19-5-25.
//

#include "Screen.h"

Screen &Screen::move(Screen::pos r, Screen::pos c) {
    pos row = r * width;        // 计算行的位置
    cursor = row + c;           // 在行内将光标移动到指定的列
    return *this;               // 以左值的形式返回对象
}

char Screen::get(Screen::pos r, Screen::pos c) const {
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_members() const {
    ++access_ctr;               // 保存一个计数值，用于记录成员函数被调用的次数
}

Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set(Screen::pos r, Screen::pos col, char ch) {
//    cout<<"contents.size():"<<contents.size()<<endl;
//    cout<< "r * width + col: "<<(r * width + col)<<endl;
    contents[r * width + col] = ch;     // 设置给定位置的新值
    return *this;
}