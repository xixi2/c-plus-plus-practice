//
// Created by xixi2 on 19-5-25.
//

#ifndef INC_1_WINDOW_MGR_H
#define INC_1_WINDOW_MGR_H

#include <vector>
#include "Screen.h"

class Window_mgr {
public:
    // 窗口中每个屏幕的编号
    using ScreenIndex = vector<Screen>::size_type;

    // 按照编号将指定的Screen重置为空白
    void clear(ScreenIndex);

    Screen &get(ScreenIndex);

    // 向窗口添加一个Screen，返回它的编号
    ScreenIndex addScreen(const Screen &);

private:
    // 这个Window_mgr追踪的Screen，默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
    vector <Screen> screens{Screen(24, 80, ' ')};

};

// 这里的ScreenIndex之前不必再次说明ScreenIndex是在Window_mgr的作用域内了；
// 这是因为，函数名前面的类名已经说明了接下来的参数列表和函数体是在类的作用域内了
void Window_mgr::clear(Window_mgr::ScreenIndex i) {
    // s是Screen的引用，指向我们想清空的那个屏幕
    Screen &s = screens[i];
    //将那个选定的screen置为空白,这里为了测试时看得明白，将空白字符改为字符B
    s.contents = string(s.height * s.width, 'B');
}

Screen &Window_mgr::get(Window_mgr::ScreenIndex i) {
    return screens[i];
}


/* 向窗口添加一个Screen，返回它的编号
 * 函数的返回类型在类的作用域之外，返回类型中用到类的作用域之内的变量必须指明作用域
 * */
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}


#endif //INC_1_WINDOW_MGR_H
