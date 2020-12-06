#include "mywidget.h"
#include <QApplication> //包含一个应用程序类的头文件,路径在哪引用？

int main(int argc, char *argv[])
{
    //a应用程序对象, 在Qt中, 应用程序对象有且仅有一个
    QApplication a(argc, argv);
    //窗口对象 MyWidget 父类---> QWidget
    MyWidget w;
    //默认不会显示,必须要调用show方法显示窗口
    w.show();
    return a.exec();
}
