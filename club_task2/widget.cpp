#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent,QString myname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    name = myname;
    ui->setupUi(this);

    setWindowTitle(name);



    image = new QImage("E:/Qt_code/club_task2/images/"+name+".jpg");
    font = new QFont(name,24,-1,true);


    *image=image->scaled(100,100);
    label=new QLabel(this);
    label_text = new QLabel(this);

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(label,0,0,1,1);
    layout->addWidget(label_text,0,1,1,1);

    label->setPixmap(QPixmap::fromImage(*image));
    label->show();

    label_text->setText("<span style = \"font-size:50px;color:blue;font-weight:1300;\">"
                        +name+" :"+"</span>");
    label_text->show();

    layout->addWidget(ui->textBrowser,1,0,1,5);
    layout->addWidget(ui->textEdit,6,0,2,5);
    layout->addWidget(ui->clearBtn,8,3,1,1);
    layout->addWidget(ui->sendBtn,8,4,1,1);
    this->setLayout(layout);

    ui->textEdit->setPlaceholderText("单人聊天使用指南：按 alt+enter 可快捷发送。还有，这后面还有一个页面！");

    connect(ui->clearBtn,SIGNAL(clicked(bool)),this,SLOT(on_clearBtn_clicked()));
    connect(ui->sendBtn,SIGNAL(clicked(bool)),this,SLOT(send_to()));
    connect(this,SIGNAL(getdata(QString)),ui->textBrowser,SLOT(append(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::set_Widget(Widget *get)
{
    ui_another = get->ui;
    connect(this,SIGNAL(getdata(QString)),ui_another->textBrowser,SLOT(append(QString)));
}



void Widget::on_clearBtn_clicked()
{
    ui->textBrowser->clear();
    ui->textEdit->setFocus();
}


void Widget::send_to()
{
    t=new QDateTime;
    time=t->currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");


    emit getdata("<span style= \"font-size:24px;color:red;\">"
                 +name+"</span>"
                 +"<span style = \"font-size:18px;color:black;font-family:verdana;\">"+"  "+time+"</span>"
                 +"<br/>"
                 +"<span style = \"font-size:18px;font-family:SimHei;color:black;\">"
                 +ui->textEdit->toPlainText()+"</span><br/>"
                 );

    ui->textEdit->clear();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Return||event->key()==Qt::Key_Enter)
        send_to();
}
