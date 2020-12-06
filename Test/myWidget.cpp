#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>

//快捷键
//注释: ctrl + /
//运行: ctrl + r
//编译: ctrl + b
//字体缩放: ctrl + 鼠标滚轮
//查找: ctrl + f
//帮助文档: F1
//自动对齐: ctrl + i

MyWidget::MyWidget(QWidget *parent) : QWidget(parent) //成员初始化列表
{
    QPushButton *btn1 = new QPushButton;
    //btn1->show();//show以顶层方式弹出窗口控件

    btn1->setParent(this);//设置父亲
    //设置按钮的显示文本
    btn1->setText("第一个按钮");

    QPushButton *btn2 = new QPushButton("第二个按钮", this);
    //移动位置
    btn2->move(100, 0);
    //重置窗口大小
    resize(400, 400);
    //设置窗口标题
    setWindowTitle("我的第一个窗口");
    //设置固定窗口大小
    setFixedSize(400, 400);

    MyPushButton *myBtn = new MyPushButton;
    myBtn->setText("我自己的按钮");
    myBtn->setParent(this);
    myBtn->move(200, 0);

    connect(myBtn, &MyPushButton::clicked, this, &MyWidget::close);
}

MyWidget::~MyWidget()
{
    qDebug() << "MyWidget析构函数";
}
