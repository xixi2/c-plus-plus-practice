#include "Screen.h"
#include "Window_mgr.h"

int main() {
    Window_mgr wm;
    Screen &screen = wm.get(0); //此处若不加&引用符号，则screen是wm.screens[0]的副本;加上引用符号，screen是screens[0]的引用
    screen.set('C');
    cout << "screen.get():" << screen.get() << " wm.get(0).get(): " << wm.get(0).get() << endl;
    wm.get(0).set('A');
    cout << "screen.get():" << screen.get() << "wm.get(0).get(): " << wm.get(0).get() << endl;
    wm.clear(0);
    cout << "screen.get(): " << screen.get() << " wm.get(0).get(): " << wm.get(0).get() << endl;

    return 0;
}