#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT //宏, 允许类中使用信号和槽的机制

public:
    MyWidget(QWidget *parent = nullptr); //构造函数
    ~MyWidget(); //析构函数
};
#endif // MYWIDGET_H
