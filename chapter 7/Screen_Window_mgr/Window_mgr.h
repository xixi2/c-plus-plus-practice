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

private:
    // 这个Window_mgr追踪的Screen，默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
    vector <Screen> screens{Screen(24, 80, ' ')};

};

void Window_mgr::clear(Window_mgr::ScreenIndex i) {
    // s是Screen的引用，指向我们想清空的那个屏幕
    Screen &s = screens[i];
//    cout << "s.height:" << (s.height) << " s.width:" << (s.width) << endl;
    //将那个选定的screen置为空白
    s.contents = string(s.height * s.width, 'B');
}

Screen &Window_mgr::get(Window_mgr::ScreenIndex i) {
//    cout << "&screen[" << i << "]:" << &screens[i] << endl;
    return screens[i];
}


#endif //INC_1_WINDOW_MGR_H
