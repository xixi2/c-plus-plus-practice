#include "Sales_data.h"


int main() {
    Sales_data total;
    if (read(cin, total)) {                     // 读入第一笔交易
        Sales_data trans;                       // 保存下一条交易数据的变量
        while (read(cin, trans)) {              // 读入剩余的交易
            if (total.isbn() == trans.isbn()) { // 检查isbn是否相同
                total.combine(trans);           // 若相同更新变量total当前的值，将新输入的trans变量加到total上
            } else {
                print(cout, total) << endl;     // 新输入一本书的信息，则输出上一本书的信息
                total = trans;                  // 处理下一本书
            }
        }
        print(cout, total);                     // 输出最后一条交易
    } else {
        cerr << " No data?" << endl;            // 没有输入任何信息
    }
    return 0;
}