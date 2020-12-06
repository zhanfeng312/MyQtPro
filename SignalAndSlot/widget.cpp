#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->mTeacher = new Teacher(this);

    //创建一个学生对象
    this->mStudent = new Student(this);

    //connect(teacher, &Teacher::hungry, student, &Student::treat);

    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlot)(QString) = &Student::treat;
    connect(mTeacher, teacherSignal, mStudent, studentSlot);
    classIsOver();

    //点击一个按钮 触发 下课
    QPushButton *btn = new QPushButton("下课", this);
    //重置窗口大小
    this->resize(600, 400);
    //connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);

    //无参信号和槽函数
    void(Teacher:: *teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: *studentSlot2)(void) = &Student::treat;
    connect(mTeacher, teacherSignal2, mStudent, studentSlot2);

    //信号连接信号
    connect(btn, &QPushButton::clicked, mTeacher, teacherSignal2);
}

void Widget::classIsOver()
{
    //下课函数, 调用后 触发老师饿了的信号
    //emit teacher->hungry();
    emit mTeacher->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    delete ui;
}

