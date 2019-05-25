//
// Created by xixi2 on 19-5-25.
//

#ifndef INC_1_SCREEN_H
#define INC_1_SCREEN_H

#include <iostream>

using namespace std;


class Screen {
public:
    //　用来定义类型的成员必须先定义再使用，因此，类型成员通常出现在类开始的地方
    typedef string::size_type pos;

    // 声明友元类
    friend class Window_mgr;

    Screen() = default;

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    // 读取光标处的字符
    char get() const { return contents[cursor]; }  //隐式内联

    // 返回位置(r, c)处的字符
    char get(pos r, pos c) const;         // 显式内联

    Screen &move(pos r, pos c);     // 将光标移动到指定位置处


    void some_members() const;

    Screen &set(char c);            // 设置光标处的字符

    Screen &set(pos r, pos col, char ch);    // 设置位置(r, col)处的字符

    // 重载display函数，使其能够支持常量和非常量
    /* 非常量版本的display，返回的是指向非常量对象的引用；
     * 可以传入非常量实参和常量实参，但是对于常量实参的函数来说，下面的常量版本是最优匹配
     * */
    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    }

    // 常量版本的display，返回的是指向常量对象的常量引用
    /* 形参列表后的const表示的是this指针指向的对象是个常量
       而返回类型中的const表示的是返回的引用是常量引用，即对常量的引用;
       可以返回一个对非常量的引用，这里因为非常量可以转化为常量，但是不能返回的引用改变对象

       一个const成员函数如果以引用形式返回*this，则它的返回类型是常量引用
     */
    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;                 //　光标的位置
    pos height = 0, width = 0;      // 屏幕的高度和宽度
    string contents;                // 屏幕中的内容
    mutable size_t access_ctr;      // mutable可变数据成员，即使是在一个const对象内也能被修改

    /* 指向常量对象的this指针
     * 形参是常量实参，当非常量实参调用时，将非常量转换成常量
     * */
    void do_display(ostream &os) const {
        os << contents;
    }
};

#endif //INC_1_SCREEN_H
