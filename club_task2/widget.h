#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QLayout>
#include <QKeyEvent>
#include <QDateTime>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QTextLayout>
#include <QFont>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0,QString myname = "Myname");
    void set_Widget(Widget *get);

    ~Widget();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;
    Ui::Widget *ui_another;
    QString name,time;
    QDateTime *t;
    QLabel *label,*label_text,*statusLabel;
    QImage *image;
    QTextLayout *show_name;
    QFont *font;

private slots:
    void send_to();
    void on_clearBtn_clicked();

signals:
    void getdata(QString);
};



#endif // WIDGET_H
